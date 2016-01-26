#include "Globals.h"
#include "Board.h"

Board *board;

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RGB_BACKGROUND,1.0f);
}


void drawBitmapText(std::string string,float x,float y,float z)
{
    glRasterPos3f(x, y,z);

    for (int i=0; i<(signed) string.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}

void drawScene() {
    // clear the matrix and
    // load the identity matrix.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(board->x, board->y, -2*(8.0f));
    glScalef( board->zoom/4,board->zoom/4,1.0f );
    board->makeBoard();
    std::string level = "Level : " + std::to_string(board->level);
    drawBitmapText(level, -BOX_SIZE -2 , BOX_SIZE/2, -16.0f);

    // performs a flush and loads
    // the buffer on the screen
    glutSwapBuffers();
}

void keyPressHandler(unsigned char key, int x, int y){
    // called whenever keys are pressed, with x and y as mouse pointer location.
    // key = normal key, use switch case.
    //std::cout <<"keyPressHandler " << key << " " << x << " " << y << std::endl;
    switch (key){
        case ' ':
            board->fireBird();
            break;

        case 'a':
            board->cannon.changeAngle(1.0f);
            if (board->birds.size()>0 and !board->birds[0].moving) board->birds[0].setBird(board->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);
            break;

        case 'b':
            board->cannon.changeAngle(-1.0f);
            if (board->birds.size()>0 and !board->birds[0].moving) board->birds[0].setBird(board->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);
            break;

        case 's':
            board->powerMeter.decreaseLevel();
            break;

        case 'f':
            board->powerMeter.increaseLevel();
            break;

        case 'k':
            board->killBird();
            break;

        case '8':
            board->y += 1;
            break;

        case '2':
            board->y -= 1;
            break;

        case '4':
            board->x -= 1;
            break;

        case '6':
            board->x += 1;
            break;

        case 'Q':
        case 'q':
            exit(0);

        default:
            break;
    }

}

void resizeHandler(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void specialKeyPressHandler(int key, int x, int y){
    // called whenever special keys are pressed, with x and y as mouse pointer location.
    // key = (100 right) (101 up) (102 left) (103 down) (i Fi)
    switch (key){
        case 100:
            board->x -= 1;
            break;

        case 102:
            board->x += 1;
            break;

        case 101:
            board->zoom += 1;
                break;

        case 103:
            board->zoom -= 1;
            break;

        default:
            break;
    }
    //std::cout<<"specialKeyPressHandler "<<key<<" "<<x<<" "<<y<<std::endl;
}

void mouseHandler(int button, int state, int x, int y){
    // called whenever mouse is clicked, with x and y as mouse pointer location.
    // button = (0 lmb) (1 mmb) (2 rmb) (3 scroll_up) (4 scroll_down)
    // state = 0 if up, 1 if down
    if (button == 0 and state == 1){
        board->fireBird();
    }
    if (button == 3 and state == 1){
        board->zoom += 1;
    }
    if (button == 4 and state == 1){
        board->zoom -= 1;
    }
    //std::cout<<"mouseHandler "<<button<<" "<<state<<" "<<x<<" "<<y<<std::endl;
}

void dragHandler(int x, int y){
    // called whenever mouse is being dragged each time it changes a pixel, with x and y as mouse pointer location.
    std::cout<<"dragHandler "<<x<<" "<<y<<std::endl;
}

void pointerHandler(int x, int y){
    double X = x;
    double Y = y;
    double Z = 0;
    double cannX, cannY, cannZ;

    double modelMatrix[16];
    double projMatrix[16];
    GLint viewport[4];

    glGetIntegerv( GL_VIEWPORT, viewport );
    glGetDoublev( GL_MODELVIEW_MATRIX, modelMatrix );
    glGetDoublev( GL_PROJECTION_MATRIX, projMatrix );


    gluUnProject(-BOX_SIZE/2-2, -BOX_SIZE/2-1, 0, modelMatrix, projMatrix, viewport, &cannX, &cannY, &cannZ);
    gluUnProject(x,y,0,modelMatrix, projMatrix, viewport, &X, &Y, &Z);
    //double xx = X-cannX, yy = Y -cannY;
    //std::cout<<"pointerHandler "<< X << " "  << Y << " " << cannX << " " << cannY << std::endl;
    //std::cout<<"Distance" << xx << " " << yy << " " << xx/yy << " " << tan(DEG2RAD(xx/yy)) << std::endl;
    //board->cannon.changeAngleAbs((float) tan(DEG2RAD( X/Y)));
}

void updateScene(int value) {
    // The frame divisions is actually a
    // crude hack to make the collisions more
    // precise as we update the positions slowly
    // and hence high velocities don't cause
    // us to go over each other.
    //std::cout<<value<<std::endl;

    for(int i = 0; i < FRAME_DIVISIONS; i++) {
        board->handleCollision();
        //board->updatePositions();
    }
    // We call the update every millisecond.
    //board->countDownTimer();
    glutTimerFunc(1, updateScene, 0);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    board = new Board();

    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);

    int windowWidth = w;
    int windowHeight = h;
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Angry Birds v1.0");
    initRendering();

    // Callbacks :)
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);

    glutKeyboardFunc(keyPressHandler);
    glutSpecialFunc(specialKeyPressHandler);

    glutMouseFunc(mouseHandler);
    glutMotionFunc(dragHandler);
    glutPassiveMotionFunc(pointerHandler);

    glutReshapeFunc(resizeHandler);

    glutTimerFunc(1, updateScene, 0);

    glutMainLoop();

    delete board;

    return 0;
}

#include "Globals.h"
#include "Board.h"

Board *board;

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RGB_BACKGROUND,1.0f);
}

void drawScene() {
    // clear the matrix and
    // load the identity matrix.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef( board->zoom/4,board->zoom/4,1.0f );
    board->makeBoard();

    // performs a flush and loads
    // the buffer on the screen
    glutSwapBuffers();
}

void keyPressHandler(unsigned char key, int x, int y){
    // called whenever keys are pressed, with x and y as mouse pointer location.
    // key = normal key, use switch case.
    switch (key){
        case ' ':
            if (board->in_progress) break;

            if (board->birds.size()>0) {
                board->birds[0].setBird(board->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);
                board->birds[0].moving = true;
                board->in_progress = true;

                board->birds[0].velX *= board->powerMeter.currLevel;
                board->birds[0].velY *= board->powerMeter.currLevel;
            }

            break;

        case 'a':
            board->cannon.changeAngle(1.0f);
            if (board->birds.size()>0) board->birds[0].setBird(board->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);
            break;

        case 'b':
            board->cannon.changeAngle(-1.0f);
            if (board->birds.size()>0) board->birds[0].setBird(board->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);
            break;

        case 's':
            board->powerMeter.decreaseLevel();
            break;

        case 'f':
            board->powerMeter.increaseLevel();
            break;

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
            break;

        case 102:
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
    std::cout<<"mouseHandler "<<button<<" "<<state<<" "<<x<<" "<<y<<std::endl;
}

void dragHandler(int x, int y){
    // called whenever mouse is being dragged each time it changes a pixel, with x and y as mouse pointer location.
    std::cout<<"dragHandler "<<x<<" "<<y<<std::endl;
}

void updateScene(int value) {
    // The frame divisions is actually a
    // crude hack to make the collisions more
    // precise as we update the positions slowly
    // and hence high velocities don't cause
    // us to go over each other.
    //std::cout<<value<<std::endl;

    for(int i = 0; i < FRAME_DIVISIONS; i++) {
        //board->handleCollision();
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

    glutReshapeFunc(resizeHandler);

    glutTimerFunc(1, updateScene, 0);

    glutMainLoop();

    delete board;

    return 0;
}

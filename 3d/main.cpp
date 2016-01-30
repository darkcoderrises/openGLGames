#include "Globals.h"
#include "Board.h"

Board *board;

void initRendering(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RGB_BACKGROUND, 1.0f);
}

void drawScene() {
    // clear the matrix and
    // load the identity matrix.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(board->x, board->y, -16.0f);
    board->drawBoard();

    // performs a flush and loads
    // the buffer on the screen
    glutSwapBuffers();
}


void resizeHandler(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyPressHandler(unsigned char key, int x, int y){
    switch (key){
        case 'c':
        std::cout<<"HI"<<std::endl;
            gluLookAt(-5,-5,-5,
            0,0,-10.f,
            0,1,0
            );
            break;
        default:
            break;
    }
}

void specialKeyPressHandler(int key, int x, int y) {
    switch (key){
        case 100:
            board->x -= 1;
            break;
        case 101:
            board->y += 1;
            break;
        case 102:
            board->x += 1;
            break;
        case 103:
            board->y -= 1;
            break;
        default:
            break;
    }
}

void mouseHandler(int button, int state, int x, int y) {

}

void dragHandler(int x, int y){

}

void pointerHandler(int x, int y){

}

void updateScene(int value){

}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);

    board = new Board();

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

    return 0;
}

#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400, 400);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Minimal Window");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
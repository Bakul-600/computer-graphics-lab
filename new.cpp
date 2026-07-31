/*
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.25, 1.0);
    glBegin(GL_POLYGON);

    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);

    glEnd();

    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0.0, 1.0,0.0, 1.0,-1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Hello");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
// p
    glColor3f(1.0, 0.25, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.20, 0.50);
        glVertex2f(0.50, 0.50);
        glVertex2f(0.50, 0.80);
        glVertex2f(0.20, 0.80);
    glEnd();
// G
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.50, 0.50);
        glVertex2f(0.80, 0.50);
        glVertex2f(0.80, 0.80);
        glVertex2f(0.50, 0.80);
    glEnd();
// B
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.20, 0.20);
        glVertex2f(0.80, 0.20);
        glVertex2f(0.80, 0.50);
        glVertex2f(0.20, 0.50);
    glEnd();

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("3 Blocks");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
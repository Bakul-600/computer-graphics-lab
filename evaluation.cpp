#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

float p = -10.0f; // Starting position

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Update position
    if (p <= 10.0f)
        p += 0.005f;
    else
        p = -10.0f;

    // Draw moving rectangle
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(p, 3.0f);
    glVertex2f(p + 3, 3.0f);
    glVertex2f(p + 3, -3.0f);
    glVertex2f(p, -3.0f);
    glEnd();

    glFlush();
    glutPostRedisplay();
}

// Initialization
void init()
{
    // Red background
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-10, 10, -10, 10, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Moving Object");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
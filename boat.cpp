#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

float boatX = -12.0f, wave = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Water
    // glColor3f(0.0f, 0.3f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-10, 0);
    glVertex2f(10, 0);
    glVertex2f(10, -10);
    glVertex2f(-10, -10);
    glEnd();

    // Waves
    glColor3f(1, 1, 1);
    for (float y = -1; y <= -1; y++)
    {
        glBegin(GL_LINE_STRIP);
        for (float x = -10; x <= 10; x += 0.2f)
            glVertex2f(x, y + 0.2f * sin(x + wave));
        glEnd();
    }

    // Boat
    glTranslatef(boatX, 0, 0);

    // Boat Body
    glBegin(GL_POLYGON);
    glVertex2f(-1.2f, -1);
    glVertex2f(1.2f, -1);
    glVertex2f(0.8f, -2);
    glVertex2f(-0.8f, -2);
    glEnd();

    // Canopy
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -1);
    glVertex2f(0.5f, -1);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(-0.5f, -0.2f);
    glEnd();

    // Roof
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    boatX += 0.01f;
    if (boatX > 12)
        boatX = -12;

    wave += 0.1f;

    glFlush();
    glutPostRedisplay();
}

void init()
{
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animated Boat");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
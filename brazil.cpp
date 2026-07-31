#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#define PI 3.14159265358979323846

// Draw Circle
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * PI / 180.0f;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2);

    // Outer Rectangle
    glBegin(GL_LINE_LOOP);
    glVertex2f(100, 100);
    glVertex2f(500, 100);
    glVertex2f(500, 400);
    glVertex2f(100, 400);
    glEnd();

    // Rotate Square
    glBegin(GL_LINE_LOOP);
    glVertex2f(300, 340); // Top
    glVertex2f(390, 250); // Right
    glVertex2f(300, 160); // Bottom
    glVertex2f(210, 250); // Left
    glEnd();

    // Circle
    drawCircle(300, 250, 55);

    // Horizontal Line
    glBegin(GL_LINES);
    glVertex2f(245, 250);
    glVertex2f(355, 250);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 500);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab Report 02");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
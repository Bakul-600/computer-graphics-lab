#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <cmath>
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++)
    {
        float theta = 2.0f * 3.1415926f * i / 100;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 60);
    glVertex2f(0, 60);
    glEnd();

    glColor3f(1, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(5, 5);
    glVertex2f(95, 5);
    glVertex2f(95, 55);
    glVertex2f(5, 55);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(2, 26);
    glVertex2f(5, 26);
    glVertex2f(5, 34);
    glVertex2f(2, 34);
    glEnd();

    glBegin(GL_LINES);
    for (float y = 26; y <= 34; y += 1)
    {
        glVertex2f(2, y);
        glVertex2f(5, y);
    }
    glEnd();

    glBegin(GL_LINES);
    for (float x = 2; x <= 5; x += 0.5)
    {
        glVertex2f(x, 26);
        glVertex2f(x, 34);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(50, 5);
    glVertex2f(50, 55);
    glEnd();

    drawCircle(50, 30, 6);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(50, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(5, 18);
    glVertex2f(18, 18);
    glVertex2f(18, 42);
    glVertex2f(5, 42);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(5, 24);
    glVertex2f(10, 24);
    glVertex2f(10, 36);
    glVertex2f(5, 36);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(82, 18);
    glVertex2f(95, 18);
    glVertex2f(95, 42);
    glVertex2f(82, 42);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(90, 24);
    glVertex2f(95, 24);
    glVertex2f(95, 36);
    glVertex2f(90, 36);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(95, 26);
    glVertex2f(98, 26);
    glVertex2f(98, 34);
    glVertex2f(95, 34);
    glEnd();

    glBegin(GL_LINES);
    for (float y = 26; y <= 34; y += 1)
    {
        glVertex2f(95, y);
        glVertex2f(98, y);
    }
    glEnd();

    glBegin(GL_LINES);
    for (float x = 95; x <= 98; x += 0.5)
    {
        glVertex2f(x, 26);
        glVertex2f(x, 34);
    }
    glEnd();

    glBegin(GL_POINTS);
    glVertex2f(14, 30);
    glEnd();

    glBegin(GL_POINTS);
    glVertex2f(86, 30);
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = -50; i <= 50; i++)
    {
        float t = i * 3.1415926 / 180.0;
        glVertex2f(14 + 6 * cos(t), 30 + 6 * sin(t));
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 130; i <= 230; i++)
    {
        float t = i * 3.1415926 / 180.0;
        glVertex2f(86 + 6 * cos(t), 30 + 6 * sin(t));
    }
    glEnd();

    float r = 2;
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 90; i++)
    {
        float t = i * 3.1415926 / 180.0;
        glVertex2f(5 + r * cos(t), 5 + r * sin(t));
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 90; i <= 180; i++)
    {
        float t = i * 3.1415926 / 180.0;
        glVertex2f(95 + r * cos(t), 5 + r * sin(t));
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 270; i <= 360; i++)
    {
        float t = i * 3.1415926 / 180.0;
        glVertex2f(5 + r * cos(t), 55 + r * sin(t));
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 180; i <= 270; i++)
    {
        float t = i * 3.1415926 / 180.0;
        glVertex2f(95 + r * cos(t), 55 + r * sin(t));
    }
    glEnd();
    glutSwapBuffers();
}
void init()
{
    glClearColor(0.2f, 0.7f, 0.2f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 60);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Football Field - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
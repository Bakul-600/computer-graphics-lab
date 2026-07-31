#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Color Constants
const float GREEN[] = {0.0f, 0.60f, 0.28f};
const float YELLOW[] = {1.0f, 0.82f, 0.00f};
const float BLUE[] = {0.08f, 0.15f, 0.47f};
const float WHITE[] = {1.0f, 1.0f, 1.0f};

// Draw a filled circle
void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Draw a straight white line
void drawStraightWhiteLine(float cx, float cy, float radius, float thickness)
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(270, 150, 260, 260);

    glColor3fv(WHITE);
    float halfThickness = thickness / 2.0f;

    glBegin(GL_QUADS);
    glVertex2f(cx - radius, cy - halfThickness);
    glVertex2f(cx + radius, cy - halfThickness);
    glVertex2f(cx + radius, cy + halfThickness);
    glVertex2f(cx - radius, cy + halfThickness);
    glEnd();

    glDisable(GL_SCISSOR_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Green Background
    glColor3fv(GREEN);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, 0.7f);
    glVertex2f(-1.0f, 0.7f);
    glEnd();

    // Yellow Diamond
    glColor3fv(YELLOW);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.55f);  // Top
    glVertex2f(0.85f, 0.0f);  // Right
    glVertex2f(0.0f, -0.55f); // Bottom
    glVertex2f(-0.85f, 0.0f); // Left
    glEnd();

    // Blue Center Circle
    glColor3fv(BLUE);
    drawCircle(0.0f, 0.0f, 0.32f, 100);

    // Straight White Line
    drawStraightWhiteLine(0.0f, 0.0f, 0.32f, 0.05f);
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -0.7, 0.7);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 560);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Brazil Flag");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
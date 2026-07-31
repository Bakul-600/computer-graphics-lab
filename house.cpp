#define GL_SILENCE_DEPRECATION
#include <cmath>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++)
    {
        float theta = 2.0f * 3.14159f * float(i) / 30.0f;
        glVertex2f(r * cosf(theta) + cx, r * sinf(theta) + cy);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // SKY BACKGROUND
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glColor3f(0.2f, 0.6f, 0.9f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // SUN
    glColor3f(1.0f, 0.85f, 0.0f);
    drawCircle(-0.7f, 0.7f, 0.15f);
    // CLOUDS
    glColor3f(0.95f, 0.95f, 0.95f);
    // Cloud 1
    drawCircle(0.5f, 0.7f, 0.08f);
    drawCircle(0.45f, 0.68f, 0.06f);
    drawCircle(0.55f, 0.68f, 0.06f);
    // Cloud 2
    drawCircle(-0.2f, 0.8f, 0.07f);
    drawCircle(-0.25f, 0.78f, 0.05f);
    drawCircle(-0.15f, 0.78f, 0.05f);

    // GRASS & GROUND
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.3f, 0.7f, 0.3f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glEnd();

    // CHIMNEY
    glColor3f(0.5f, 0.25f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.28f, 0.2f);
    glVertex2f(0.28f, 0.55f);
    glVertex2f(0.18f, 0.55f);
    glEnd();

    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, 0.55f);
    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.30f, 0.58f);
    glVertex2f(0.16f, 0.58f);
    glEnd();

    // HOUSE MAIN BODY
    glColor3f(0.85f, 0.85f, 0.85f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glEnd();

    // ROOF BASE
    glColor3f(0.7f, 0.2f, 0.15f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.45f, 0.2f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.0f, 0.6f);
    glEnd();

    // ROOF BRICK PATTERN
    glColor3f(0.5f, 0.1f, 0.05f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    // Row 1
    glVertex2f(-0.33f, 0.3f);
    glVertex2f(0.33f, 0.3f);
    glVertex2f(-0.22f, 0.3f);
    glVertex2f(-0.22f, 0.2f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.22f, 0.3f);
    glVertex2f(0.22f, 0.2f);

    // Row 2
    glVertex2f(-0.22f, 0.4f);
    glVertex2f(0.22f, 0.4f);
    glVertex2f(-0.11f, 0.4f);
    glVertex2f(-0.11f, 0.3f);
    glVertex2f(0.11f, 0.4f);
    glVertex2f(0.11f, 0.3f);

    // Row 3
    glVertex2f(-0.11f, 0.5f);
    glVertex2f(0.11f, 0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.0f, 0.4f);
    glEnd();

    // DOOR WITH KNOB
    glColor3f(0.3f, 0.15f, 0.05f); // Frame
    glBegin(GL_QUADS);
    glVertex2f(-0.12f, -0.4f);
    glVertex2f(0.12f, -0.4f);
    glVertex2f(0.12f, 0.02f);
    glVertex2f(-0.12f, 0.02f);
    glEnd();

    glColor3f(0.5f, 0.25f, 0.08f); // Door Body (Top at y = 0.0)
    glBegin(GL_QUADS);
    glVertex2f(-0.10f, -0.4f);
    glVertex2f(0.10f, -0.4f);
    glVertex2f(0.10f, 0.0f);
    glVertex2f(-0.10f, 0.0f);
    glEnd();

    glColor3f(0.9f, 0.7f, 0.1f); // Knob
    drawCircle(0.06f, -0.2f, 0.015f);

    // LEFT WINDOW
    glColor3f(0.3f, 0.15f, 0.05f); // Frame
    glBegin(GL_QUADS);
    glVertex2f(-0.34f, -0.19f);
    glVertex2f(-0.16f, -0.19f);
    glVertex2f(-0.16f, 0.01f);
    glVertex2f(-0.34f, 0.01f);
    glEnd();
    glColor3f(0.7f, 0.9f, 0.95f); // Glass
    glBegin(GL_QUADS);
    glVertex2f(-0.33f, -0.18f);
    glVertex2f(-0.17f, -0.18f);
    glVertex2f(-0.17f, 0.0f);
    glVertex2f(-0.33f, 0.0f);
    glEnd();
    glColor3f(0.3f, 0.15f, 0.05f); // Grid Lines
    glBegin(GL_LINES);
    glVertex2f(-0.25f, -0.18f);
    glVertex2f(-0.25f, 0.0f);
    glVertex2f(-0.33f, -0.09f);
    glVertex2f(-0.17f, -0.09f);
    glEnd();

    // RIGHT WINDOW
    glColor3f(0.3f, 0.15f, 0.05f); // Frame
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.19f);
    glVertex2f(0.34f, -0.19f);
    glVertex2f(0.34f, 0.01f);
    glVertex2f(0.16f, 0.01f);
    glEnd();
    glColor3f(0.7f, 0.9f, 0.95f); // Glass
    glBegin(GL_QUADS);
    glVertex2f(0.17f, -0.18f);
    glVertex2f(0.33f, -0.18f);
    glVertex2f(0.33f, 0.0f);
    glVertex2f(0.17f, 0.0f);
    glEnd();
    glColor3f(0.3f, 0.15f, 0.05f); // Grid Lines
    glBegin(GL_LINES);
    glVertex2f(0.25f, -0.18f);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.17f, -0.09f);
    glVertex2f(0.33f, -0.09f);
    glEnd();

    // TREE
    glColor3f(0.4f, 0.2f, 0.05f); // Trunk
    glBegin(GL_QUADS);
    glVertex2f(-0.73f, -0.4f);
    glVertex2f(-0.67f, -0.4f);
    glVertex2f(-0.67f, -0.05f);
    glVertex2f(-0.73f, -0.05f);
    glEnd();

    glColor3f(0.1f, 0.4f, 0.1f); // Leaves
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.85f, -0.1f);
    glVertex2f(-0.55f, -0.1f);
    glVertex2f(-0.7f, 0.15f);
    glVertex2f(-0.82f, 0.05f);
    glVertex2f(-0.58f, 0.05f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.78f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glVertex2f(-0.7f, 0.38f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D House Scene");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
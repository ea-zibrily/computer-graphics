/*

Code: Make Chair Object
File: transform3.cpp
Programmer: Zibrilyy | SHINONNN
Date: 26/09/2022

*/

/*

Membuat objek grafik bentuk kursi sederhana menggunakan glFrustum()

*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define pi 3.14

static float X = 0.0;
static float leftX = -2.0;
static float rightX = 2.0;
static float Y = 0.0;
static float legY = 0.5;
static float chairaY = 1.0;
static float chairbY = 2.0;
static float Z = -15.0;
GLfloat x, y;

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling left leg
    glPushMatrix();

    glTranslatef(leftX, legY, Z);
    glRotatef(80.0, 1.0, 0.0, 0.0);
    glRotatef(-30.0, 0.0, 1.0, 1.0);
    glColor3f(0.82, 0.4086, 0.1148);
    glutSolidCylinder(0.8, 10.0, 10.0, 2.0);

    glPopMatrix();

    // Modeling middle leg
    glPushMatrix();

    glTranslatef(X, Y, Z);
    glRotatef(80.0, 1.0, 0.0, 0.0);
    glColor3f(0.82, 0.4086, 0.1148);
    glutSolidCylinder(0.8, 11.0, 10.0, 2.0);

    glPopMatrix();

    // Modeling right leg
    glPushMatrix();

    glTranslatef(rightX, legY, Z);
    glRotatef(80.0, 1.0, 0.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 1.0);
    glColor3f(0.82, 0.4086, 0.1148);
    glutSolidCylinder(0.8, 10.0, 10.0, 2.0);

    glPopMatrix();

    // Modeling chair 3D - A
    glPushMatrix();

    glTranslatef(X, chairaY, Z);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 370; ++i)
    {
        glColor3f(0.82, 0.4086, 0.1148);
        // glColor3f(0.62, 0.3633, 0.0496);
        glVertex2f(2.0f * cos(pi * i / 180) * 3.5, sin(pi * i / 180) * 3.5);
    }

    glEnd();

    glPopMatrix();

    // Modeling chair 3D - B
    glPushMatrix();

    glTranslatef(X, chairbY, Z);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 370; ++i)
    {
        // glColor3f(1.0, 0.55, 0.0);
        glColor3f(0.9, 0.54, 0.036);
        glVertex2f(2.0f * cos(pi * i / 180) * 3.5, sin(pi * i / 180) * 3.5);
    }

    glEnd();

    glPopMatrix();

    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
        X += 0.5;
        leftX += 0.5;
        rightX += 0.5;
        glutPostRedisplay();
        break;
    case 'd':
        X -= 0.5;
        leftX -= 0.5;
        rightX -= 0.5;
        glutPostRedisplay();
        break;
    case 's':
        Y -= 0.5;
        legY -= 0.5;
        chairaY -= 0.5;
        chairbY -= 0.5;
        glutPostRedisplay();
        break;
    case 'w':
        Y += 0.5;
        legY += 0.5;
        chairaY += 0.5;
        chairbY += 0.5;
        glutPostRedisplay();
        break;
    case 'q':
        Z -= 0.5;
        glutPostRedisplay();
        break;
    case 'e':
        Z += 0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("chair.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}

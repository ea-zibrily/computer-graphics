/*

Code: Draw with glut
File: transform4.cpp
Programmer: Zibrilyy | SHINONNN
Date: 27/09/2022

*/

/*

Membuat objek grafik bentuk pizza sederhana menggunakan glFrustum()

*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define PI 3.14

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;


void drawLeftCircle() // the filled one
{
    float radius = 0.5;
    float twoPI = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);

    for (float i = PI; i <= twoPI; i += 0.001)
        glVertex2f((sin(i) * radius), (cos(i) * radius));

    glEnd();
    glFlush();
}

void drawRightHalfCircle() // the empty one
{
    float radius = 70;
    float twoPI = 2 * PI;

    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
    {
        glRotatef(60.0, 0.0, 1.0, 0.0);
        // glRotatef(60.0, 1.0, 0.0, 1.0);
        glutSolidCone((sin(i) * radius), (cos(i) * radius), 20.0, 5.0);
        glVertex2f((sin(i) * radius), (cos(i) * radius));
    }

    glEnd();
    glFlush();
}


// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling transformations.
    
        // shape 1
        glPushMatrix();

        glTranslatef(X, Y, Z);
        glRotatef(60.0, 0.0, 1.0, 0.0);
        // glRotatef(60.0, 1.0, 0.0, 1.0);
        glutSolidCone(3.0, 5.5, 20.0, 5.0);

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
        glutPostRedisplay();
        break;
    case 'd':
        X -= 0.5;
        glutPostRedisplay();
        break;
    case 's':
        Y -= 0.5;
        glutPostRedisplay();
        break;
    case 'w':
        Y += 0.5;
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
    glutCreateWindow("circle-cone.cpp");
    //glutDisplayFunc(drawScene);
    glutDisplayFunc(drawLeftCircle);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14
using namespace std;

// fungsi untuk menggambar titik
void drawDot(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void draw()
{
    int x = 0 ;
    int y = 0;
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x, y + 50);
    glVertex2d(x + 100, y + 50);
    glVertex2d(x + 100, y);
    glVertex2d(x, y);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);

    glutCreateWindow("Primitive Draw 2");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
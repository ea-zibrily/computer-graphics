#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
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
    glPointSize(10);    // fungsi untuk menentukan ukuran pixell point
    glColor3f(0, 1, 0); // fungsi untuk memberi warna point
    drawDot(0, 0);      // menggambar point dengan koordinat berbeda

    glColor3f(0, 1, 1);
    drawDot(50, 0);

    glColor3f(1, 1, 0);
    drawDot(-50, 0);
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

    glutCreateWindow("Primitive Draw 6");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
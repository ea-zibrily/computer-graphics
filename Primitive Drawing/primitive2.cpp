#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

//fungsi untuk menggambar titik
void drawDot(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void draw()
{
    glPointSize(5); //fungsi untuk menentukan ukuran pixell point
    drawDot(100,50); //menggambar point dengan koordinat berbeda
    drawDot(100,130);
    
    //tutor kids ez ez ez
    glPointSize(5);
    drawDot(150,130);
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
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640, 480);

    glutCreateWindow("Primitive Draw 2");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void drawPolygon()
{
    glBegin(GL_POLYGON);

    /*// bentuk tanda save
    glVertex2f(-100, 100);

    glVertex2f(100, -100);

    glVertex2f(100, 100);

    glVertex2f(-100, -100);
    */

    // pattern sesuai soal
    glColor3f(0., 0., 1.); // biru
    glVertex2f(100, 100);

    glColor3f(1., 1., 0.); // kuning
    glVertex2f(-100, 100);

    glColor3f(1., 0., 0.); // merah
    glVertex2f(-100, -100);

    glColor3f(0., 1., 0.); // hijau
    glVertex2f(100, -100);

    /*
    // pattern modifikasi
    glColor3f(1., 1., 0.); // kuning
    glVertex2f(-100, 100);

    glColor3f(0., 0., 1.); // biru
    glVertex2f(100, 100);

    glColor3f(0., 1., 0.); // hijau
    glVertex2f(100, -100);

    glColor3f(1., 0., 0.); // merah
    glVertex2f(-100, -100);
    */

    glEnd();
}

void draw()
{
    drawPolygon();
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

    glutCreateWindow("Primitive Draw Rectangle");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
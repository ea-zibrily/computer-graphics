#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void drawLine()
{
    glBegin(GL_LINE_STRIP);

    glVertex2f(-200, 200);
    glVertex2f(200, 200);

    glEnd();
}

void drawRectangle()
{
    glBegin(GL_POLYGON);

    glColor3f(1., 1., 0.); // kuning
    glVertex2f(100, -100);

    glColor3f(0., 0., 1.); // biru
    glVertex2f(100, 100);

    glColor3f(0., 1., 0.); // hijau
    glVertex2f(-100, 100);

    glColor3f(1., 0., 0.); // merah
    glVertex2f(-100, -100);

    glEnd();
}

void drawTriangle()
{
    glBegin(GL_POLYGON);

    glColor3f(0, 1, 0);
    // glVertex3f(0.6, -0.75, 0);
    glVertex2f(20, -50);

    glColor3f(0, 0, 1);
    // glVertex3f(0, 0.75, 0);
    glVertex2f(-20, 50);

    glColor3f(1, 0, 0);
    // glVertex3f(-0.6, -0.75, 0.5);
    glVertex2f(-50, -50);

    glEnd();
}

void draw()
{
    drawLine();
    drawRectangle();
    drawTriangle();
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
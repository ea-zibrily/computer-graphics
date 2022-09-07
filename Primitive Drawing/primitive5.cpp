#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void drawPolygon()
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(100, 100);
    glVertex2f(200, 150);
    glVertex2f(300, 50);
    glEnd();
}

void draw()
{
    /*
    glColor3f(0., 0., 1.); //mengganti warna garis
    glLineWidth(5); //mengganti ukuran garis
    */
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
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640, 480);

    glutCreateWindow("Primitive Draw 5");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}
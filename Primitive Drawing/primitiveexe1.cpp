#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

// fungsi untuk menggambar lingkaran
void drawCircle()
{
    GLfloat x, y, phi;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);

    for (phi = 0.0f; phi <= (2.0f * 3.14); phi += 0.01f)
    {
        glColor3f(0, 1, 0);
        x = 150.0f * sin(phi);
        y = 150.0f * cos(phi);
        glColor3f(1.,0.,1.);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void draw()
{
    drawCircle();   
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

    glutCreateWindow("Primitive Draw Circle");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
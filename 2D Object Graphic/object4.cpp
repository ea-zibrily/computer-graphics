/*
Code: Make 2D Object Graphic - Animasi 2D dengan Koordinat Polar
File: object4.cpp
Programmer: Zibrilyy | SHINONNN
Date: 14/09/2022
*/

/*
Membuat animasi 2D dengan koordinat polar menggunakan drawPolygon
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

// dapat mengubah variabel menjadi true agar animasi berjalan.
static bool spinning = true;

// membuat variabel untuk fps
static const int FPS = 60;
static GLfloat currentAngleOfRotation = 0.0;

// membuat struct dengan nama lain point2D
typedef struct point
{
    float x;
    float y;
} point2D;

// func untuk menggambar polygon
void drawPolygon(point2D shp[], int n)
{
    int i;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < n; i++)
    {
        glVertex2f(shp[i].x, shp[i].y);
    }
    glEnd();
}

void draw()
{
    static int tick = 0;
    point2D shape[360];
    int i;
    double srad, r;

    for (i = 0; i < 360; i++)
    {
        srad = (i + tick) * 3.14 / 180;
        r = sin(5 * srad);

        shape[i].x = (float)(r * cos(srad));
        shape[i].y = (float)(r * sin(srad));
    }

    // memanggil func drawPolygon
    glLineWidth(2);
    drawPolygon(shape, 360);
    tick++;
}

void timer(int v)
{
    if (spinning)
    {
        currentAngleOfRotation += 1.0;
        if (currentAngleOfRotation > 360.0)
        {
            currentAngleOfRotation -= 360.0;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000 / FPS, timer, v);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        spinning = true;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        spinning = false;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(currentAngleOfRotation, 0.0, 0.0, 1.0);
    draw();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(640, 480);

    glutCreateWindow("Object Graphic 2D 4");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
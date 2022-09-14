/*
Code: Make 2D Object Graphic - Rose 5 Daun
File: object3.cpp
Programmer: Zibrilyy | SHINONNN
Date: 14/09/2022
*/

/*
Membuat objek grafik 2D bentuk rose 5 daun menggunakan drawPolygon
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

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
    point2D rose[360];
    int i;
    float size;
    double srad, r;

    for (i = 0; i < 360; i++)
    {
        srad = i * 3.14 / 180;
        r = sin(5 * srad);

        //membuat var size untuk memperbesar ukuran objek
        size = r * 200;
        rose[i].x = (float)(size * cos(srad));
        rose[i].y = (float) (size * sin(srad));
    }

    //memanggil func drawPolygon
    glLineWidth(2);
    drawPolygon(rose, 360);
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
        glutInitWindowPosition(150, 150);
        glutInitWindowSize(640, 480);

        glutCreateWindow("Object Graphic 2D 3");
        glClearColor(0.0, 0.0, 0.0, 0.0);
        gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
        glutIdleFunc(display);
        glutDisplayFunc(display);
        glutMainLoop();

        return 0;
    }
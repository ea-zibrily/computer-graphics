/*
Code: Make 2D Object Graphic - Bintang
File: object2.cpp
Programmer: Zibrilyy | SHINONNN
Date: 14/09/2022
*/

/*
Membuat objek grafik 2D bentuk bintang menggunakan drawPolygon
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

//membuat struct dengan nama lain point2D
typedef struct point
{
    float x;
    float y;
} point2D;

//func untuk menggambar polygon
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
    point2D bintang[10] = {{80,146},{99,90},{157,90},{110,55},{128,1},
    {80,34},{32,1},{54,55},{3,90},{63,90}};

    //memanggil func drawPolygon
    //glLineWidth(10);
    drawPolygon(bintang, 10);
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

    glutCreateWindow("Object Graphic 2D 2");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
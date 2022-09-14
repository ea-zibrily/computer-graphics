/*
Code: Make 2D Object Graphic - Kotak
File: object1.cpp
Programmer: Zibrilyy | SHINONNN
Date: 14/09/2022
*/

/*
Membuat objek grafik 2D bentuk kotak menggunakan drawPolygon
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
    point2D kotak[4] = {{100,100},{300,100},{300,200},{100,200}};

    //memanggil func drawPolygon
    drawPolygon(kotak, 4);
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

    glutCreateWindow("Object Graphic 2D 1");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
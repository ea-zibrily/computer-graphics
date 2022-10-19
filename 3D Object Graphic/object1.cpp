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

// membuat struct dengan nama lain point2D
typedef struct point
{
    float x;
    float y;
} point2D;

//<summary>
// membuat struct untuk menggambar point 3D
//</summary>
typedef struct
{
    float x, y, z;
} point3D_t;

typedef struct
{
    int NumberofVertices;
    short int pnt[32];
} face_t;

typedef struct
{
    int NumberofVertices;
    point3D_t pnt[100];
    int NumberofFaces;
    face_t fc[32];
} object3D_t;

void draw()
{
    object3D_t prisma = {5, {{0, 100, 0}, {100, 0, 0}, 
    {0, 0, 100}, {-100, 0, 0}, {0, 0, -100}}, 5, 
    {{3, {0, 1, 2}}, {3, {0, 2, 3}}, {3, {0, 3, 4}}, {3, 
    {0, 4, 1}}, {4, {1, 4, 3, 2}}}};
    
    
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

    glutCreateWindow("Object Graphic 3D 1");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
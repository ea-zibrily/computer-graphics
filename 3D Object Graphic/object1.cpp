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

//<summary>
// membuat struct untuk menggambar point 3D
//</summary>
typedef struct
{
    float x;
    float y;
    float z;
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

//<summary>
// membuat struct untuk menggambar vektor 3D
//</summary>

typedef struct
{
    float x;
    float y;
} point2D_t;

typedef struct
{
    float v[4];
} vector3D_t;

// vektor 2d ke 3d
point2D_t Vector2Point2D(vector3D_t vec)
{
    point2D_t pnt;
    pnt.x = vec.v[0];
    pnt.y = vec.v[1];
    return pnt;
}

// vektor 3d ke 3d
vector3D_t Point2Vector(point3D_t pnt)
{
    vector3D_t vec;
    vec.v[0] = pnt.x;
    vec.v[1] = pnt.y;
    vec.v[2] = pnt.z;
    vec.v[3] = 1.;
    return vec;
}

typedef struct
{
    float x;
    float y;
} matrix3D_t;

void drawPolygon(point2D_t shp[], int n)
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
    float theta = 0.5;
    //matrix3D_t tilting = rotationXMTX(theta) * rotationYMTX(-theta);
    
    object3D_t prisma = {5, {{0, 100, 0}, {100, 0, 0}, {0, 0, 100}, {-100, 0, 0}, {0, 0, -100}}, 5, {{3, {0, 1, 2}}, {3, {0, 2, 3}}, {3, {0, 3, 4}}, {3, {0, 4, 1}}, {4, {1, 4, 3, 2}}}};

    /*
    mat = tilting;
    for (i = 0; i < prisma.NumberofVertices; i++)
    {
        vec[i] = Point2Vector(prisma.pnt[i]);
        vec[i] = mat * vec[i];
    }
    for (i = 0; i < prisma.NumberofFaces; i++)
    {
        for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
            vecbuff[j] = vec[prisma.fc[i].pnt[j]];
        for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
            titik2D[j] = Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
        drawPolygon(titik2D, prisma.fc[i].NumberofVertices);
    }
    */
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
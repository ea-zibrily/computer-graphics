#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

typedef struct point
{
    float x;
    float y;
} point2D;

typedef struct colorPoint
{
    float r;
    float g;
    float b;
} rgbColor;

void setColor(rgbColor color)
{
    glColor3f(color.r, color.g, color.b);
};

void drawPolyline(point2D shp[], int n)
{
    int i;
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < n; i++)
    {
        glVertex2f(shp[i].x, shp[i].y);
    }
    glEnd();
}

// bentuk polygon tidak berwarna
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

// bentuk polygon berwarna
void fillPolygon(point2D shp[], int n, rgbColor color)
{
    int i;
    setColor(color);
    glBegin(GL_POLYGON);
    for (i = 0; i < n; i++)
    {
        glVertex2f(shp[i].x, shp[i].y);
    }
    glEnd();
}

// bentuk polygon berwarna gradasi
void gradPolygon(point2D shp[], int n, rgbColor color)
{
    int i;
    glBegin(GL_POLYGON);
    for (i = 0; i < n; i++)
    {
        setColor(color);
        glVertex2f(shp[i].x, shp[i].y);
    }
    glEnd();
}

void draw()
{
    point2D kotak[4] = {{100, 100}, {300, 100}, {300, 200}, {100, 200}};
    drawPolyline(kotak, 4);
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

    glutCreateWindow("Primitive Draw 1");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
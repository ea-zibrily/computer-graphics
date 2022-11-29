/*

Code: Make Presence Box w/ Texture
File: project2.cpp
Programmer: 1. Zibril Yuan Afrianto | 5221600002
            2. Ahmad Rizky Juli Ridhani | 5221600026
Date: 21/11/2022

*/

/*

Membuat objek grafika 3D bentuk benda-benda yang ada dalam
lab Game Art/Komputer Grafika (GT-302), kemudian menambahkan
texture dan lighting pada benda yang dipilih

==================================

Pilihan benda: Mesin Presensi Mahasiswa (Box Presensi)

*/

//#include <iostream>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
GLuint texture;
// using namespace std;

static float X = 0.0;
static float secX = -2.2;
static float treX = -1.0;
static float Y = 0.0;
static float secY = 1.5;
static float treY = 4.5;
static float Z = -15.0;
static float secZ = -14.0;
static float treZ = -20.0;

// pattern position
static float pat1X = 4.0; // 4.0, -0.7
static float pat1Y = -0.7;
static float pat2X = 3.3; // 3.3, -1.7
static float pat2Y = -1.7;

// input position
static float inX = 3.0; // 3.0, 2.5
static float in1Y = 2.5;
static float in2Y = 1.5;
static float in3Y = 0.5;

// card position
static float card1X = -0.8; //-0.8, -2.1
static float card1Y = -2.1;
static float card2Y = -1.7;

// globalLight
//  Globals.
static int light0On = 1;                          // White light on?
static int light1On = 1;                          // Green light on?
static float d = 1.0;                             // Diffuse and specular white light intensity.
static float m = 0.2;                             // Global ambient white light intensity.
static int localViewer = 1;                       // Local viewpoint?
static float p = 1.0;                             // Positional light?
static float t = 0.0;                             // Quadratic attenuation factor.
static float zMove = 0.0;                         // z-direction component.
static float xAngle = 0.0, yAngle = 0.0;          // Rotation angles of white light.
static long font = (intptr_t)GLUT_BITMAP_8_BY_13; // Font selection.
static char theStringBuffer[10];                  // String buffer.

void loadTextureFromFile(const char *filename, unsigned int texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
        // cout << "Failed to load texture" << endl;
    }
    stbi_image_free(data);
}

const char *filename1 = "wp.jpg";
const char *filename2 = "bp.jpg";
unsigned int tob[2];

void FreeTexture(GLuint texture)
{
    glDeleteTextures(3, &texture);
}

static void drawBox(GLfloat size, GLenum type)
{
    static GLfloat n[6][3] =
        {
            {-1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0},
            {1.0, 0.0, 0.0},
            {0.0, -1.0, 0.0},
            {0.0, 0.0, 1.0},
            {0.0, 0.0, -1.0}};

    static GLint faces[6][4] =
        {
            {0, 1, 2, 3},
            {3, 2, 6, 7},
            {7, 6, 5, 4},
            {4, 5, 1, 0},
            {5, 6, 2, 1},
            {7, 4, 0, 3}};
    GLfloat v[8][3];
    GLint i;

    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

    for (i = 5; i >= 0; i--)
    {
        glBegin(type);
        glNormal3fv(&n[i][0]);

        glTexCoord2d(0.0, 0.0);
        glVertex3fv(&v[faces[i][0]][0]);
        glTexCoord2d(0.0, 1.0);
        glVertex3fv(&v[faces[i][1]][0]);
        glTexCoord2d(1.0, 1.0);
        glVertex3fv(&v[faces[i][2]][0]);
        glTexCoord2d(1.0, 0.0);
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }
}

void APIENTRY
myglutSolidCube(GLdouble size)
{
    drawBox(size, GL_QUADS);
}

void init()
{
    // for 3d lighting
    glEnable(GL_DEPTH_TEST);     // depth test
    glEnable(GL_LIGHTING);       // enable light from a single source
    glEnable(GL_LIGHT0);         // enable white light , diffuse and specular components
    glEnable(GL_COLOR_MATERIAL); // track the current color
}

// Drawing routine.
void drawScene(void)
{
    /*
    // Light property vectors.
    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
    float lightDifAndSpec0[] = { d, d, d, 1.0 };
    float lightPos0[] = { 0.0, 0.0, 3.0, p };
    float lightDifAndSpec1[] = { 0.0, 1.0, 0.0, 1.0 };
    float lightPos1[] = { 1.0, 2.0, 0.0, 1.0 };
    float globAmb[] = { m, m, m, 1.0 };

    // Light0 properties.
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec0);

    // Light1 properties.
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDifAndSpec1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightDifAndSpec1);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer); // Enable local viewpoint

    // Turn lights off/on.
    if (light0On) glEnable(GL_LIGHT0); else glDisable(GL_LIGHT0);
    if (light1On) glEnable(GL_LIGHT1); else glDisable(GL_LIGHT1);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Light quadratic attenuation factor.
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, t);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, t);


    gluLookAt(3.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw light source spheres (or arrow) after disabling lighting.
    glDisable(GL_LIGHTING);
    // Light0 positioned and sphere positioned in case of positional light
    // and arrow in case of directional light.
    glPushMatrix();
    glRotatef(xAngle, 1.0, 0.0, 0.0); // Rotation about x-axis.
    glRotatef(yAngle, 0.0, 1.0, 0.0); // Rotation about y-axis.
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glTranslatef(lightPos0[0], lightPos0[1], lightPos0[2]);
    glColor3f(d, d, d);
    if (light0On)
    {
        if (p) myglutSolidCube(4); // Sphere at positional light source.
        else // Arrow pointing along incoming directional light.
        {
            glLineWidth(3.0);
            glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 0.25);
            glVertex3f(0.0, 0.0, -0.25);
            glVertex3f(0.0, 0.0, -0.25);
            glVertex3f(0.05, 0.0, -0.2);
            glVertex3f(0.0, 0.0, -0.25);
            glVertex3f(-0.05, 0.0, -0.2);
            glEnd();
            glLineWidth(1.0);
        }
    }
    glPopMatrix();

    // Light1 and its sphere positioned.
    glPushMatrix();
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glTranslatef(lightPos1[0], lightPos1[1], lightPos1[2]);
    glColor3f(0.0, 1.0, 0.0);
    if (light1On) myglutSolidCube(4);
    glPopMatrix();

    glEnable(GL_LIGHTING);
    */

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    // glRotatef(45.0, 0.0, 1.0, 0.0);

    //<summary
    // buat wadah kabel bagian belakang box alat
    //</summary>

    // Modeling wadah kabel
    glBindTexture(GL_TEXTURE_2D, tob[0]);
    glPushMatrix();

    glTranslatef(X, treY, treZ);
    glScalef(1.7, 15.0, 0.5);
    glColor3f(0.752941, 0.752941, 0.752941);
    myglutSolidCube(1.5);

    glPopMatrix();

    //<summary
    // buat bagian box alat presensi
    //</summary>

    // Modeling main box
    glBindTexture(GL_TEXTURE_2D, tob[0]);
    glPushMatrix();
    // glEnable(GL_TEXTURE_2D);

    glTranslatef(X, Y, Z);
    glScalef(3.0, 2.5, 0.5);
    glColor3f(0.0, 0.0, 0.0);
    myglutSolidCube(4);

    glPopMatrix();

    // Modeling secondary box
    glBindTexture(GL_TEXTURE_2D, tob[1]);
    glPushMatrix();

    glTranslatef(X, Y, secZ);
    glScalef(3.0, 2.5, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    myglutSolidCube(3);

    //<summary>
    // ini coba pake polygon cuman agak aneh
    //</summary>
    /*
    glBegin(GL_POLYGON);

    glVertex2f(3, 3);
    glVertex2f(-3, 3);
    glVertex2f(-3, -3);
    glVertex2f(3, -3);

    glEnd();
    */

    glPopMatrix();

    // Modeling inner box
    glPushMatrix();

    glTranslatef(treX, secY, secZ);
    glScalef(5.0, 2.5, 0.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    myglutSolidCube(1);

    glPopMatrix();

    // Modeling screen box
    glPushMatrix();

    glTranslatef(secX, secY, secZ);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glColor3f(0.309804, 0.309804, 0.184314); // dark olive green color
    glutSolidCylinder(1.0, 2.5, 30.0, 2.0);

    glPopMatrix();

    // Modeling pattern 1
    glPushMatrix();

    glTranslatef(pat1X, pat1Y, secZ);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.658824, 0.658824, 0.658824);
    glLineWidth(3.0);

    glVertex2f(0.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(-1.0, -1.5);
    glVertex2f(0.0, -1.5);

    glEnd();

    glPopMatrix();

    // Modeling pattern 2
    glPushMatrix();

    glTranslatef(pat2X, pat2Y, secZ);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.196078, 0.6, 0.8); // sky blue color
    glLineWidth(3.0);

    glVertex2f(0.2, 0.2);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, -1.0);
    glVertex2f(0.2, -1.0);

    glEnd();

    glPopMatrix();

    // Modeling input 1
    glPushMatrix();

    glTranslatef(inX, in1Y, secZ);
    glScalef(2.0, 0.4, 0.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    myglutSolidCube(1);

    glPopMatrix();

    // Modeling input 2
    glPushMatrix();

    glTranslatef(inX, in2Y, secZ);
    glScalef(2.0, 0.4, 0.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    myglutSolidCube(1);

    glPopMatrix();

    // Modeling input 3
    glPushMatrix();

    glTranslatef(inX, in3Y, secZ);
    glScalef(2.0, 0.4, 0.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    myglutSolidCube(1);

    glPopMatrix();

    // Modeling card 1
    glPushMatrix();

    glTranslatef(card1X, card1Y, secZ);
    glScalef(1.2, 1.9, 0.0);
    glRotatef(-20.0, 0.0, 0.0, 1.0);
    glColor3f(0.80, 0.80, 0.80); // grey color
    myglutSolidCube(1);

    glPopMatrix();

    // Modeling card 2
    glPushMatrix();

    glTranslatef(treX, card2Y, secZ);
    glScalef(1.2, 1.9, 0.0);
    glRotatef(-20.0, 0.0, 0.0, 1.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    myglutSolidCube(1);

    glPopMatrix();

    glFlush();
    glDisable(GL_TEXTURE_2D);
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    /*
     glEnable(GL_DEPTH_TEST); // Enable depth testing.

    // Turn on OpenGL lighting.
    glEnable(GL_LIGHTING);

    // Material property vectors.
    float matAmbAndDif[] = {0.0, 0.0, 1.0, 1.0};
    float matSpec[] = {1.0, 1.0, 1, 0, 1.0};
    float matShine[] = {50.0};

    // Material properties of ball.
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

    // Cull back faces.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    */
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
        X += 0.5;
        secX += 0.5;
        treX += 0.5;
        pat1X += 0.5;
        pat2X += 0.5;
        inX += 0.5;
        card1X += 0.5;
        glutPostRedisplay();
        break;
    case 'd':
        X -= 0.5;
        secX -= 0.5;
        treX -= 0.5;
        pat1X -= 0.5;
        pat2X -= 0.5;
        inX -= 0.5;
        card1X -= 0.5;
        glutPostRedisplay();
        break;
    case 's':
        Y -= 0.5;
        secY -= 0.5;
        treY -= 0.5;
        pat1Y -= 0.5;
        pat2Y -= 0.5;
        in1Y -= 0.5;
        in2Y -= 0.5;
        in3Y -= 0.5;
        card1Y -= 0.5;
        card1Y -= 0.5;
        glutPostRedisplay();
        break;
    case 'w':
        Y += 0.5;
        secY += 0.5;
        treY += 0.5;
        pat1Y += 0.5;
        pat2Y += 0.5;
        in1Y += 0.5;
        in2Y += 0.5;
        in3Y += 0.5;
        card1Y += 0.5;
        card1Y += 0.5;
        glutPostRedisplay();
        break;
    case 'q':
        Z -= 0.5;
        secZ -= 0.5;
        treZ -= 0.5;
        glutPostRedisplay();
        break;
    case 'e':
        Z += 0.5;
        secZ += 0.5;
        treZ += 0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("presence-box.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glGenTextures(2, &tob[0]);
    loadTextureFromFile(filename1, tob[0]);
    loadTextureFromFile(filename2, tob[1]);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}

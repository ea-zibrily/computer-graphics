/*

Code: Make Presence Box
File: project1.cpp
Programmer: 1. Zibril Yuan Afrianto | 5221600002
            2. Ahmad Rizky Juli Ridhani | 5221600026
Date: 18/10/2022

*/

/*

Membuat objek grafika 3D bentuk benda-benda yang ada dalam
lab Game Art/Komputer Grafika (GT-302)

==================================

Pilihan benda: Mesin Presensi Mahasiswa (Box Presensi)

*/

#include <GL/glew.h>
#include <GL/freeglut.h>

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

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();
    // glRotatef(45.0, 0.0, 1.0, 0.0);

    //<summary
    // buat wadah kabel bagian belakang box alat
    //</summary>

    // Modeling wadah kabel
    glPushMatrix();

    glTranslatef(X, treY, treZ);
    glScalef(1.7, 15.0, 0.5);
    glColor3f(0.752941, 0.752941, 0.752941);
    glutSolidCube(1.5);

    glPopMatrix();

    //<summary
    // buat bagian box alat presensi
    //</summary>

    // Modeling main box
    glPushMatrix();

    glTranslatef(X, Y, Z);
    glScalef(3.0, 2.5, 0.5);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidCube(4);

    glPopMatrix();

    // Modeling secondary box
    glPushMatrix();

    glTranslatef(X, Y, secZ);
    glScalef(3.0, 2.5, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(3);

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
    glutSolidCube(1);

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
    glutSolidCube(1);

    glPopMatrix();

    // Modeling input 2
    glPushMatrix();

    glTranslatef(inX, in2Y, secZ);
    glScalef(2.0, 0.4, 0.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    glutSolidCube(1);

    glPopMatrix();

    // Modeling input 3
    glPushMatrix();

    glTranslatef(inX, in3Y, secZ);
    glScalef(2.0, 0.4, 0.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    glutSolidCube(1);

    glPopMatrix();

    // Modeling card 1
    glPushMatrix();

    glTranslatef(card1X, card1Y, secZ);
    glScalef(1.2, 1.9, 0.0);
    glRotatef(-20.0, 0.0, 0.0, 1.0);
    glColor3f(0.80, 0.80, 0.80); // grey color
    glutSolidCube(1);

    glPopMatrix();

    // Modeling card 2
    glPushMatrix();

    glTranslatef(treX, card2Y, secZ);
    glScalef(1.2, 1.9, 0.0);
    glRotatef(-20.0, 0.0, 0.0, 1.0);
    glColor3f(0.658824, 0.658824, 0.658824); // light grey color
    glutSolidCube(1);

    glPopMatrix();

    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
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

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

typedef struct {
	float x,y;
} point2D_t;

typedef struct {
	float x,y,z;
} point3D_t;

typedef struct {
	float v[4];
} vector3D_t;

typedef struct {
	float m[4][4];
} matrix3D_t;

typedef struct {
	float r,g,b;
} color_t;

vector3D_t point2vector(point3D_t pnt)
{
    vector3D_t vec;
    vec.v[0]=pnt.x;
    vec.v[1]=pnt.y;
	vec.v[2]=pnt.z;
    vec.v[3]=1.;
	return vec;
}

point3D_t vector2point(vector3D_t vec)
{
    point3D_t pnt;
    pnt.x=vec.v[0];
    pnt.y=vec.v[1];
    pnt.z=vec.v[2];
    return pnt;
}

point2D_t vector2point2D(vector3D_t vec)
{
    point2D_t pnt;
    pnt.x=vec.v[0];
    pnt.y=vec.v[1];
    return pnt;
}

matrix3D_t createIdentity(void) {
	matrix3D_t u;
	int i,j;
	for (i=0;i<4;i++) {
		for(j=0;j<4;j++) u.m[i][j]=0.;
		u.m[i][i]=1.;
	}
	return u;
}


matrix3D_t rotationXMTX(float theta)
{
	matrix3D_t rotate=createIdentity();
	float cs=cos(theta);
	float sn=sin(theta);
	rotate.m[0][0]=cs; rotate.m[0][1]=-sn;
	rotate.m[1][0]=sn; rotate.m[1][1]=cs;
	return rotate;
}

matrix3D_t rotationYMTX(float theta)
{
	matrix3D_t rotate=createIdentity();
	float cs=cos(theta);
	float sn=sin(theta);
	rotate.m[0][0]=cs; rotate.m[0][2]=-sn;
	rotate.m[2][0]=sn; rotate.m[2][2]=cs;
	return rotate;
}

matrix3D_t rotationZMTX(float theta)
{
	matrix3D_t rotate=createIdentity();
	float cs=cos(theta);
	float sn=sin(theta);
	rotate.m[1][1]=cs; rotate.m[1][2]=-sn;
	rotate.m[2][1]=sn; rotate.m[2][2]=cs;
	return rotate;
}

matrix3D_t translationMTX(float dx,float dy,float dz)
{
	matrix3D_t trans=createIdentity();
	trans.m[0][3]=dx;
	trans.m[1][3]=dy;
	trans.m[2][3]=dz;
	return trans;
}

matrix3D_t scalingMTX(float sx,float sy, float sz)
{
	matrix3D_t r=createIdentity();
	r.m[0][0]=sx;
	r.m[1][1]=sy;
	r.m[2][2]=sz;
	return r;
}

vector3D_t operator ^ (vector3D_t a, vector3D_t b)
{
	vector3D_t c;//c=a*b
	c.v[0]=a.v[1]*b.v[2]-a.v[2]*b.v[1];
	c.v[1]=a.v[2]*b.v[0]-a.v[0]*b.v[2];
	c.v[2]=a.v[0]*b.v[1]-a.v[1]*b.v[0];
	c.v[3]=1.;
	return c;
}

vector3D_t operator - (vector3D_t a, vector3D_t b)
{
	vector3D_t c;//c=a*b
	for(int i=0;i<3;i++)
		c.v[i]=a.v[i]-b.v[i];
	c.v[3]=1.;
	return c;
}

matrix3D_t operator * (matrix3D_t a, matrix3D_t b)
{
	matrix3D_t c;//c=a*b
	int i,j,k;
	for (i=0;i<4;i++) for (j=0;j<4;j++) {
		c.m[i][j]=0;
		for (k=0;k<4;k++) 
			c.m[i][j]+=a.m[i][k]*b.m[k][j];
	}
	return c;
}

vector3D_t operator * (matrix3D_t a, vector3D_t b)
{
	vector3D_t c;//c=a*b
	int i,j;
	for (i=0;i<4;i++) {
		c.v[i]=0;
		for (j=0;j<4;j++) 
			c.v[i]+=a.m[i][j]*b.v[j];
	}
	return c;
}

void setColor(float r,float g,float b){
	glColor3f(r,g,b);
}

void setColor(color_t col){
	glColor3f(col.r,col.g,col.b);
}

void drawDot(float x,float y){
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void drawDot(point2D_t p){
	glBegin(GL_POINTS);
	glVertex2f(p.x,p.y);
	glEnd();
}

void drawLine(float x1, float y1, float x2,float y2){
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}

void drawLine(point2D_t p1,point2D_t p2){
	glBegin(GL_LINES);
	glVertex2f(p1.x,p1.y);
	glVertex2f(p2.x,p2.y);
	glEnd();
}

void drawPolygon(point2D_t p[],int n){
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<n;i++) glVertex2f(p[i].x,p[i].y);
	glEnd();
}

void gradatePolygon(point2D_t p[],color_t col[],int n){
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++) {
		glColor3f(col[i].r,col[i].g,col[i].b);
		glVertex2f(p[i].x,p[i].y);
	}
	glEnd();
}

void fillPolygon(point2D_t p[],color_t col, int n){
	setColor(col);
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++) glVertex2f(p[i].x,p[i].y);
	glEnd();
}

void drawPolyline(point2D_t p[],int n){
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<n;i++) glVertex2f(p[i].x,p[i].y);
	glEnd();
}

static void createCircle(point2D_t p[],float r){
	for(int i=0;i<360;i++){
		p[i].x=r*cos(i/57.3);
		p[i].y=r*sin(i/57.3);
	}
}

static void createCircle(point2D_t p[],float r[]){
	for(int i=0;i<360;i++){
		p[i].x=r[i]*cos(i/57.3);
		p[i].y=r[i]*sin(i/57.3);
	}
}

//////////////////////////////////////////////////////////////////
void drawcharX(float x,float y)
{
	drawLine(x,y,x+10,y+12);
	drawLine(x,y+12,x+10,y);
}

void drawcharY(float x,float y)
{
	drawLine(x+5,y,x+5,y+7);
	drawLine(x,y+12,x+5,y+7);
	drawLine(x+10,y+12,x+5,y+7);
}

void drawcharZ(float x,float y)
{
	drawLine(x,y+12,x+10,y+12);
	drawLine(x+10,y+12,x,y);
	drawLine(x,y,x+10,y);
}

void drawAxes(matrix3D_t view)
{
#define HALFAXIS  220
#define HALFAXIS1 (HALFAXIS-10)
	point3D_t axes[14]={
	{-HALFAXIS,0,0},{HALFAXIS,0,0},{HALFAXIS1,5,0},{HALFAXIS1,0,0},{0,0,0},
	{0,-HALFAXIS,0},{0,HALFAXIS,0},{0,HALFAXIS1,5},{0,HALFAXIS1,0},{0,0,0},
	{0,0,-HALFAXIS},{0,0,HALFAXIS1},{5,0,HALFAXIS1},{0,0,HALFAXIS1}
	};
	vector3D_t vec[14];
	point2D_t buff[14];
	int i;
	for (i=0;i<14;i++) {
		vec[i]=point2vector(axes[i]);
		vec[i]=view*vec[i];
		buff[i]=vector2point2D(vec[i]);
	}
	drawPolyline(buff,14);
	drawcharX(buff[1].x,buff[1].y);
	drawcharY(buff[6].x,buff[6].y);
	drawcharZ(buff[11].x-14,buff[11].y);
}

typedef struct {
	int NumberofVertices;
	int pnt[32];
	color_t colface;
} face_t;

typedef struct{
	int NumberofVertices;
	point3D_t pnt[100];
	int NumberofFaces;
	face_t fc[50];
} object3D_t;

void drawObject3D(object3D_t obyek, matrix3D_t mat){
	vector3D_t vec[100],vec1[32],vecNormal;
	point2D_t p[100];
	int i,j;
	for(i=0;i<obyek.NumberofVertices;i++){
		vec[i]=point2vector(obyek.pnt[i]);
		vec[i]=mat*vec[i];
	}
	//sisi visible
	for(i=0;i<obyek.NumberofFaces;i++){
		for(j=0;j<obyek.fc[i].NumberofVertices;j++){
			vec1[j]=vec[obyek.fc[i].pnt[j]];
			p[j]=vector2point2D(vec1[j]);
		}
		vecNormal=(vec1[1]-vec1[0])^(vec1[2]-vec1[0]);
		if(vecNormal.v[2]>0){
			fillPolygon(p,obyek.fc[i].colface,obyek.fc[i].NumberofVertices);
			setColor(1,1,1);
			drawPolygon(p,obyek.fc[i].NumberofVertices);
		}
	}
}

void userdraw() {
	static float tick=0;
	matrix3D_t tilting=rotationYMTX(0.25)*rotationXMTX(-0.5);
	setColor(0,1,0);
	drawAxes(tilting);

	//setColor(1,1,1);
	object3D_t kubus={8,
	{{100,100,100},{100,100,-100},{-100,100,-100},{-100,100,100},{100,-100,100},{100,-100,-100},{-100,-100,-100},{-100,-100,100}},
	6,
	{{4,{0,1,2,3},{1,0,0}},{4,{4,7,6,5},{1,0,0}},{4,{0,4,5,1},{1,1,0}},{4,{3,2,6,7},{1,1,0}},{4,{0,3,7,4},{1,0,1}},{4,{1,5,6,2},{1,0,1}}}};
	matrix3D_t mat;

	mat=tilting*rotationYMTX(tick)*translationMTX(200,0,0)*scalingMTX(0.5,0.5,0.5);
	drawObject3D(kubus,mat);

	mat=tilting*rotationYMTX(tick)*scalingMTX(0.5,0.5,0.5);
	drawObject3D(kubus,mat);

	tick+=0.01;
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main (int argc, char ** argv) {
    // insert code here...
    glutInit(&argc,argv); //inisialisasi toolkit
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Komposisi Transformasi Kubus 4");
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(-400.,400.,-400.,400.);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
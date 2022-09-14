#include <stdio.h>
#include <GL/glut.h>

float red=1,green=1,blue=1;



void init (void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,200.0);
}


void process_SHIFT_ALT_CTRL(unsigned char key, int x, int y) 
{
    // Press ALT or  SHIFT or  CTRL in combination with other keys.
    printf("key_code =%d  \n",key);

    int mod = glutGetModifiers();

    if (mod != 0) //ALT=4  SHIFT=1  CTRL=2
    {      
          switch(mod)
          {
             case 1 :  printf("SHIFT key %d\n",mod);  break;
             case 2 :  printf("CTRL  key %d\n",mod);  break;
             case 4 :  printf("ALT   key %d\n",mod);  break;
             mod=0;
          }
    }
}


void process_Normal_Keys(int key, int x, int y) 
{
     switch (key) 
    {    
       case 27 :      break;
       case 100 : printf("GLUT_KEY_LEFT %d\n",key);   break;
       case 102: printf("GLUT_KEY_RIGHT %d\n",key);  ;  break;
       case 101   : printf("GLUT_KEY_UP %d\n",key);  ;  break;
       case 103 : printf("GLUT_KEY_DOWN %d\n",key);  ;  break;
    }

}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glFlush();
}


int main(int argc, char **argv)
{

    printf("Press ALT or  SHIFT or  CTRL in combination with other keys. \n\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(800,20);
    glutInitWindowSize(400, 300);
    glutCreateWindow("A simple example");
    init();

    // famous GLUT callback functions

    glutDisplayFunc(display);


    glutSpecialFunc( process_Normal_Keys );
    glutKeyboardFunc( process_SHIFT_ALT_CTRL );  


    glutMainLoop();

return 0;
}
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;



float scale = 1.0f;

float x=0.8f;
float y=1.0f;
float z =0.0f;
float _angle = 45.0f;
float _cameraAngle = 0.0f;



/***************************************************************************************/
void initRendering() ;
void handleResize(int w, int h);
void drawScene() ;
void update();
void handleKeypress(unsigned char key, int x, int y) ;
/***************************************************************************************/



void initRendering() {
    glEnable(GL_DEPTH_TEST);
}


void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double) w / (double) h, 1.0, 200.0);
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glScalef(scale,scale,scale);

    glPopMatrix();
    glPushMatrix();

    

    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(x,y,z);
    glScalef(scale,scale,scale);


    glColor3f(1.0, 0.25, 1.0);
    glColor3f (.5, 0.5, .25);

    /* main rec */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (.5, .75, .35);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*back rec*/
    glColor3f (.5, .75, .35);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* left rec */
    glColor3f (.75, 0.75, .25);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* right rec */
    glColor3f (.75, 0.75, .25);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glEnd();

    /* left tri */
    glColor3f (.5, 0.5, .25);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    /* right tri */
    glColor3f (.5, 0.5, .25);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* roof */
    glColor3f (.55, 0.35, .2);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*back roof */
    glColor3f (.55, 0.35, .2);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* door */
    glColor3f (.15, 0.2, .3);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, 0.0);
    glVertex3f (0.65, 0.105, 0.0);
    glVertex3f (0.65, 0.46, 0.0);
    glVertex3f (0.47, 0.46, 0.0);
    glEnd();

    /* window 1 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25, 0.0);
    glVertex3f (0.83, 0.25, 0.0);
    glVertex3f (0.83, 0.4, 0.0);
    glVertex3f (0.72, 0.4, 0.0);
    glEnd();

    /* window 2 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25, 0.0);
    glVertex3f (0.38, 0.25, 0.0);
    glVertex3f (0.38, 0.4, 0.0);
    glVertex3f (0.27, 0.4, 0.0);
    glEnd();


    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
   
}
void update() {
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    
}


void handleKeypress(unsigned char key, int a, int b) {
   if (key == 27)
        exit(0);
    else if (key=='r') {
        cout<<"Rotate"<<endl;

         update();
    }
    else if (key=='q') {
        cout<<"scale ---"<<endl;
        scale=scale-0.1f;
         glutPostRedisplay();

    }
    else if (key=='e') {
        cout<<"scale +++"<<endl;
       scale=scale+0.1f;
         glutPostRedisplay();
    }
    else if (key=='w') {
        cout<<"y ekseni +++"<<endl;
        y=y+ 0.1f;;
       glutPostRedisplay();
    }
   
    else if (key=='s') {
        cout<<"y ekseni ---"<<endl;
         y-= 0.1f;
         glutPostRedisplay();
    }

     else if (key=='f') {
        cout<<"z ekseni ---"<<endl;
        z-= 0.1f;;
        glutPostRedisplay();
        
    }
    
    else if (key=='g') {
        cout<<"z ekseni +++"<<endl;
         z+= 0.1f;
         glutPostRedisplay();
    }

     else if (key=='a') {
        cout<<"x ekseni ---"<<endl;
        x-= 0.1f;;
        glutPostRedisplay();
        
    }
    
    else if (key=='d') {
        cout<<"x ekseni +++"<<endl;
         x+= 0.1f;
         glutPostRedisplay();
    }
  
}
int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("151044025");
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
   
    glutMainLoop();
    return 0;
}
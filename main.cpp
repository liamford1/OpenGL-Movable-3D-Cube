/*
 *  Hello World Triangle Version 1
 */
#include <GLUT/glut.h>
#include <cstdlib>
/*
 * This function is called by GLUT to display the scene
 */

float x_theta = 0;
float y_theta = 0;
float z_theta = -5.0f;
float x_rotation = 0.0f;
float y_rotation = 0.0f;
int last_x, last_y;

bool keyStates[256] = {false}; 

void display(void) //
{
   //  Clear screen
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glLoadIdentity(); 
   glTranslatef(x_theta, y_theta, z_theta);
   glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);
   glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);

   //  Draw triangle
   glBegin(GL_QUADS);
    // Front face
    glColor3f(1, 0, 0); // Red
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);

    // Back face
    glColor3f(0, 1, 0); // Green
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);

    // Top face
    glColor3f(0, 0, 1); // Blue
    glVertex3f(-0.5,  0.5, -0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5, -0.5);

    // Bottom face
    glColor3f(1, 1, 0); // Yellow
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f(-0.5, -0.5,  0.5);

    // Right face
    glColor3f(1, 0, 1); // Magenta
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);

    // Left face
    glColor3f(0, 1, 1); // Cyan
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glEnd();
   //  Make scene visible
    glFlush();
    glutSwapBuffers();
}

void mouseMotion(int x, int y) {
    int dx = x - last_x;
    int dy = y - last_y;

    x_rotation += dy * 0.5f;
    y_rotation += dx * 0.5f;

    last_x = x;
    last_y = y;

    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        last_x = x;
        last_y = y;
    }
}

void specialKeys(int key, int, int) {
    if (key == GLUT_KEY_RIGHT) {
        x_theta += .1f;
    }
    else if (key == GLUT_KEY_LEFT) {
        x_theta -= .1f;
    }
    else if (key == GLUT_KEY_UP) {
        y_theta += .1f;
    }
    else if (key == GLUT_KEY_DOWN) {
        y_theta -= .1f;
    }
    glutPostRedisplay();
}

void update() {
    if (keyStates['w']) y_theta += 0.01f;
    if (keyStates['s']) y_theta -= 0.01f;
    if (keyStates['a']) x_theta -= 0.01f; 
    if (keyStates['d']) x_theta += 0.01f;
    if (keyStates['e']) z_theta += 0.01f;
    if (keyStates['r']) z_theta -= 0.01f;
    glutPostRedisplay(); 
}

void keyPress(unsigned char key, int, int) {
    keyStates[key] = true; 
    if (key == 27) exit(0); 
}


void keyRelease(unsigned char key, int, int) {
    keyStates[key] = false; 
}

/*
 * GLUT based Hello World
 */
int main(int argc,char* argv[])
{
   //  Initialize GLUT
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   //  Create window
   glutCreateWindow("Hello World");
   //  Register function used to display scene

   glEnable(GL_DEPTH_TEST);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, 1.0, 1.0, 10.0);
   glMatrixMode(GL_MODELVIEW);

   glutDisplayFunc(&display);
   glutMouseFunc(&mouseClick);
   glutMotionFunc(&mouseMotion);
   glutIdleFunc(&update);
   glutSpecialFunc(&specialKeys);
   glutKeyboardFunc(&keyPress);
   glutKeyboardUpFunc(&keyRelease);
   //  Pass control to GLUT for events
   //glEnable(GL_DEPTH_TEST);
   glutMainLoop();
   //  Return to OS
   return 0;
}
#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>
#else
#include <GLUT/GLUT.h>
#endif

void reshape(int w, int h);
void display();
int main (int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL laba");
       
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
       
    glutMainLoop();
 
    return 0;
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
       
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
       
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0, 1000);
    glVertex2i(0, 0);
    glVertex2i(1000, 0);
    glVertex2i(1000, 1000);
    glEnd();
	
	for(int i=0;i<10;i++){
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2i(250, 450-(25*i));
		glVertex2i(550, 450-(25*i));
		glEnd();
       }

    glutSwapBuffers();
}

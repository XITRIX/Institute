#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>
#else
#include <GLUT/GLUT.h>
#endif

void counter();
void reshape(int w, int h);
void display();
int arg[6], he;
int main (int argc, char * argv[])
{
	for(int i=1;i<argc;i++){
		arg[i]=atoi(argv[i]);	
	}
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(atoi(argv[1]), atoi(argv[2]));
    glutCreateWindow("OpenGL laba");
       
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
       
    glutMainLoop();
 
    return 0;
}

void reshape(int w, int h)
{
	arg[1]=w;
	arg[2]=h;
	he=arg[2]/(arg[3]+1);

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
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(0, arg[2]);
    glVertex2i(0, 0);
    glVertex2i(arg[1], 0);
    glVertex2i(arg[1], arg[2]);
    glEnd();
	
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0+2, arg[2]-2);
    glVertex2i(0+2, 0+2);
    glVertex2i(arg[1]-2, 0+2);
    glVertex2i(arg[1]-2, arg[2]-2);
    glEnd();
	
	for(int i=0;i<arg[3];i++){
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2i((arg[1]/2)-(arg[4]/2), he+(he*i));
		glVertex2i((arg[1]/2)+(arg[4]/2), he+(he*i));
		glEnd();
       }

    glutSwapBuffers();
}

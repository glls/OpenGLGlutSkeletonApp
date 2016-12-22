#include <GL/freeglut.h>

void display()
{
	// set clear color (rgba - white)
	glClearColor(1, 1, 1, 0);
	// clear frame buffer
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00AA);

	// red line strip
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(5, 45);
	glVertex2i(45, 45);
	glVertex2i(45, 5);
	glVertex2i(5, 5);
	glVertex2i(25, 25);
	glVertex2i(5, 45);
	glVertex2i(0, 0);
	glEnd();

	// blue rectangle
	glColor3f(0, 0, 1);
	glRecti(35, 25, 49, 35);

	//green quad
	glColor3f(0.2f, .8f, 0.2f);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(5.0, 30.0);
	glVertex2f(30.0, 5.0);	
	glVertex2f(5.0, 5.0);
	glVertex2f(30.0, 30.0);
	glEnd();

	// render
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	// set window position
	glutInitWindowPosition(50, 50);
	// set window size
	glutInitWindowSize(640, 480);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// create window and set title
	glutCreateWindow("A sample OpenGL application");

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 50.0, 0, 50.0);

	// set callback function
	glutDisplayFunc(display);

	// start event processing loop
	glutMainLoop();

	return 0;
}

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265

int gdepth = 15;
int keys[255] = {0};
float scale = 1;
float w = 800;
float h = 800;
GLint wdGUI;

void putv(float x, float y, float z)
{
	float xf = x - (w/2);
	float yf = y - (h/2);
	float zf = z - (h/2);
	glVertex3f(xf/w*2.0f, yf/h*2.0f, zf/h*2.0f);
}

float rot = 5000.0;
void frac1(int depth, float x, float y, float r, float l)
{
	float i;
	i = 350.0;

	rot = r;
	while (i > 0.0)
	{
	glBegin(GL_POINTS);
		glColor4f(r, 1.0-i/300.0, i/300.0, 0.5f);

		putv(y + i *sin(cos(rot/0.02) + r)*sin(rot/0.1),
			x + i *cos(sin(rot/0.02) + r)*cos(rot/0.1),
			x + i *cos(sin(rot/0.02) + r)*cos(rot/0.1)
		);
		/*
		putv(y - i *sin(cos(rot/0.02) + r)*sin(rot/0.1),
			x + i *cos(sin(rot/0.02) + r)*cos(rot/0.1));
		putv(y + i *sin(cos(rot/0.02) + r)*sin(rot/0.1),
			x - i *cos(sin(rot/0.02) + r)*cos(rot/0.1));	
		putv(y - i *sin(cos(rot/0.02) + r)*sin(rot/0.1),
			x - i *cos(sin(rot/0.02) + r)*cos(rot/0.1));
		*/
		
		i -= 0.1;
		rot += 0.001;
	glEnd();
	}
}

float divi = 2.0;
float vel = 0.001;
float color = 0.1;
float l = 0.4;

// GUI CALLBACK FUNCTIONS
void display()
{


	divi += vel;
	//if (222222222222 % (int)divi == 0)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//frac1(10, w/2.0f, h/2.0f, 222222222222.0/sin(tan(0.000001*divi)), l);
		frac1(10, w/2.0f, h/2.0f, l, l);
		l += vel;
	//usleep(50000);
	glutSwapBuffers();
	glFlush();
}

void keysdown(unsigned char key, int x, int y) {
	keys[(int)key] = 1;
}

void keysup(unsigned char key, int x, int y) {
	keys[(int)key] = 0;
}

void mouse(int button, int state, int x, int y) {

}

int main(int argc, char *argv[])
{
	// Initial GLUT init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize((scale * w) - 1, (scale * h) - 1);
	wdGUI = glutCreateWindow("GUI");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keysdown);
	glutKeyboardUpFunc(keysup);
	glPointSize(scale * 5.0f);
	glLineWidth(scale * 0.2f);
	glEnable(GL_POINT_SMOOTH);
	//glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glDepthMask(GL_FALSE);
	//glHint(GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_MULTISAMPLE);
	glDisable(GL_DEPTH_TEST);
	glutMainLoop();

	glutDestroyWindow(wdGUI);

	return 0;
}

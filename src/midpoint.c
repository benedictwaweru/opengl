#include <GL/glut.h>
#include <stdio.h>

// Set pixel at (x, y)
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

// Midpoint circle drawing algorithm
void midpoint_circle(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 1 - r;

	while (x <= y) {
		plot(xc + x, yc + y);
		plot(xc - x, yc + y);
		plot(xc + x, yc - y);
		plot(xc - x, yc - y);
		plot(xc + y, yc + x);
		plot(xc - y, yc + x);
		plot(xc + y, yc - x);
		plot(xc - y, yc - x);

		if (d < 0) {
			d += 2 * x + 3;
		} else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	midpoint_circle(0, 0, 50);      // Example circle
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Midpoint Algorithms");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

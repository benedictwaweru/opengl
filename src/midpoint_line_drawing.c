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

// Midpoint line drawing algorithm
void midpoint_line(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = 2 * dy - dx;
	int y = y0;

	for (int x = x0; x <= x1; x++) {
		plot(x, y);
		if (d > 0) {
			y++;
			d += 2 * (dy - dx);
		} else {
			d += 2 * dy;
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	midpoint_line(-50, 0, 50, 50);  // Example line
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

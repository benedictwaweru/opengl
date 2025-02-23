#include <GL/glut.h>
#include <math.h>

void plot(int x, int y)
{
	glColor3f(1.0f, 1.0f, 1.0f); // Solid white color
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void bresenham_line(int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;

	while (1) {
		plot(x0, y0); // Draw the current pixel
		if (x0 == x1 && y0 == y1) break; // Exit loop at endpoint

		int e2 = 2 * error;
		if (e2 >= dy) { // Step in x-direction
			if (x0 == x1) break;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx) { // Step in y-direction
			if (y0 == y1) break;
			error += dx;
			y0 += sy;
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluOrtho2D(0, w, 0, h); // Match OpenGL coordinates to window size

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw a line from (100, 150) to (500, 400)
	bresenham_line(100, 150, 500, 400);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bresenham's Line Algorithm");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

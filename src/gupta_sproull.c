#include <GL/glut.h>
#include <math.h>

void plot(int x, int y, float intensity)
{
	glColor4f(1.0f, 1.0f, 1.0f, intensity);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void gupta_sproull_line(float x0, float y0, float x1, float y1)
{
	// Line equation: ax + by + c = 0
	float dx = x1 - x0;
	float dy = y1 - y0;
	float a = dy;
	float b = -dx;
	float c = dx * y0 - dy * x0;

	float denominator = sqrt(a * a + b * b);
	if (denominator == 0) return; // Avoid division by zero for zero-length lines

	// Anti-aliasing filter radius (adjust for thicker/thinner lines)
	float radius = 1.0f;

	// Bounding box expanded by filter radius
	int x_min = (int)(fmin(x0, x1) - radius);
	int x_max = (int)(fmax(x0, x1) + radius);
	int y_min = (int)(fmin(y0, y1) - radius);
	int y_max = (int)(fmax(y0, y1) + radius);

	// Iterate over pixels in the bounding box
	for (int x = x_min; x <= x_max; x++) {
		for (int y = y_min; y <= y_max; y++) {
			// Pixel center coordinates
			float px = x + 0.5f;
			float py = y + 0.5f;

			// Perpendicular distance from pixel center to the line
			float distance = fabs(a * px + b * py + c) / denominator;

			if (distance <= radius) {
				// Cone filter: intensity decreases linearly with distance
				float intensity = 1.0f - (distance / radius);
				plot(x, y, intensity);
			}
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
	gluOrtho2D(0, w, 0, h); // Set coordinate system to match window size

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw an anti-aliased line using Gupta-Sproull
	gupta_sproull_line(100.0f, 150.5f, 500.0f, 400.5f);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Gupta-Sproull Line Algorithm");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Enable alpha blending

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

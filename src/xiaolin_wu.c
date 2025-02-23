#include <GL/glut.h>
#include <math.h>

void swap(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

int ipart(float x)
{
	return (int)floor(x);
}

float fpart(float x)
{
	return x - floor(x);
}

float rfpart(float x)
{
	return 1 - fpart(x);
}

void plot(int x, int y, float intensity)
{
	glColor4f(1.0f, 1.0f, 1.0f, intensity);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void wu_draw_line(float x0, float y0, float x1, float y1)
{
	int steep = fabs(y1 - y0) > fabs(x1 - x0);

	if (steep) {
		swap(&x0, &y0);
		swap(&x1, &y1);
	}

	if (x0 > x1) {
		swap(&x0, &x1);
		swap(&y0, &y1);
	}

	float dx = x1 - x0;
	float dy = y1 - y0;
	float gradient = (dx == 0) ? 0 : dy / dx;

	// First endpoint
	float xend = roundf(x0);
	float yend = y0 + gradient * (xend - x0);
	float xgap = rfpart(x0 + 0.5f);
	int xpxl1 = (int)xend;
	int ypxl1 = ipart(yend);

	if (steep) {
		plot(ypxl1, xpxl1, rfpart(yend) * xgap);
		plot(ypxl1 + 1, xpxl1, fpart(yend) * xgap);
	} else {
		plot(xpxl1, ypxl1, rfpart(yend) * xgap);
		plot(xpxl1, ypxl1 + 1, fpart(yend) * xgap);
	}

	float intery = yend + gradient;

	// Second endpoint
	xend = roundf(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart(x1 + 0.5f);
	int xpxl2 = (int)xend;
	int ypxl2 = ipart(yend);

	if (steep) {
		plot(ypxl2, xpxl2, rfpart(yend) * xgap);
		plot(ypxl2 + 1, xpxl2, fpart(yend) * xgap);
	} else {
		plot(xpxl2, ypxl2, rfpart(yend) * xgap);
		plot(xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}

	// Main loop
	if (steep) {
		for (int x = xpxl1 + 1; x < xpxl2; x++) {
			plot(ipart(intery), x, rfpart(intery));
			plot(ipart(intery) + 1, x, fpart(intery));
			intery += gradient;
		}
	} else {
		for (int x = xpxl1 + 1; x < xpxl2; x++) {
			plot(x, ipart(intery), rfpart(intery));
			plot(x, ipart(intery) + 1, fpart(intery));
			intery += gradient;
		}
	}
}

/* void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int window_width = glutGet(GLUT_WINDOW_WIDTH);
	int window_height = glutGet(GLUT_WINDOW_HEIGHT);
	gluOrtho2D(0, window_width, 0, window_height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw an example anti-aliased line
	wu_draw_line(100.0f, 150.5f, 500.0f, 400.5f);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Xiaolin Wu's Line Algorithm");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
 */

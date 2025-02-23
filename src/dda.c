void drawLineDDA(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xIncrement = dx / (float)steps;
	float yIncrement = dy / (float)steps;

	float x = x0;
	float y = y0;
	for (int i = 0; i <= steps; i++) {
		setPixel(round(x), round(y));
		x += xIncrement;
		y += yIncrement;
	}
}

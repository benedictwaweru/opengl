#ifndef XIAOLIN_WU_H
#define XIAOLIN_WU_H

#include <GL/glut.h>
#include <math.h>

/**
 * Function to swap two float values
 */
void swap(float* a, float* b);

/**
 * Functions for integer and fractional parts of a float
 */
int ipart(float x);
float fpart(float x);
float rfpart(float x);

/**
 * Function to plot a pixel with given intensity
 */
void plot(int x, int y, float intensity);

/**
 * Function to draw an anti-aliased line using Xiaolin Wu's algorithm
 */
void wu_draw_line(float x0, float y0, float x1, float y1);

#endif

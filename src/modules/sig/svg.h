#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include <stdbool.h>
#include "circle.h"
#include "rectangle.h"
#include "block.h"
#include "equipment.h"
#include "building.h"
#include "wall.h"

#define STROKE_WIDTH "1"
#define WALL_STROKE_WIDTH "3"
#define TEXT_FILL_COLOR "white"
#define TEXT_EXTRA "font-family=\"Arial\" style=\"stroke:#000;stroke-width:0.2px;\""
#define POINT_RADIUS 2.0
#define HYDRANT_RADIUS 5.0
#define POLY_OPACITY 0.6
#define HIGHLIGHT_CSTROKE "gold"
#define HIGHLIGHT_WSTROKE "2"
#define HIGHLIGHT_CFILL "yellow"
#define TEXT_CENTER "dominant-baseline=\"middle\" text-anchor=\"middle\""

void putSVGStart(FILE *file);

void putSVGQueryStart(FILE *file);

void putSVGQueryEnd(FILE *file);

void putSVGUseQuery(FILE *file);

void putSVGCircle(FILE *file, Circle circ, char color1[], char color2[], char stroke[]);

void putSVGRectangle(FILE *file, Rectangle rect, char color1[], char color2[], char stroke[]);

void putSVGEllipse(FILE *file, double cx, double cy, double rx, double ry, char color1[], char color2[]);

void putSVGText(FILE *file, double x, double y, char text[]);

void putSVGPoint(FILE *file, double x, double y, bool inside);

void putSVGBox(FILE *file, double x, double y, double width, double height, bool gaps);

void putSVGLine(FILE *file, double x1, double y1, double x2, double y2);

void putSVGBlock(Block b, void *file);

void putSVGHydrant(Equip h, void *file);

void putSVGTrafficLight(Equip t, void *file);

void putSVGCellTower(Equip c, void *file);

void putSVGBuilding(Building b, void *file);

void putSVGWall(Wall w, void *file);

void putSVGSegment(FILE *file, double x1, double y1, double x2, double y2);

void putSVGTriangle(FILE *file, double x1, double y1, double x2, double y2, double x3, double y3);

void putSVGBomb(FILE *file, double x, double y);

void putSVGEnd(FILE *file);

#endif
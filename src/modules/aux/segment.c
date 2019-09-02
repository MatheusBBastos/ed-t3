#include "segment.h"

typedef struct segment_t {
    Point pStart;
    Point pEnd;
    double xBiombo;
    double yBiombo;
} *SegmentPtr;

Segment Segment_Create(Point pStart, Point pEnd) {
    SegmentPtr segment = malloc(sizeof(struct segment_t));
    segment->pStart = pStart;
    segment->pEnd = pEnd;
    segment->xBiombo = Point_GetX(pStart);
    segment->yBiombo = Point_GetY(pStart);
    return segment;
}

Segment Segment_CreateFromCoords(double x1, double y1, double x2, double y2, double x, double y) {
    SegmentPtr segment = malloc(sizeof(struct segment_t));
    double angle1 = calculateAngle(y1 - y, x1 - x);
    double angle2 = calculateAngle(y2 - y, x2 - x);
    double distance1 = euclideanDistance(x1, y1, x, y);
    double distance2 = euclideanDistance(x2, y2, x, y);
    Point p1 = Point_Create(x1, y1, segment, angle1, distance1);
    Point p2 = Point_Create(x2, y2, segment, angle2, distance2);
    if (angle1 > angle2) {
        segment->pStart = p2;
        Point_SetStarting(p2, true);
        segment->pEnd = p1;
        Point_SetStarting(p1, false);
    } else {
        segment->pStart = p1;
        Point_SetStarting(p1, true);
        segment->pEnd = p2;
        Point_SetStarting(p2, false);
    }
    segment->xBiombo = Point_GetX(segment->pStart);
    segment->yBiombo = Point_GetY(segment->pStart);
    return segment;
}

double Segment_CheckXIntersection(Segment segmentVoid, double y) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    Point p1 = segment->pStart;
    Point p2 = segment->pEnd;

    if (Point_GetX(p1) == Point_GetX(p2)) {
        if (y >= min(Point_GetY(p1), Point_GetY(p2)) && y <= max(Point_GetY(p1), Point_GetY(p2)))
            return Point_GetX(p1);
        else
            return -1;
    }

    double a = (Point_GetY(p1) - Point_GetY(p2))/(Point_GetX(p1) - Point_GetX(p2));
    double b = Point_GetY(p1) - a * Point_GetX(p1);

    return (y - b)/a;
}

Point Segment_GetPStart(Segment segmentVoid) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    return segment->pStart;
}

Point Segment_GetPEnd(Segment segmentVoid) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    return segment->pEnd;
}

double Segment_GetXBiombo(Segment segmentVoid) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    return segment->xBiombo;
}

double Segment_GetYBiombo(Segment segmentVoid) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    return segment->yBiombo;
}

void Segment_SetPStart(Segment segmentVoid, Point pStart) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    segment->pStart = pStart;
    segment->xBiombo = Point_GetX(pStart);
    segment->yBiombo = Point_GetY(pStart);
}

void Segment_SetPEnd(Segment segmentVoid, Point pEnd) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    segment->pEnd = pEnd;
}

void Segment_SetXBiombo(Segment segmentVoid, double xBiombo) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    segment->xBiombo = xBiombo;
}

void Segment_SetYBiombo(Segment segmentVoid, double yBiombo) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    segment->yBiombo = yBiombo;
}

void Segment_Destroy(Segment segmentVoid) {
    SegmentPtr segment = (SegmentPtr) segmentVoid;
    Point_Destroy(segment->pStart);
    Point_Destroy(segment->pEnd);
    free(segment);
}

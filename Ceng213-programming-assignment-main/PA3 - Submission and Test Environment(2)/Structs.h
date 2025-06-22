#pragma once

#include <cmath>

struct IdPair
{
    int vertexId0;
    int vertexId1;
};

struct Double3
{
    double x, y, z;

    static double Distance(Double3 left, Double3 right);
};

inline
double Double3::Distance(Double3 left, Double3 right)
{
    //TODO:
    double distance1 = left.x - right.x;
    double distance2 = left.y - right.y;
    double distance3 = left.z - right.z;
    return std::sqrt(distance1*distance1+distance2*distance2+distance3*distance3);
}
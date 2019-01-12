//
// Created by st0rmbring3r on 12/1/19.
//

#ifndef PHYSICS_VEC3_H
#define PHYSICS_VEC3_H

#include <cmath>

class vec3 {
public:
    double x, y, z;

    vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    double mag();

    vec3 operator*(double k);

    vec3 operator/(double k);

    vec3 operator*(vec3 v2);

    vec3 operator+(vec3 v2);

    vec3 operator-(vec3 v2);

    vec3 unit();

    friend vec3 operator*(double k, vec3 v);
};

double dot(vec3 v1, vec3 v2);

#endif //PHYSICS_VEC3_H

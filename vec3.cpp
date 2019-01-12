//
// Created by st0rmbring3r on 12/1/19.
//

#include "vec3.h"

double vec3::mag() {
    return sqrt(x * x + y * y + z * z);
}

vec3 vec3::operator*(double k) {
    return vec3(k * x, k * y, k * z);
}

vec3 operator*(double k, vec3 v) {
    return v * k;
}

vec3 vec3::operator/(double k) {
    return (*this) * (1 / k);
}

vec3 vec3::operator*(vec3 v2) {
    return vec3(y * v2.z - z * v2.y,
                z * v2.x - x * v2.z,
                x * v2.y - y * v2.x);
}

vec3 vec3::operator+(vec3 v2) {
    return vec3(x + v2.x, y + v2.y, z + v2.z);
}

vec3 vec3::operator-(vec3 v2) {
    return vec3(x - v2.x, y - v2.y, z - v2.z);
}

vec3 vec3::unit() {
    double m = mag();
    return vec3(x / m, y / m, z / m);
}

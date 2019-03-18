#include "math3d.h"
#include <cmath>
#include <string>
#include <sstream>

double eps = 1e-7;

vec3d::vec3d() : x(0), y(0), z(0) {}

vec3d::vec3d(db x, db y, db z) : x(x), y(y), z(z) {}

db vec3d::mag()
{
    return sqrt(x * x + y * y + z * z);
}

vec3d vec3d::operator+(vec3d v2)
{
    return vec3d(x + v2.x, y + v2.y, z + v2.z);
}

vec3d vec3d::operator-(vec3d v2)
{
    return vec3d(x - v2.x, y - v2.y, z - v2.z);
}

vec3d vec3d::operator*(db k)
{
    return vec3d(x * k, y * k, z * k);
}

vec3d vec3d::operator/(db k)
{
    return vec3d(x / k, y / k, z / k);
}

vec3d operator*(db k, vec3d v){
    return vec3d(v.x * k, v.y * k, v.z * k);
}

vec3d operator/(db k, vec3d v){
    return vec3d(v.x / k, v.y / k, v.z / k);
}

void vec3d::operator+=(vec3d v2)
{
    x += v2.x;
    y += v2.y;
    z += v2.z;
}

void vec3d::operator-=(vec3d v2)
{
    x -= v2.x;
    y -= v2.y;
    z -= v2.z;
}

void vec3d::operator*=(db k)
{
    x *= k;
    y *= k;
    z *= k;
}

void vec3d::operator/=(db k)
{
    x /= k;
    y /= k;
    z /= k;
}

db vec3d::operator*(vec3d v2)
{
    return x * v2.x + y * v2.y + z * v2.z;
}

vec3d vec3d::cross(vec3d v2)
{
    return vec3d(y * v2.z - z * v2.y,
                 z * v2.x - x * v2.z,
                 x * v2.y - y * v2.x);
}

void vec3d::normalise()
{
    (*this) /= mag();
}

vec3d vec3d::unit()
{
    vec3d newvec = (*this);
    newvec.normalise();
    return newvec;
}

bool vec3d::operator==(vec3d v2)
{
    return (((*this) - v2).mag() < eps);
}

std::ostream &operator<<(std::ostream &out, vec3d v)
{
    return (out << "vec3d<" << v.x << ", " << v.y << ", " << v.z << ">");
}

std::string vec3d::toJson()
{
    std::ostringstream os;
    os << "[" << x << "," << y << "," << z << "]";
    return os.str();
}
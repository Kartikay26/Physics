#ifndef MATH3D_H
#define MATH3D_H

#include <string>

typedef double db;

class vec3d
{
  private:
    double x, y, z;

  public:
    vec3d();
    vec3d(db x, db y, db z);
    db mag();
    vec3d operator+(vec3d other);
    vec3d operator-(vec3d other);
    vec3d operator*(db scale);
    vec3d operator/(db scale);
    friend vec3d operator*(db scale, vec3d v);
    friend vec3d operator/(db scale, vec3d v);
    void operator+=(vec3d other);
    void operator-=(vec3d other);
    void operator*=(db scale);
    void operator/=(db scale);
    db operator*(vec3d other);
    bool operator==(vec3d other);
    vec3d cross(vec3d other);
    vec3d unit();
    void normalise();
    friend std::ostream& operator<< (std::ostream& out, vec3d v);
    std::string toJson();
};

#endif
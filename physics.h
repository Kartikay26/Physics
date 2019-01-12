#ifndef PHYSICS_LIBRARY_H
#define PHYSICS_LIBRARY_H

#include "vec3.h"
#include <iostream>
#include <vector>

using std::vector, std::ostream;

class Universe;

class Object;

class Force;

class Universe {
    vector<Force *> forces;
    vector<Object *> objects;
public:
    double time = 0.000;
    double timestep = 0.001;

    void addObject(Object *o);

    void addForce(Force *f);

    void step();

    vec3 getForce(Object &p);
};

class Object {
public:
    Universe *univ = nullptr;

    friend void Universe::addObject(Object *);

    virtual ostream &operator<<(ostream &) = 0;
};

class Force {
public:
    virtual vec3 calculateFor(Object &o) = 0;
};

class Particle : public Object {
public:
    vec3 pos;

    Particle(vec3 pos, vec3 vel, double mass);

    ostream &operator<<(ostream &) override;

    double mass;
    vec3 vel;
};

class GravityForce : public Force {
    vec3 calculateFor(Object &o) override;
};

#endif

#ifndef PHYSICS_H
#define PHYSICS_H

#include <string>
#include <vector>

#include "math3d.h"

class Universe;
class Particle;
class Force;
class Spring;

class Universe
{
  private:
    std::vector<Force *> forces;
    std::vector<Particle *> particles;
    std::vector<Spring *> springs;

  public:
    db time = 0;
    int steps = 0;
    db dt;
    Universe(db timestep = 1e-3);
    void add(Force *f);
    void add(Particle *p);
    void add(Spring *s);
    void step();
    std::string info();
    vec3d total_force(Particle *p);
    std::string toJson();
};

class Particle
{
    friend class Universe;
  private:
    vec3d _new_pos, _new_vel;
  public:
    db mass;
    vec3d pos;
    vec3d vel;
    Particle(vec3d pos, vec3d vel = vec3d(0, 0, 0), db mass = 1);
    std::string toJson();
};

class Force
{
  public:
    virtual vec3d get_force(Particle *p) = 0;
};

class GravityForce : public Force
{
  public:
    vec3d g;
    GravityForce(vec3d g = vec3d(0, 0, -1));
    vec3d get_force(Particle *p) override;
};

#endif
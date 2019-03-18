#include "physics.h"
#include <sstream>

// ============================================================

// CORE ALGORITHM

void Universe::step()
{
    for (Particle *p : particles)
    {
        vec3d acc = total_force(p) / p->mass;
        p->_new_pos = p->pos + dt * p->vel;
        p->_new_vel = p->vel + dt * acc;
    }
    for (Particle *p : particles)
    {
        p->pos = p->_new_pos;
        p->vel = p->_new_vel;
    }
    time += dt;
    steps += 1;
}

// ============================================================

Universe::Universe(db dt) : dt(dt) {}

void Universe::add(Force *f)
{
    forces.push_back(f);
}

void Universe::add(Particle *p)
{
    particles.push_back(p);
}

void Universe::add(Spring *s)
{
    springs.push_back(s);
}

vec3d Universe::total_force(Particle *p)
{
    vec3d total_force;
    for (Force *f : forces)
    {
        total_force += f->get_force(p);
    }
    return total_force;
}

std::string Universe::info()
{
    std::ostringstream os;
    os << "t = " << time;
    return os.str();
}

std::string Universe::toJson()
{
    std::ostringstream os;
    os << "{\"t\":" << time << ",\"particles\":[";
    for (auto i = particles.begin(); i < particles.end(); i++)
    {
        Particle *p = *i;
        os << p->toJson();
        os << (",]"[i == particles.end() - 1]);
    }
    os << ",\"springs\":[]}";
    return os.str();
}

Particle::Particle(vec3d pos, vec3d vel, db mass) : pos(pos), vel(vel), mass(mass) {}

std::string Particle::toJson()
{
    std::ostringstream os;
    os << "{\"pos\":" << pos.toJson() << ",\"vel\":" << vel.toJson() << ",\"mass\":" << mass << "}";
    return os.str();
};

GravityForce::GravityForce(vec3d g) : g(g), Force() {}

vec3d GravityForce::get_force(Particle *p)
{
    return p->mass * g;
}
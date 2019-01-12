#include "physics.h"

void Universe::step() {
    for (Object *o: objects) {
        auto p = dynamic_cast<Particle *> (o);
        if (p == nullptr) continue; // not a particle
        auto F = getForce(*p);
        auto acc = F / p->mass;
        p->pos = p->pos + timestep * p->vel;
        p->vel = p->vel + timestep * acc;
    }
    time += timestep;
}

void Universe::addObject(Object *o) {
    objects.push_back(o);
    o->univ = this;
}

void Universe::addForce(Force *f) {
    forces.push_back(f);
}

vec3 Universe::getForce(Object &p) {
    vec3 F = {0, 0, 0};
    for (auto force: forces) {
        F = F + force->calculateFor(p);
    }
    return F;
}

Particle::Particle(vec3 pos, vec3 vel, double mass) : pos(pos), vel(vel), mass(mass) {

}

ostream &Particle::operator<<(ostream &out) {
    out << "<" << pos.x << ", " << pos.y << ", " << pos.z << ">";
    return out;
}

vec3 GravityForce::calculateFor(Object &o) {
    auto p = dynamic_cast<Particle &>(o);
    return vec3(0, 0, -9.81) * p.mass; // times mass
}

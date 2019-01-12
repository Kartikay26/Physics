//
// Created by st0rmbring3r on 12/1/19.
//

#include <cstdio>
#include "physics.h"

int main() {
    auto u = Universe();
    auto p = Particle(vec3(0, 0, 0), vec3(1, 0, 10), 1);
    auto g = GravityForce();
    u.addObject(&p);
    u.addForce(&g);
    int steps = 0;
    while (p.pos.z >= 0) {
        printf("%0.3f: <%0.2f, %0.2f, %0.2f>\n", u.time, p.pos.x, p.pos.y, p.pos.z);
        u.step();
        steps++;
    }
}

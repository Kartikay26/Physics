#include <iostream>
#include <fstream>
using namespace std;

#include "physics.h"

int main(){
    auto u = Universe();
    
    auto g = GravityForce();
    u.add(&g);
    auto p = Particle(vec3d());
    u.add(&p);

    ofstream fout("data.txt");
    for(int i = 0; i <= 100; i++)
    {
        cout << u.info() << endl;
        fout << u.toJson() << endl;
        for(int k = 0; k < 20; k++)
        {
            u.step();
        }
    }
}
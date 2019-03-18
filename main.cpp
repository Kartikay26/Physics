#include <iostream>
#include <fstream>
using namespace std;

#include "physics.h"

int main(){
    auto u = Universe();
    
    auto g = GravityForce();
    u.add(&g);
    auto p = Particle(vec3d(0,0,0), vec3d(2,0,5));
    u.add(&p);

    ofstream fout("data.txt");
    for(int i = 0; i <= 500; i++)
    {
        cout << u.info() << endl;
        fout << u.toJson() << endl;
        for(int k = 0; k < 20; k++)
        {
            u.step();
        }
    }
}
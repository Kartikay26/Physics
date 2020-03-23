# Physics

A simple physics simulation library in C++.

You can add particles, simulate gravity, springs, charges, etc.

## To install:

(assuming a linux machine)

1. Clone the repo
2. Navigate to frontend/ and run `npm install`
3. Run the server in the background
4. Run `make data` to generate data.txt
5. The frontend automatically reloads with the new data. (or press Ctrl+R)

## Minimal Example:

See main.cpp for a minimal example

```cpp
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
```

A universe is created, a particle is created with some initial velocity and a gravity force is added to the universe. The universe is run by calling u.step in a loop and at every 20th step, the data is recorded into a file.

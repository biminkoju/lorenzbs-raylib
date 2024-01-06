"The Lorenz system is a system of ordinary differential equations first studied by mathematician and meteorologist Edward Lorenz. It is notable for having chaotic solutions for certain parameter values and initial conditions. In particular, the Lorenz attractor is a set of chaotic solutions of the Lorenz system. In popular media the "butterfly effect" stems from the real-world implications of the Lorenz attractor, namely that several different initial chaotic conditions evolve in phase space in a way that never repeats, so all chaos is unpredictable. This underscores that chaotic systems can be completely deterministic and yet still be inherently unpredictable over long periods of time. Because chaos continually increases in systems, we cannot predict the future of systems well. E.g., even the small flap of a butterfly’s wings could set the world on a vastly different trajectory, such as by causing a hurricane. The shape of the Lorenz attractor itself, when plotted in phase space, may also be seen to resemble a butterfly. " -[wikipedia](https://en.wikipedia.org/wiki/Lorenz_system)

### uh so basically my rayblib implementation of this shit

run the build.bash file to compile it, it compiles the file in the src dir

and run the builded file to execute the program

make sure you have gcc and raylib headers installed
and yea idk go nuts

you can change the parameters by changing the varables

```cpp
const float dt = 0.01f;
const float sigma = 10.0f;
const float ro = 28.0f;
const float beta = 8.0f / 3.0f;
```

and the default color is blue(idk how to make rainbow, if you know send pr)

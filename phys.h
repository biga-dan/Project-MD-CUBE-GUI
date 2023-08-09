
#ifndef PHYS_H
#define PHYS_H

class System;

class Physics {
public:
    Physics(System&, int, int);
    bool advance();

private:
    void accumulateAccel();
    void rungeKutta(double, bool);
    void adaptiveRungeKutta();
    System& system_;
    int width_;
    int height_;
};

#endif // PHYS_H

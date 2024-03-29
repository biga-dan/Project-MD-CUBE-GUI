
#ifndef SYSTEM_H
#define SYSTEM_H

#include "state.h"
#include <vector>

#define S_ALIVE     0x01
#define S_SELECTED  0x02
#define S_FIXED     0x04
#define S_TEMPFIXED 0x08

struct Mass {
    Mass()
        : x(0), y(0), vx(0), vy(0), ax(0), ay(0), mass(0), elastic(0),
          radius(0), status(S_ALIVE) {}

    bool isAlive() const { return (status & S_ALIVE) != 0; }
    bool isSelected() const { return (status & S_SELECTED) != 0; }
    bool isFixed() const { return (status & S_FIXED) != 0; }
    bool isTempFixed() const { return (status & S_TEMPFIXED) != 0; }

    void setFixed(bool fixed) {
        if (fixed)
            status |= S_FIXED;
        else
            status &= ~S_FIXED;
    }
    void setTempFixed(bool fixed) {
        if (fixed)
            status |= S_TEMPFIXED;
        else
            status &= ~S_TEMPFIXED;
    }
    void setSelected(bool selected) {
        if (selected)
            status |= S_SELECTED;
        else
            status &= ~S_SELECTED;
    }
    void toggleSelected() { status ^= S_SELECTED; }

    /* Current position, velocity, acceleration */
    double x, y;
    double vx, vy;
    double ax, ay;

    /* Mass and radius of mass */
    double mass;
    double elastic;
    int radius;

    /* Connections to springs */
    std::vector<int> parents;

    int status;

    /* RK temporary space */
    double cur_x, cur_y, cur_vx, cur_vy;
    double old_x, old_y, old_vx, old_vy;
    double test_x, test_y, test_vx, test_vy;
    double k1x, k1y, k1vx, k1vy;
    double k2x, k2y, k2vx, k2vy;
    double k3x, k3y, k3vx, k3vy;
    double k4x, k4y, k4vx, k4vy;
    double k5x, k5y, k5vx, k5vy;
    double k6x, k6y, k6vx, k6vy;
};

struct Spring {
    Spring() : ks(0), kd(0), restlen(0), m1(0), m2(0), status(S_ALIVE) {}

    bool isAlive() const { return (status & S_ALIVE) != 0; }
    bool isSelected() const { return (status & S_SELECTED) != 0; }

    void setAlive(bool alive) {
        if (alive)
            status |= S_ALIVE;
        else
            status &= ~S_ALIVE;
    }
    void setSelected(bool selected) {
        if (selected)
            status |= S_SELECTED;
        else
            status &= ~S_SELECTED;
    }
    void toggleSelected() { status ^= S_SELECTED; }

    /* Ks, Kd and rest length of spring */
    double ks, kd;
    double restlen;

    /* Connected to masses m1 and m2 */
    int m1, m2;

    int status;
};

class System {
public:
    System();
    void deleteMass(int);
    void deleteSpring(int);
    void deleteSelected();
    void addMassParent(int, int);
    void deleteMassParent(int, int);
    void selectObject(int, bool, bool);
    void selectObjects(int, int, int, int);
    void unselectAll();
    void selectAll();
    void moveSelectedMasses(int, int);
    void setCenter();
    bool anythingSelected() const;
    int createMass();
    int createSpring();
    int nearestObject(int, int, bool*) const;
    void deleteAll();
    void reconnectMasses();
    void setRestLenth();
    bool evalSelection();
    void duplicateSelected();
    void restoreState();
    void saveState();
    void attachFakeSpring(int);
    void killFakeSpring();
    void moveFakeMass(int, int);
    void setMassVelocity(int, int, bool);
    void setTempFixed(bool);
    int massCount() const { return masses_.size(); }
    Mass& getMass(int mass) { return masses_[mass]; }
    const Mass& getMass(int mass) const { return masses_[mass]; }
    int springCount() const { return springs_.size(); }
    Spring& getSpring(int spring) { return springs_[spring]; }
    const Spring& getSpring(int spring) const { return springs_[spring]; }
    State& getState() { return state_; }
    const State& getState() const { return state_; }
    void reset();
    bool isFakeMass(int mass) const { return mass == fakeMass_; }
    bool isFakeSpring(int spring) const { return spring == fakeSpring_; }

private:
    void initObjects();
    State state_;
    std::vector<Mass> masses_;
    std::vector<Spring> springs_;
    int fakeMass_;
    int fakeSpring_;
};

#endif

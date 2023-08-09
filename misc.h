
#ifndef MISC_H
#define MISC_H

template <typename NumericType> NumericType deltaX(NumericType dx) {
    return dx;
}

template <typename NumericType> NumericType deltaY(NumericType dy) {
    return -dy;
}

#define NAIL_SIZE 4

int massRadius(double);
int sphereSize(int);
int sphereRadius(int);

inline int screenRadius(int radius) {
    return sphereRadius(sphereSize(radius));
}

inline double square(double x) {
    return x * x;
}

#endif // MISC_H

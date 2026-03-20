#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

struct Bound {
    double low;
    double high;
};

// Границы согласно файлу: a0[0,2], a1[4,12], a2[-200, 1.74], a3[0, 176.54], a4[8,20], a5[0,3], a6[0,8]
const std::vector<Bound> A_BOUNDS = {
    {0.0, 2.0},      // a0
    {4.0, 12.0},     // a1
    {-200.0, 1.74},  // a2
    {0.0, 176.54},   // a3
    {8.0, 20.0},     // a4
    {0.0, 3.0},      // a5
    {0.0, 8.0}       // a6
};

#endif
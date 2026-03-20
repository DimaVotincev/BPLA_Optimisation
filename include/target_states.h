#ifndef TARGET_STATES_H
#define TARGET_STATES_H
#include <vector>
#include "dynamics.h"

struct TargetY {
    double y1, y2, y3, y4, y6;
};

TargetY calculateTargetStates(const std::vector<double>& a, const AeroConstants& config);
#endif
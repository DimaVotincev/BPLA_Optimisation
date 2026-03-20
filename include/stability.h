#ifndef STABILITY_H
#define STABILITY_H
#include <vector>
#include "dynamics.h"

bool isSystemStable(const std::vector<double>& a, const AeroConstants& config);
#endif
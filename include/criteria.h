#ifndef CRITERIA_H
#define CRITERIA_H
#include <vector>
#include "dynamics.h"

// Константы весов из файла: xi1=0.001965, xi2=0.001637, xi3=0.008185, xi4=0.000982, xi5=0.491090, xi6=0.491090
const std::vector<double> XI = {0.001965, 0.001637, 0.008185, 0.000982, 0.491090, 0.491090};

double calculateF(const std::vector<double>& a, const AeroConstants& config);
#endif
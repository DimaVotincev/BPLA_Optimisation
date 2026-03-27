#ifndef CRITERIA_H
#define CRITERIA_H
#include <vector>
#include "dynamics.h"

// Константы весов из файла: ksi1=0.007015, ksi2=0.001637, ksi3=0.008185, ksi4=0.000982, ksi5=0.491090, ksi6=0.491090
const std::vector<double> KSI = {0.007015, 0.001637, 0.008185, 0.000982, 0.491090, 0.491090};

double calculateF(const std::vector<double>& a, const AeroConstants& config);
#endif
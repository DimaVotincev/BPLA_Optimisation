#include "criteria.h"
#include "target_states.h"
#include "stability.h"
#include "dynamics.h"
#include <cmath>

double calculateF(const std::vector<double>& a, const AeroConstants& config) {
    SimulationResult y = solveSystemODE(a, config);
    TargetY ty = calculateTargetStates(a, config);
    double f = 0.0;
    for(size_t i = 0; i < KSI.size() - 1; i++){
        f += (y[i] - ty[i]) * KSI[i];
    }
    f += y[y.size() - 1] * KSI[KSI.size() - 1];
    return f;
}

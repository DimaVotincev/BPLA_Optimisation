#ifndef DYNAMICS_H
#define DYNAMICS_H
#include <vector>

struct AeroConstants {
    double k_beta, k_gamma, l_beta, l_gamma, l_psi, l_e, n_beta, n_gamma, n_psi, n_c;
    double alpha_0, omega_y_star, t_T, epsilon;
};

struct SimulationResult {
    double y1, y2, y3, y4, y6, y8; // y8 - значение интеграла (20)
};

SimulationResult solveSystemODE(const std::vector<double>& a, const AeroConstants& config);
#endif
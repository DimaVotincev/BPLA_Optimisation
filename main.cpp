#include <iostream>
#include <iomanip>
#include "dynamics.h"
#include "criteria.h"
#include "sofama.h"
#include "target_states.h"
#include "agents.h"

// Функция перевода в коэффициенты рулей (зависимость в конце файла)
void printControlGains(const std::vector<double>& a, const AeroConstants& c) {
    double i_beta_e = (a[0] - c.l_beta) / c.l_e;
    double i_x_e    = (a[1] - c.l_gamma) / c.l_e;
    double i_y_e    = (c.l_psi - a[2]) / c.l_e;
    double q_e      = a[3] / c.l_e;
    double i_beta_c = (a[4] - c.n_beta) / c.n_c;
    double i_x_c    = (a[5] - c.n_gamma) / c.n_c;
    double i_y_c    = (a[6] - c.n_psi) / c.n_c;

    std::cout << "\n--- Передаточные числа автопилота ---\n";
    std::cout << "Элероны: i_be=" << i_beta_e << ", i_xe=" << i_x_e << ", i_ye=" << i_y_e << ", qe=" << q_e << "\n";
    std::cout << "РН:      i_bc=" << i_beta_c << ", i_xc=" << i_x_c << ", i_yc=" << i_y_c << "\n";
}

int main() {
    // Данные SR200 из файла
    AeroConstants sr200 = {
        0.1946, 0.0883, 47.272, 6.776, 1.742, 176.54, 13.81, 0.108, 0.859, 7.12, // Аэродинамика
        3.9, 2.0, 15.0, 0.5 // alpha0, omega_y*, t_T, epsilon
    };

    SofamaParams s_p = {50, 0.3, 5, 0.01, 1000}; // Пример параметров SOFAMA

    auto func = [&](const std::vector<double>& a) {
        return calculateF(a, sr200);
    };

    std::vector<double> best_a = runSofama(s_p, func);

    std::cout << "Оптимальный вектор a: ";
    for(double x : best_a) std::cout << std::fixed << std::setprecision(4) << x << " ";
    
    std::cout << "\nЗначение критерия F: " << calculateF(best_a, sr200);
    
    printControlGains(best_a, sr200);

    return 0;
}
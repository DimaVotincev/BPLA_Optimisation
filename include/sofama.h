#ifndef SOFAMA_H
#define SOFAMA_H
#include <vector>
#include <functional>

struct SofamaParams {
    int M; double Q; int N; double gamma; int K;
    // Функции контроля распределения Коши h(k), zeta(k) и phi(k)
};

std::vector<double> runSofama(const SofamaParams& p, std::function<double(const std::vector<double>&)> targetFunc);
#endif
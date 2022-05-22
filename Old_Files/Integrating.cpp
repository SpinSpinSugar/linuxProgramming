#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

double f(double x) {
    return (sin(2*x + 0.5))/(2+cos(x*x + 1));
}

int main(int argc, char* argv[]) {
    std::cout << "Введите пределы интегрирования: \n";
    double a = 0; //0.1
    double b = 0; //0.5
    int n = 0;    //5
    std::cout << "Нижний предел: ";
    std::cin >> a;
    std::cout << "Верхний предел:";
    std::cin >> b;
    std::cout << "Введите число разбиений: ";
    std::cin >> n;
    double h = (b - a) / n;

    // (x_i, y_i) pairs
    std::vector<std::pair<double, double>> values;
    for (int i = 0; i <= n; ++i) {
        values.push_back({a + i * h, f(a + i * h)});
    }

    /*
    for (int i = 0; i <= n; ++i) {
        std::cout << '(' << values[i].first << "; " << values[i].second << ")\n";
    }
    */
    
    //sum for y_i i=[1...n-2]
    double sum = 0;
    for (int i = 1; i < n-1; ++i) {
        sum += values[i].second;
    }

    double valueOfIntegral = h * ((values[0].second + values[n-1].second) / 2 + sum);
    std::cout << "Значение интеграла: " << valueOfIntegral;
    return EXIT_SUCCESS;
}
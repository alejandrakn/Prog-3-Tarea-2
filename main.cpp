#include <iostream>
#include <vector>
#include "core_numeric.h"
#include "mis_clases.h"

int main() {

    // ejemplos con double
    std::vector<double> nums = {1.0, 2.0, 3.0, 4.0, 5.0};

    auto sumaNums   = core_numeric::sum(nums);
    auto promedioNums = core_numeric::mean(nums);
    auto varianzaNums = core_numeric::variance(nums);
    auto maxNums    = core_numeric::max(nums);

    std::cout << "suma:     " << sumaNums    << "\n";
    std::cout << "media:    " << promedioNums << "\n";
    std::cout << "varianza: " << varianzaNums << "\n";
    std::cout << "maximo:   " << maxNums      << "\n\n";

    //  transform_reduce
    auto cuadrados = core_numeric::transform_reduce(nums, [](double x) {
        return x * x;
    });
    std::cout << "suma de cuadrados: " << cuadrados << "\n\n";

    //variadics
    auto s1 = core_numeric::sum_variadic(1, 2, 33, 4);
    auto s2 = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0);
    auto s3 = core_numeric::variance_variadic(1.0, 2.0, 3.0, 4.0);
    auto s4 = core_numeric::max_variadic(1, 2, 7, 3, 4);

    std::cout << "sum_variadic:      " << s1 << "\n";
    std::cout << "mean_variadic:     " << s2 << "\n";
    std::cout << "variance_variadic: " << s3 << "\n";
    std::cout << "max_variadic:      " << s4 << "\n\n";

    // con objetos Coordenadas
    std::vector<Coordenadas> puntos = {
        Coordenadas(1.0, 2.0),
        Coordenadas(3.0, 4.0),
        Coordenadas(0.5, 1.5)
    };

    auto sumaPuntos = core_numeric::sum(puntos);
    std::cout << "suma coordenadas: (" << sumaPuntos.x << ", " << sumaPuntos.y << ")\n";

    auto maxPunto = core_numeric::max(puntos);
    std::cout << "max coordenadas:  (" << maxPunto.x << ", " << maxPunto.y << ")\n\n";

    return 0;
}

#pragma once
#include "concepts.h"
#include "sum_mean.h"

namespace core_numeric {

    // calcula la varianza del contenedor
    // reutiliza mean() como dice la tarea
    template <Iterable C>
    requires Addable<typename C::value_type> && Divisible<typename C::value_type>
    auto variance(const C& contenedor) {
        using T = typename C::value_type;

        auto promedio = mean(contenedor);

        // contar cuantos elementos hay
        std::size_t cuantos = 0;
        for (const auto& _ : contenedor) {
            cuantos++;
        }

        // si constexpr para diferenciar entre enteros y flotantes
        // para enteros hacemos la varianza entera, para flotantes la normal
        if constexpr (std::is_integral_v<T>) {
            // para enteros: sumamos las diferencias al cuadrado como enteros
            T suma_difs{};
            for (const auto& val : contenedor) {
                T dif = val - promedio;
                suma_difs = suma_difs + (dif * dif);
            }
            return suma_difs / cuantos;
        } else {
            // para flotantes: igual pero con mayor precision
            T suma_difs{};
            for (const auto& val : contenedor) {
                T dif = val - promedio;
                suma_difs = suma_difs + (dif * dif);
            }
            return suma_difs / cuantos;
        }
    }

    // calcula el maximo de un contenedor
    // usa el concept Comparable que cree yo
    template <Iterable C>
    requires Comparable<typename C::value_type>
    auto max(const C& contenedor) {
        auto it = std::begin(contenedor);
        auto maximo = *it;  // el primero como maximo inicial
        ++it;

        for (; it != std::end(contenedor); ++it) {
            if (*it > maximo) {
                maximo = *it;
            }
        }
        return maximo;
    }

}

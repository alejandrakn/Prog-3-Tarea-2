#pragma once
#include "concepts.h"
#include <cstddef>
#include <algorithm>
#include <initializer_list>

namespace core_numeric {

    // sum_variadic: suma todos los argumentos que le pases
    // usa fold expression con + para doblar todos los valores
    template <Addable T, Addable... Resto>
    auto sum_variadic(T primero, Resto... demas) {
        return (primero + ... + demas);
    }

    // mean_variadic: promedio de todos los argumentos
    template <Addable T, Addable... Resto>
    requires Divisible<T>
    auto mean_variadic(T primero, Resto... demas) {
        auto total = (primero + ... + demas);
        std::size_t cuantos = 1 + sizeof...(demas);  // sizeof... cuenta los args
        return total / cuantos;
    }

    // helper interno para calcular varianza de variadic
    template <typename T>
    T calcular_varianza_de_lista(std::initializer_list<T> lista) {
        std::size_t n = lista.size();

        T suma{};
        for (const auto& x : lista) {
            suma = suma + x;
        }
        T promedio = suma / n;

        // calculo la varianza
        T suma_difs{};
        for (const auto& x : lista) {
            T dif = x - promedio;
            suma_difs = suma_difs + (dif * dif);
        }
        return suma_difs / n;
    }


    template <typename T, typename... Resto>
    requires Addable<T> && Divisible<T>
    auto variance_variadic(T primero, Resto... demas) {
        if constexpr (std::is_integral_v<T>) {
            // para enteros
            return calcular_varianza_de_lista<T>({primero, static_cast<T>(demas)...});
        } else {
            // para flotantes
            return calcular_varianza_de_lista<T>({primero, static_cast<T>(demas)...});
        }
    }


    template <Comparable T, Comparable... Resto>
    auto max_variadic(T primero, Resto... demas) {
        auto resultado = primero;
        // expando el pack con una lambda que compara
        ((resultado = (demas > resultado ? demas : resultado)), ...);
        return resultado;
    }

}

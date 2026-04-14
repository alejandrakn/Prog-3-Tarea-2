#pragma once
#include "concepts.h"

namespace core_numeric {

    // suma todos los elementos de un contenedor
    template <Iterable C>
    requires Addable<typename C::value_type>
    auto sum(const C& contenedor) {
        using T = typename C::value_type;
        T resultado{};  // se inicializa en 0 para int, double, etc.
        for (const auto& val : contenedor) {
            resultado = resultado + val;
        }
        return resultado;
    }

    // calcula el promedio de un contenedor
    // reutiliza sum() como dice la tarea
    template <Iterable C>
    requires Addable<typename C::value_type> && Divisible<typename C::value_type>
    auto mean(const C& contenedor) {
        auto total = sum(contenedor);
        std::size_t cuantos = 0;
        for (const auto& _ : contenedor) {
            cuantos++;
        }
        return total / cuantos;
    }

}

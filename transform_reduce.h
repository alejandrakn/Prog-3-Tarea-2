#pragma once
#include "concepts.h"
#include "sum_mean.h"

namespace core_numeric {

    // aplica una funcion a cada elemento y luego suma todo
    // la funcion se recibe como parametro template (como pide la tarea)
    template <Iterable C, typename Func>
    requires Addable<typename C::value_type>
    auto transform_reduce(const C& contenedor, Func miFuncion) {
        using T = typename C::value_type;
        T resultado{};

        for (const auto& val : contenedor) {
            resultado = resultado + miFuncion(val);
        }

        return resultado;
    }

}

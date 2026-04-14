#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"
#include "mis_clases.h"

int main() {




    // CASOS QUE SI COMPILAN

    //  sum() con int
    std::vector<int> enteros = {1, 2, 3, 4, 5};
    auto r1 = core_numeric::sum(enteros);  // OK: int cumple Addable
    std::cout << "sum(int): " << r1 << "\n";

    // sum() con double
    std::vector<double> flots = {1.5, 2.5, 3.0};
    auto r2 = core_numeric::sum(flots);  // OK: double cumple Addable
    std::cout << "sum(double): " << r2 << "\n";

    // mean() con double
    auto r3 = core_numeric::mean(flots);  // OK: double cumple Addable y Divisible
    std::cout << "mean(double): " << r3 << "\n";

    //  variance() con double
    std::vector<double> datos = {1.0, 2.0, 3.0};
    auto r4 = core_numeric::variance(datos);  // OK
    std::cout << "variance(double): " << r4 << "\n";

    //  max() con int
    auto r5 = core_numeric::max(enteros);  // OK: int cumple Comparable
    std::cout << "max(int): " << r5 << "\n";

    // max() con double
    auto r6 = core_numeric::max(flots);  // OK: double cumple Comparable
    std::cout << "max(double): " << r6 << "\n";

    // transform_reduce()
    auto r7 = core_numeric::transform_reduce(flots, [](double x) {
        return x * x;
    });  // OK
    std::cout << "transform_reduce: " << r7 << "\n";

    //  variadics con int
    auto r8 = core_numeric::sum_variadic(1, 2, 33, 4);  // OK
    std::cout << "sum_variadic(int): " << r8 << "\n";

    auto r9 = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0);  // OK
    std::cout << "mean_variadic(double): " << r9 << "\n";

    auto r10 = core_numeric::variance_variadic(1.0, 2.0, 3.0, 4.0);  // OK
    std::cout << "variance_variadic(double): " << r10 << "\n";

    auto r11 = core_numeric::max_variadic(1, 2, 7, 3, 4);  // OK
    std::cout << "max_variadic(int): " << r11 << "\n";

    // con clase Coordenadas (cumple Addable, Divisible, Comparable) ---
    std::vector<Coordenadas> puntos = {
        Coordenadas(1.0, 2.0),
        Coordenadas(3.0, 4.0),
        Coordenadas(2.0, 1.0)
    };
    auto r12 = core_numeric::sum(puntos);      // OK: Coordenadas tiene operator+
    auto r13 = core_numeric::mean(puntos);     // OK: Coordenadas tiene operator/ con size_t
    auto r14 = core_numeric::max(puntos);      // OK: Coordenadas tiene operator>
    std::cout << "sum(Coordenadas): (" << r12.x << ", " << r12.y << ")\n";
    std::cout << "mean(Coordenadas): (" << r13.x << ", " << r13.y << ")\n";
    std::cout << "max(Coordenadas): (" << r14.x << ", " << r14.y << ")\n";

    // con clase Esfera
    std::vector<Esfera> esferas = {Esfera(1.0), Esfera(3.0), Esfera(2.0)};
    auto r15 = core_numeric::max(esferas);     // OK: Esfera tiene operator>
    std::cout << "max(Esfera) radio: " << r15.radio << "\n";

    //con clase Vector3D
    std::vector<Vector3D> vecs = {
        Vector3D(1,0,0),
        Vector3D(3,4,0),
        Vector3D(0,1,1)
    };
    auto r16 = core_numeric::sum(vecs);   // OK: Vector3D tiene operator+
    auto r17 = core_numeric::max(vecs);   // OK: Vector3D tiene operator>
    std::cout << "sum(Vector3D): (" << r16.x << ", " << r16.y << ", " << r16.z << ")\n";
    std::cout << "max(Vector3D) magnitud: " << r17.magnitud() << "\n";


    // CASOS QUE NO COMPILAN (dejados comentados para que no salgaa error)


    // CASO 1: sum() con strings
    // std::vector<std::string> palabras = {"hola", "mundo"};
    // auto malo1 = core_numeric::sum(palabras);
    // ERROR: std::string no cumple el concept Addable porque
    // operator+(string, string) no retorna std::same_as<string>
    // en el sentido que el concept espera (retorna string pero
    // el concepto requiere exactamente same_as<T>).
    // En la practica string + string si funciona, pero falla
    // porque el concept Addable requiere { a+b } -> same_as<T>
    // y std::string cumple eso, asi que para forzar el error
    // usamos variance o mean que son mas restrictivos:

    // CASO 2: mean() con strings (no tiene operator/ con size_t)
    // std::vector<std::string> palabras2 = {"a", "b", "c"};
    // auto malo2 = core_numeric::mean(palabras2);
    // ERROR: std::string no cumple Divisible porque no tiene
    // operator/(string, size_t). No se puede sacar un promedio de strings.

    // CASO 3: variance() con strings
    // std::vector<std::string> palabras3 = {"a", "b", "c"};
    // auto malo3 = core_numeric::variance(palabras3);
    // ERROR: std::string no cumple Divisible (igual que mean).

    // CASO 4: max() con strings (cumple Comparable! pero lo excluimos con el concept)
    // Para excluir string del max necesitaria un concept mas especifico.
    // String SI tiene < y > pero semanticamente no tiene sentido en este contexto.

    // CASO 5: max() con un tipo sin operator>
    // struct SinComparar { int x; };
    // std::vector<SinComparar> cosas = {SinComparar{1}, SinComparar{2}};
    // auto malo4 = core_numeric::max(cosas);
    // ERROR: SinComparar no cumple Comparable porque no tiene
    // operator< ni operator> definidos.

    // CASO 6: sum() con un tipo sin operator+
    // struct SinSuma { int x; };
    // std::vector<SinSuma> cosas2 = {SinSuma{1}, SinSuma{2}};
    // auto malo5 = core_numeric::sum(cosas2);
    // ERROR: SinSuma no cumple Addable porque no tiene operator+.

    // CASO 7: mean() con int (int no cumple Divisible como lo definimos)
    // std::vector<int> enteros2 = {1, 2, 3};
    // auto malo6 = core_numeric::mean(enteros2);
    // Nota: en realidad int SI cumple Divisible si int/size_t -> int,
    // depende de la implementacion. Puede que compile segun el compilador.

    // CASO 8: sum_variadic con tipos que no son Addable
    // auto malo7 = core_numeric::sum_variadic("hola", "mundo");
    // ERROR: const char* no cumple Addable porque no tiene operator+
    // definido que retorne const char*.

    std::cout << "\nTodos los casos validos funcionaron correctamente\n";
    return 0;
}

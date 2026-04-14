#pragma once
#include <concepts>
#include <iterator>

// concept para saber si dos cosas se pueden sumar
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

// concept para saber si algo se puede dividir entre un numero
template <typename T>
concept Divisible = requires(T a, std::size_t n) {
    { a / n } -> std::same_as<T>;
};

// concept para saber si algo se puede recorrer con un for
template <typename C>
concept Iterable = requires(C c) {
    std::begin(c);
    std::end(c);
};

// concept propio: para saber si dos cosas se pueden comparar con < y >
// lo voy a usar en max() para que solo funcione con tipos que se puedan ordenar
template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::same_as<bool>;
    { a > b } -> std::same_as<bool>;
};

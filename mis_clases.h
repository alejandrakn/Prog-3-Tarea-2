#pragma once
#include <cmath>
#include <iostream>

// Clase Coordenadas para probar los concepts con objetos
struct Coordenadas {
    double x, y;

    Coordenadas() : x(0), y(0) {}
    Coordenadas(double x, double y) : x(x), y(y) {}

    // necesito + para que funcione Addable
    Coordenadas operator+(const Coordenadas& otro) const {
        return Coordenadas(x + otro.x, y + otro.y);
    }

    // necesito / para que funcione Divisible
    Coordenadas operator/(std::size_t n) const {
        return Coordenadas(x / n, y / n);
    }

    // necesito < y > para que funcione Comparable (lo uso en max) y tmb comparo por distancia al origen
    bool operator<(const Coordenadas& otro) const {
        double miDist = x*x + y*y;

        double suDist = otro.x*otro.x + otro.y*otro.y;
        return miDist < suDist;
    }

    bool operator>(const Coordenadas& otro) const {
        return otro < *this;
    }

    // para poder restarlas (lo necesito en variance)
    Coordenadas operator-(const Coordenadas& otro) const {
        return Coordenadas(x - otro.x, y - otro.y);
    }

    // para poder multiplicarlas (lo necesito en variance para dif*dif)
    Coordenadas operator*(const Coordenadas& otro) const {
        return Coordenadas(x * otro.x, y * otro.y);
    }
};

// Clase Vector3D para otro ejemplo
struct Vector3D {
    double x, y, z;

    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& otro) const {
        return Vector3D(x + otro.x, y + otro.y, z + otro.z);
    }

    Vector3D operator/(std::size_t n) const {
        return Vector3D(x / n, y / n, z / n);
    }

    Vector3D operator-(const Vector3D& otro) const {
        return Vector3D(x - otro.x, y - otro.y, z - otro.z);
    }

    Vector3D operator*(const Vector3D& otro) const {
        return Vector3D(x * otro.x, y * otro.y, z * otro.z);
    }

    // comparo por magnitud
    double magnitud() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    bool operator<(const Vector3D& otro) const {
        return magnitud() < otro.magnitud();
    }

    bool operator>(const Vector3D& otro) const {
        return otro < *this;
    }
};

// Clase Esfera para otro ejemplo
struct Esfera {
    double radio;

    Esfera() : radio(0) {}
    Esfera(double r) : radio(r) {}

    Esfera operator+(const Esfera& otra) const {
        return Esfera(radio + otra.radio);
    }

    Esfera operator/(std::size_t n) const {
        return Esfera(radio / n);
    }

    Esfera operator-(const Esfera& otra) const {
        return Esfera(radio - otra.radio);
    }

    Esfera operator*(const Esfera& otra) const {
        return Esfera(radio * otra.radio);
    }

    bool operator<(const Esfera& otra) const {
        return radio < otra.radio;
    }

    bool operator>(const Esfera& otra) const {
        return otra < *this;
    }
};

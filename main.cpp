#include <iostream>
#include "macierz.h"

int main() {
    // Tworzenie obiekt�w macierzy
    Macierz m1;
    Macierz m2;
    Macierz m3;

    // Wy�wietlanie pocz�tkowych macierzy
    std::cout << "Macierz m1:" << std::endl << m1 << std::endl;
    std::cout << "Macierz m2:" << std::endl << m2 << std::endl;

    // Ustawianie warto�ci element�w macierzy
    m1.ustaw(0, 0, 1);
    m1.ustaw(0, 1, 2);
    m1.ustaw(1, 0, 3);
    m1.ustaw(1, 1, 4);

    m2.ustaw(0, 0, 5);
    m2.ustaw(0, 1, 6);
    m2.ustaw(1, 0, 7);
    m2.ustaw(1, 1, 8);

    // Wy�wietlanie macierzy po ustawieniu warto�ci element�w
    std::cout << "Macierz m1 po ustawieniu warto�ci element�w:" << std::endl << m1 << std::endl;
    std::cout << "Macierz m2 po ustawieniu warto�ci element�w:" << std::endl << m2 << std::endl;

    // Przyk�ady operacji na macierzach
     m3 = m1 + m2;
    std::cout << "Wynik dodawania m1 i m2:" << std::endl << m3 << std::endl;

    m3 = m1 * m2;
    std::cout << "Wynik mno�enia m1 i m2:" << std::endl << m3 << std::endl;

    m1 *= m2;
    std::cout << "Macierz m1 po przypisaniu wyniku mno�enia m1 i m2:" << std::endl << m1 << std::endl;

    // Przyk�ady operacji na macierzy z skalarem
    m3 = m1 * 2.0;
    std::cout << "Wynik mno�enia m1 przez skalar 2.0:" << std::endl << m3 << std::endl;

    m1 *= 0.5;
    std::cout << "Macierz m1 po przypisaniu wyniku mno�enia przez skalar 0.5:" << std::endl << m1 << std::endl;

    // Transponowanie macierzy
    m3 = m1;
    m3.transponuj();
    std::cout << "Transponowana macierz m3:" << std::endl << m3 << std::endl;

    // Por�wnywanie macierzy
    std::cout << "Czy m1 jest r�wna m2? " << (m1 == m2 ? "Tak" : "Nie") << std::endl;

    return 0;
}

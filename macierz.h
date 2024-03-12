#pragma once
#ifndef MACIERZ_HPP
#define MACIERZ_HPP

#include <iostream>

class Macierz
{
private:
    static const int LICZBA_WM = 2;
    static const int LICZBA_KM = 2;
    double macierzTablica[LICZBA_WM][LICZBA_KM];

public:
    // Konstruktory i destruktor
    Macierz();                  // Konstruktor domyœlny
    Macierz(const Macierz& copy); // Konstruktor kopiuj¹cy
    ~Macierz();                 // Destruktor

    // Metody publiczne
    double pobierz(int i, int j) const;    // Pobiera wartoœæ elementu na pozycji (i, j)
    void ustaw(int i, int j, double x);    // Ustawia wartoœæ elementu na pozycji (i, j)
    void transponuj();                      // Transponuje macierz

    // Przeci¹¿one operatory
    Macierz operator*(const Macierz& copy) const;     // Operator mno¿enia macierzy
    Macierz operator+(const Macierz& copy) const;     // Operator dodawania macierzy
    Macierz operator*(const double x) const;         // Operator mno¿enia przez skalar
    Macierz& operator=(const Macierz& copy);          // Operator przypisania
    bool operator==(const Macierz& copy) const;       // Operator porównania
    Macierz& operator+=(const Macierz& copy);         // Operator dodawania macierzy z przypisaniem
    Macierz& operator*=(const Macierz& copy);         // Operator mno¿enia macierzy z przypisaniem
    Macierz& operator*=(const double x);             // Operator mno¿enia przez skalar z przypisaniem

    // Przyjazna funkcja do wyœwietlania
    friend std::ostream& operator<<(std::ostream& s, const Macierz& mx);
};

#endif // MACIERZ_HPP

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
    Macierz();                  // Konstruktor domy�lny
    Macierz(const Macierz& copy); // Konstruktor kopiuj�cy
    ~Macierz();                 // Destruktor

    // Metody publiczne
    double pobierz(int i, int j) const;    // Pobiera warto�� elementu na pozycji (i, j)
    void ustaw(int i, int j, double x);    // Ustawia warto�� elementu na pozycji (i, j)
    void transponuj();                      // Transponuje macierz

    // Przeci��one operatory
    Macierz operator*(const Macierz& copy) const;     // Operator mno�enia macierzy
    Macierz operator+(const Macierz& copy) const;     // Operator dodawania macierzy
    Macierz operator*(const double x) const;         // Operator mno�enia przez skalar
    Macierz& operator=(const Macierz& copy);          // Operator przypisania
    bool operator==(const Macierz& copy) const;       // Operator por�wnania
    Macierz& operator+=(const Macierz& copy);         // Operator dodawania macierzy z przypisaniem
    Macierz& operator*=(const Macierz& copy);         // Operator mno�enia macierzy z przypisaniem
    Macierz& operator*=(const double x);             // Operator mno�enia przez skalar z przypisaniem

    // Przyjazna funkcja do wy�wietlania
    friend std::ostream& operator<<(std::ostream& s, const Macierz& mx);
};

#endif // MACIERZ_HPP

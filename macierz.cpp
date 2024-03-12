#include "macierz.h"

Macierz::Macierz() : macierzTablica{ {5, 2}, {7, 8} } {}

Macierz::Macierz(const Macierz& c)
{
    for (int i = 0; i < LICZBA_WM; i++)
    {
        for (int j = 0; j < LICZBA_KM; j++)
        {
            macierzTablica[i][j] = c.macierzTablica[i][j];
        }
    }
}

Macierz::~Macierz() {}

double Macierz::pobierz(int i, int j) const
{
    return macierzTablica[i][j];
}

void Macierz::ustaw(int i, int j, double x)
{
    if (i >= 0 && i < LICZBA_WM && j >= 0 && j < LICZBA_KM)
    {
        this->macierzTablica[i][j] = x;
    }
    else
    {
        std::cerr << "Nieprawid³owy indeks macierzy!" << std::endl;
    }
}

void Macierz::transponuj()
{
    for (int wiersz = 0; wiersz < LICZBA_WM; wiersz++)
    {
        for (int kolumna = wiersz + 1; kolumna < LICZBA_KM; kolumna++)
        {
            // Zamiana elementów macierzy wiersz-kolumna z kolumna-wiersz
            double temp = macierzTablica[wiersz][kolumna];
            macierzTablica[wiersz][kolumna] = macierzTablica[kolumna][wiersz];
            macierzTablica[kolumna][wiersz] = temp;
        }
    }
}

Macierz Macierz::operator*(const Macierz& c) const
{
    Macierz mnozenie;
    for (int wiersz = 0; wiersz < LICZBA_WM; wiersz++)
    {
        for (int kolumna = 0; kolumna < LICZBA_KM; kolumna++)
        {
            mnozenie.macierzTablica[wiersz][kolumna] = 0;

            for (int k = 0; k < LICZBA_KM; ++k)
            {
                mnozenie.macierzTablica[wiersz][kolumna] += macierzTablica[wiersz][k] * c.macierzTablica[k][kolumna];
            }
        }
    }

    return mnozenie;
}

Macierz Macierz::operator+(const Macierz& c) const
{
    Macierz suma = *this; // Tworzenie kopii aktualnej macierzy
    suma += c; // Wykorzystanie operatora +=
    return suma;
}

Macierz Macierz::operator*(const double x) const
{
    Macierz tmp = *this;
    for (int wiersz = 0; wiersz < LICZBA_WM; wiersz++)
    {
        for (int kolumna = 0; kolumna < LICZBA_KM; kolumna++)
        {
            tmp.macierzTablica[wiersz][kolumna] *= x;
        }
    }
    return tmp;
}

Macierz& Macierz::operator=(const Macierz& c)
{
    if (this == &c)
    {
        return *this;
    }
    for (int i = 0; i < LICZBA_WM; ++i)
    {
        for (int j = 0; j < LICZBA_KM; ++j)
        {
            this->macierzTablica[i][j] = c.macierzTablica[i][j];
        }
    }
    return *this;
}

Macierz& Macierz::operator+=(const Macierz& c)
{
    for (int wiersz = 0; wiersz < LICZBA_WM; wiersz++)
    {
        for (int kolumna = 0; kolumna < LICZBA_KM; kolumna++)
        {
            this->macierzTablica[wiersz][kolumna] += c.macierzTablica[wiersz][kolumna];
        }
    }
    return *this;
}

Macierz& Macierz::operator*=(const Macierz& c)
{
    Macierz tmp;
    for (int wiersz = 0; wiersz < LICZBA_WM; wiersz++)
    {
        for (int kolumna = 0; kolumna < LICZBA_KM; kolumna++)
        {
            tmp.macierzTablica[wiersz][kolumna] = 0;

            for (int k = 0; k < LICZBA_KM; ++k)
            {
                tmp.macierzTablica[wiersz][kolumna] += macierzTablica[wiersz][k] * c.macierzTablica[k][kolumna];
            }
        }
    }

    *this = tmp;
    return *this;
}

Macierz& Macierz::operator*=(const double x)
{
    for (int wiersz = 0; wiersz < LICZBA_WM; wiersz++)
    {
        for (int kolumna = 0; kolumna < LICZBA_KM; kolumna++)
        {
            this->macierzTablica[wiersz][kolumna] *= x;
        }
    }
    return *this;
}

bool Macierz::operator==(const Macierz& c) const
{
    for (int i = 0; i < LICZBA_WM; i++)
    {
        for (int j = 0; j < LICZBA_KM; j++)
        {
            if (macierzTablica[i][j] != c.macierzTablica[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& strumien, const Macierz& mx)
{
    strumien << "Macierz 2x2:" << std::endl;
    for (int i = 0; i < Macierz::LICZBA_WM; i++)
    {
        for (int j = 0; j < Macierz::LICZBA_KM; j++)
        {
            strumien << " a" << i + 1 << "," << j + 1 << ":" << mx.macierzTablica[i][j];
        }
        strumien << "\n";
    }
    return strumien;
}

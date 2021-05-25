#include <iostream>
#include "Fraction.h"


Fraction::Fraction(int num = 1, int denum = 1)
{
    if (denum == 0)
    {
        std::cout << "Incorrect input" << std::endl;
        exit(1);
    }
    if (num == 0)
    {
        std::cout << 0 << std::endl;
        exit(1);
    }
    int less, j;
    do
    {
        if (num < denum)
            less = num;
        else
            less = denum;
        for (j = less; j > 0; j--)
        {
            if (!(num % j) && !(denum % j))
            {
                num /= j;
                denum /= j;
                break;
            }
        }
    } while (j != 1);
    numerator = num;
    denumerator = denum;
}

void Fraction::showme()
{
    if (denumerator == 1)
    {
        std::cout << numerator << std::endl;
        exit(1);
    }
    std::cout << numerator << "/" << denumerator << std::endl;
}

Fraction Fraction::operator+(Fraction f)
{
    return Fraction(this->numerator * f.denumerator + f.numerator * this->denumerator, this->denumerator * f.denumerator);
}

Fraction Fraction::operator-(Fraction f)
{
    return Fraction(this->numerator * f.denumerator - f.numerator * this->denumerator, this->denumerator * f.denumerator);
}

Fraction Fraction::operator*(Fraction f)
{
    return Fraction(this->numerator * f.numerator, this->denumerator * f.denumerator);
}

Fraction Fraction::operator/(Fraction f)
{
    return Fraction(this->numerator * f.denumerator, this->denumerator * f.numerator);
}

std::ostream& operator<<(std::ostream& out, Fraction f)
{
    out << f.numerator << "/" << f.denumerator << std::endl;

    return out;
}

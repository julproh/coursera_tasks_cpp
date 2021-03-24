#include <iostream>

using namespace std;
class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        int a = numerator, b = denominator, c = 0;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        if (denominator / a < 0) {
        	denominator = -denominator;
        	numerator = -numerator;
        }
        p = numerator / a;
        q = denominator / a;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
};

bool operator == (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return (lhs.Numerator() * l) == (rhs.Numerator() *r);
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return Rational((lhs.Numerator() * l) + (rhs.Numerator() *r), n);
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return Rational((lhs.Numerator() * l) - (rhs.Numerator() *r), n);
}
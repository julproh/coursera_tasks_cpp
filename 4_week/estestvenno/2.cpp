#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;


class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
    	if (denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}
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

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}
Rational operator + (Rational a, Rational b) { //и тут перегрузим, и дальше тоже
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}
Rational operator - (Rational a, Rational b) {
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}
Rational operator * (Rational a, Rational b) {
    return Rational((a.Numerator()*b.Numerator()), (a.Denominator()*b.Denominator()));
}
istream& operator >> (istream& stream, Rational& r) { //возвращать будем ссылку на поток
    //if (stream) return stream;
    int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = { p, q };
    }
    return stream;
}
 
ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator > (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) { //обязательно нужно это дело перегрузить, для использования в map и set
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main () {
    Rational r1, r2;
    char c;
    try {cin >> r1 >> c >> r2;
    if ( c == '+') {
        cout << r1+r2 << endl;
    } else if ( c == '-') {
        cout << r1-r2 << endl;
    } else if (c == '*') {
        cout << r1*r2 << endl;
    } else {
        cout << r1/r2 << endl;
    } } catch (exception& ex) { cout << ex.what() << endl;}
    return 0;
}
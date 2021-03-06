#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;
class Rational {
public:
    Rational() { //конструктор по умолчанию
        num = 0;
        den = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator < 0) { //постепенно все проверяем, что пришло на вход
            if (numerator < 0) { //и следим за отрицательностью
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }
        if (numerator == 0) {
            denominator = 1;
        }
        //обязательно сократим дробь, если можно
        int nod = Nod(abs(numerator), abs(denominator));
        num = numerator / nod;
        den = denominator / nod;
    }
    int Numerator() const { //тут просто возвращаем значения
        return num;
    }
    int Denominator() const { //и тут
        return den;
    }
private:
    int num; //поле числитель
    int den; //и знаменатель
 
    int Nod(int a, int b) { //маленькая функция нахождения делителя
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        } //while
        return a + b;
    }
};
bool operator == (Rational a, Rational b) { //перезгузим оператор ==
    if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator())) {
        return true;
    }
    else {
        return false;
    }
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
Rational operator / (Rational a, Rational b) {
    return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
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

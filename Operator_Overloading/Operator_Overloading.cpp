#include"Siniflar.h"
using namespace std;

Kompleks::Kompleks(int r = 1, int i = 0) {
    real = r;
    imag = i;
    cout << "Parametreli constructor calisti" << endl;
}

Kompleks::~Kompleks()
{
    cout << "Yikici metod calisti" << endl;
}
Kompleks::Kompleks(const Kompleks& oth) {
    real = oth.real;
    imag = oth.imag;
    cout << "Kopya metodu calisti" << endl;
}
Kompleks Kompleks::topla(const Kompleks& x) {
    int r, i;
    r = this->real + x.real;
    i = this->imag + x.imag;
    return Kompleks(r, i);
}
Kompleks Kompleks::cıkar(const Kompleks& x) {
    Kompleks result = x;
    result.eksi();
    return topla(result);
}

Kompleks Kompleks::operator+(const Kompleks& oth)const {
    int r_, i_;
    r_ = real + oth.real;
    i_ = imag + oth.imag;
    cout << "'+' operatoru asırı yuklendi" << endl;
    return Kompleks(r_, i_);
}
void Kompleks::operator++() { 
    real += 1;
    cout << "'++' operatoru asiri yuklendi" << endl;
}
void Kompleks::operator--(int) {
    real -= 1;
    cout << "'--' operatoru asiri yuklendi" << endl;

}

void String::operator=(const String& oth) {
    int size = 0;
    if (size != oth.size) {
        size = oth.size;
        delete[] contents;
        contents = new char[size +1 ];
    }
    memcpy(contents, oth.contents, size + 1);
    cout << "'=' operatoru asırı yuklendi" << endl;

}
char& String::operator[](int i) {
    if (i < 0) return contents[0];
    else if (i >= size) return contents[size - 1];
    else return contents[i];
}
String::String() : contents(nullptr), size(0) {
    cout << "Parametresiz constructor calisti" << endl;
}

String::String(const char* mesaj) {
    size = strlen(mesaj);
    contents = new char[size + 1];
    memcpy(contents, mesaj, size + 1);
    cout << "Parametreli constructor calisti" << endl;
}

String::~String()
{
    delete[] contents;
    cout << "Yikici metod calisti" << endl;

}
void String::yazdir() {
   cout << contents <<endl;
}
int main()
{
    //Kompleks k1(9, 5);
    //k1.yazdir();
    //++k1;//preincrement 
    //k1.yazdir();
    //k1--;//postincrement
    //k1.yazdir();
    
    
    //String s1("Sinan"),s2;
    //s1[1] = 'a';
    //s1.yazdir();
    //cout << s1[4] << endl;



    Kompleks k1(5, 3),k3;
    Kompleks k2 = k1;

    k3 = k1 + k2;

    k1.yazdir();
    k2.yazdir();
    k3.yazdir();

}


#pragma once
#include<iostream>
using namespace std;

class Kompleks
{
public:
    Kompleks(int r, int i);
    ~Kompleks();
    Kompleks(const Kompleks& oth);
    Kompleks topla(const Kompleks& x);
    int getR() { return real; }
    int getI() { return imag; }
    void setValue(int r, int i) {
        real = r;
        imag = i;
    }
    void yazdir() {
        imag >= 0 ? cout << "Sayi : " << real << "+" << imag << "i" << endl : cout << "Sayi : " << real << "-" << imag << "i" << endl;
    }
    void eksi() {
        real *= -1;
        imag *= -1;
    }
    Kompleks cýkar(const Kompleks& x);
    Kompleks operator+(const Kompleks& oth)const;
    void operator++();
    void operator--(int);
private:
    int real, imag;
};
class String
{
public:
    String();
    String(const char* mesaj);
    ~String();
    void operator=(const String& oth);
    char& operator[](int i);
    void yazdir();

private:
    int size;
    char* contents;
};





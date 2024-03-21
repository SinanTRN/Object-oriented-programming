#include <iostream>
using namespace std;
class kompleks {
    int real, imag;
public:
    kompleks() { cout << "constructor calisti" << endl; };
    kompleks(int r, int i) {
        real = r;
        imag = i;
        cout << "Parametreli constructor calisti" << endl;
    }
    kompleks(const kompleks& oth) {
        real = oth.real;
        imag = oth.imag;
        cout << "Copy constructor calisti" << endl;
    }
    ~kompleks() { cout << "destruction methodu calisti" << endl; }
    int getR() { return real; }
    int getI() { return imag; }
    void setValue(int r, int i) {
        real = r;
        imag = i;
    }
    void yazdir() {
        imag >= 0 ? cout<<"Sayi : " << real << "+" << imag << "i" << endl : cout<<"Sayi : " << real<<"-" << imag << "i" << endl;
    }
    void eksi() {
        real *= -1;
        imag *= -1;
    }
    kompleks topla(const kompleks& x) {
        //kompleks result;
        //result.real = this->real + x.real;
        //result.imag = this->imag + x.imag;
        //return result;

        int r, i;
        r = this->real + x.real;
        i = this->imag + x.imag;
        return kompleks(r, i);

    }
    kompleks cıkar(kompleks& x) {
        kompleks result;
        x.eksi();
        result = topla(x);
        return result;
    }
    kompleks carpSbt(int a) {
        kompleks result;
        result.real = real * a;
        result.imag = imag * a;
        return result;
    }
    kompleks carpKompleks(const kompleks& x) {
        kompleks result;
        result.real = (real * x.real)- (imag * x.imag);
        result.imag = (real * x.imag) + (imag * x.real);
        return result;
    }

};
int main()
{

    kompleks k1(4, 5);
    kompleks k2(6, 7);

    kompleks k3 = k1.topla(k2);
    k3.yazdir();


    //kompleks k1(4,5);
    //cout << "Real :" << k1.getR() << endl;
    //cout << "Imag :" << k1.getI() << endl;
    //k1.yazdir();
    //
    //kompleks k2(k1);
  
    //
    //k2.setValue(2,3);
    //k2.yazdir();
    //kompleks k3;
    //k3 = k2.carpKompleks(k1);
    //k3.yazdir();



}

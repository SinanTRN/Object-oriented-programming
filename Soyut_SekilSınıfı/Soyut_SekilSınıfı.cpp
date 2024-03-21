#include <iostream>
#include "Sekil.h"
int main()
{
    Sekil* ptr[] = { new Daire(5),new Dikdortgen(3,5) };
    int number;
    char c;
    do {
        cout << "Lutfen seklinizi ve komutunuzu giriniz : ";
        cin >> number;
        cin >> c;
        switch(c){
        case 'A':
            ptr[number]->hesaplaAlan();
            cout << "Alan hesaplandi" << endl;
            break;
        case 'C':
            ptr[number]->hesaplaCevre();
            cout << "Cevre hesaplandi" << endl;
            break;
        case 'Y':
            ptr[number]->yazdir();
        }
    } while (number != -1);
}

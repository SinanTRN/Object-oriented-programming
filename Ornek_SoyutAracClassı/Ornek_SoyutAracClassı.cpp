#include <iostream>
#include "Arac.h"
int main()
{
    Arac* ptr[] = { new Araba("Auidi RS7",2000000),new Motorsiklet("Kawasaki",400000) };
    int number;
    char komut;
    do {
        cout << "Lutfen araci ve yapacaginiz islemi giriniz : ";
        cin >> number;
        cin >> komut;
        switch (komut) {
        case 'U':
            ptr[number]->hiziArttir();
            ptr[number]->yazdir();
            break;
        case'D':
            ptr[number]->hiziAzalt();
            ptr[number]->yazdir();
            break;
        case'A':
            ptr[number]->calistir();
            ptr[number]->yazdir();
            break;
        case'K':
            ptr[number]->durdur();
            ptr[number]->yazdir();
            break;
        }
    } while (number != -1);
}

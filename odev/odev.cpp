#include <iostream>
using namespace std;
int main() {
    int sayi;
    cin >> sayi;
    for (int j = 0; j < sayi; j++) {     
            int toplam = 0;
            for (int k = 0; k < j; k++) {
                toplam += j;
            }
            if (toplam == sayi) {
                cout << j;
                break;
            }      
    }
    return 0;
} 
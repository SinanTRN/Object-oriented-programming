#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class Matris {
	int satir, sutun;
	int** matris;
public:
	Matris(){}
	Matris(int sa ,int su) {
		if ((0 < sa) && (0 < su)) {
			satir = sa;
			sutun = su;
		}
		else{ 
			satir = 5;
			sutun = 5;
		}
		matris = new int* [satir];
		for (int i = 0; i < satir; i++) {
			matris[i] = new int [sutun];
		}
		cout << "Matris olusturuldu." << endl;

	}
	~Matris() { 
		for (int i = 0; i < satir; i++) {
			delete[] matris[i];
		}
		delete[] matris;
		cout << "Yikici metod calisti" << endl; }
	Matris(const Matris& x) {
		satir = x.satir;
		sutun = x.sutun;
		matris = new int* [satir];
		for (int i = 0; i < satir; i++) {
			matris[i] = new int[sutun];
		}
		for (int i = 0; i < satir; i++) {
			for (int j = 0; i < sutun; i++) {
				matris[i][j] = x.matris[i][j];
			}
		}
	}
	void setValue(int sa, int su, int deger) {
		matris[sa][su] = deger;
	}
	void yazdir() {
		cout << ".................." << endl;
		cout << "  MATRIS " << endl;
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
				cout << matris[i][j] << " ";
			}
			cout << "\n";
		}
		cout << ".................." << endl;

	}
	void random() {
		srand(time(NULL));
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
				matris[i][j] = rand() % 10;
			}
		}

	}
	void birimMat() {
		if (satir == sutun) {
			for (int i = 0; i < satir; i++) {
				for (int j = 0; j < sutun; j++) {
					if (i == j) {
						matris[i][j] = 1;
					}
					else {
						matris[i][j] = 0;

					}
				}
			}
		}
		else { cout << "Birim matris olusturulamadi !!!" << endl; }
	}
	void toplam(const Matris& x) {
		Matris result(satir,sutun);
		if ((satir == x.satir) && (sutun == x.sutun)) {
			for (int i = 0; i < satir; i++) {
				for (int j = 0; j < sutun; j++) {
					result.matris[i][j] = this->matris[i][j] + x.matris[i][j];
				}
			}
			result.yazdir();
		}
		else { cout << "Satir ve sutun sayilari esit olmali ." << endl; }
		
	}

};
int main()
{
	Matris m1(4,4);
	m1.random();
	m1.yazdir();
	Matris m2(4, 4);
	m2.birimMat();
	m2.yazdir();
	
	m2.toplam(m1);

}


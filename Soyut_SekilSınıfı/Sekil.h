#pragma once
#include<iostream>
#define PI 3.14
using namespace std;
class Sekil
{
	double alan=0, cevre=0;
public:
	double getAlan() const { return alan; }
	double getCevre() const { return cevre; }

	void setAlan(double _alan) { alan = _alan; }
	void setCevre(double _cevre) { cevre = _cevre; }

	virtual void hesaplaAlan() = 0;
	virtual void hesaplaCevre() = 0;
	virtual void yazdir() = 0;
};
class Daire :public Sekil {
	double yaricap;
public:
	Daire(double r){
		yaricap = r;
	}
	void hesaplaAlan() {
		setAlan(PI * yaricap * yaricap);
	}
	void hesaplaCevre() {
		setCevre(2 * PI * yaricap);
	}
	void yazdir() {
		cout << ".......Daire......." << endl;
		cout << "Alan : " << getAlan() << endl;
		cout << "Cevre : " << getCevre() << endl;
	}
};
class Dikdortgen :public Sekil {
	double kisa, uzun;
public:
	Dikdortgen(double k, double u) {
		kisa = k;
		uzun = u;
	}
	void hesaplaAlan() {
		setAlan(kisa * uzun);
	}
	void hesaplaCevre() {
		setCevre(2 * (kisa + uzun));
	}
	void yazdir() {
		cout << ".......Dikdortgen......." << endl;
		cout << "Alan : " << getAlan() << endl;
		cout << "Cevre : " << getCevre() << endl;
	}
};


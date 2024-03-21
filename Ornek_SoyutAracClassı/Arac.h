#pragma once
#include<string.h>
using namespace std;
class Arac
{
	int hiz, vites;
	bool calismaDurumu;
	string marka;
	long fiyat;
public:
	Arac(string _marka,long _fiyat) {
		calismaDurumu = false;
		hiz = 0;
		vites = 0;
		marka = _marka;
		fiyat = _fiyat;
	}

	int getHiz() const { return hiz; }
	int getVites() const { return vites; }
	bool getCalismaDurumu() const { return calismaDurumu; }
	string getMarka() const { return marka; }
	long getFiyat() const { return fiyat; }
	
	void setHiz(int _hiz) { hiz = _hiz; }
	void setVites(int _vites) { vites = _vites; }
	void setMarka(string _marka) { marka = _marka; }
	void setFiyat(long _fiyat) { fiyat = _fiyat; }

	void calistir() {
		calismaDurumu = true;
		vites = 1;
	}
	void durdur() {
		calismaDurumu = false;
		vites = 0;
	}

	virtual void yazdir() {
		cout << "Marka : " << marka << endl;
		cout << "Fiyati : " << fiyat << endl;
		cout << "Hizi : " << hiz << endl;
		cout << "Vites numarasi : " << vites << endl;
	}
	virtual void hiziArttir() = 0;
	virtual void hiziAzalt() = 0;
};

class Araba : public Arac
{
public:
	Araba(string marka,long fiyat):Arac(marka,fiyat){}
	void yazdir() {
		cout << ".........Araba Bilgileri........." << endl;
		Arac::yazdir();
	}
	void hiziArttir() {
		if (getCalismaDurumu()) {
			if (getHiz() <= 120) {
				setHiz(getHiz() + 30);
				if (getVites() <= 5) {
					setVites(getVites() + 1);
				}
			}
		}
		else
			cout << "Lutfen once araci calistirin..." << endl;
	}
	void hiziAzalt() {
		if (getCalismaDurumu()) {
			if (getHiz() >= 30) {
				setHiz(getHiz() - 30);
				if (getVites() >= 2) {
					setVites(getVites() - 1);
				}
			}
		}
		else
			cout << "Lutfen once araci calistirin..." << endl;

	}
};
class Motorsiklet :public Arac {
public:
	Motorsiklet(string marka, long fiyat) :Arac(marka, fiyat){}
	void yazdir() {
		cout << "......Motorsiklet Bilgileri......." << endl;
		Arac::yazdir();
	}
	void hiziArttir() {
		if (getCalismaDurumu()) {
			if (getHiz() <= 150) {
				setHiz(getHiz() + 50);
				if (getVites() <= 5) {
					setVites(getVites() + 1);
				}
			}
		}
		else
			cout << "Lutfen once araci calistirin..." << endl;
	}
	void hiziAzalt() {
		if (getCalismaDurumu()) {
			if (getHiz() >= 50) {
				setHiz(getHiz() - 50);
				if (getVites() >= 2) {
					setVites(getVites() - 1);
				}
			}
		}
		else
			cout << "Lutfen once araci calistirin..." << endl;
	}
};




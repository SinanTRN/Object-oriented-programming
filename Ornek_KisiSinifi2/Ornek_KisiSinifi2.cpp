#include <iostream>
#include<string.h>
#include <string>
using namespace std;
class Kisi {
protected:
	string isim, soyisim, departman, pozisyon, ID;
	int maas, yil;
public:
	Kisi(string isim_, string soyisim_, string departman_, string pozisyon_, int maas_, int yil_) {
		isim = isim_; soyisim = soyisim_; departman = departman_;
		pozisyon = pozisyon_;maas = maas_; yil = yil_;
	}
	void setIsim(string isim_) { isim = isim_; }
	void setSoyisim(string soyisim_) { soyisim = soyisim_; }
	void setDep(string dep) { departman = dep; }
	void setPoz(string poz) { pozisyon = poz; }
	void setID(string ID_){ ID = ID_; }
	void setMaas(int maas_) { maas = maas_; }
	void setYil(int yil_) { yil = yil_; }
	string getIsım()const { return isim; }
	string getSoyisim()const { return soyisim; }
	string getDep()const { return departman; }
	string getPoz()const { return pozisyon; }
	string getID()const { return ID; }
	int getMaas()const { return maas; }
	int getYil()const { return yil; }
	void yazdir() {
		cout << "....................." << endl;
		cout << "Isim : " << isim << " " << soyisim << endl;
		cout << "Departman : " << departman << endl;
		cout << "Pozisyon : " << pozisyon << endl;
		cout << "Maas : " << maas << endl;
		cout << "Calistigi yil : " << yil << endl;
		cout << "ID number : " << ID << endl;

	}

};
class Calisan :public Kisi {
	int calisanBonusu;
protected:
	static int sayac;
public:
	Calisan(string isim_, string soyisim_, string departman_, string pozisyon_, int maas_, int yil_) :Kisi(isim_, soyisim_, departman_, pozisyon_, maas_, yil_) {
		calisanBonusu = 85 * yil;
		Calisan::setID("EMP" + to_string(sayac));
		sayac++;
	};
	void yazdir() {
		Kisi::yazdir();
		cout << "Calisan bonusu : " << calisanBonusu << endl;
	}
};
class Mudur :public Calisan {
	int managerBonus;
public:
	Mudur(string isim_, string soyisim_, string departman_, string pozisyon_, int maas_, int yil_) :Calisan(isim_, soyisim_, departman_, pozisyon_, maas_, yil_) {	 
		managerBonus = 100 * yil;
		Mudur::setID("MNG" + to_string(sayac));
	};
	void yazdir() {
		Kisi::yazdir();
		cout << "Mudur bonusu : " << managerBonus << endl;
	}
	
};

int Calisan::sayac =1;

int main()
{
	Mudur m1("Sinan", "Turan", "Muhendislik", "Ogrenci", 1250, 2);
	Mudur m2("Habibe", "Karagoz", "Muhendislik", "Ogrenci", 1250, 2);
	Calisan c1("Melisa", "Isik", "Muhendislik", "Ogrenci", 1250, 2);


	m1.yazdir();
	m2.yazdir();
	c1.yazdir();
}


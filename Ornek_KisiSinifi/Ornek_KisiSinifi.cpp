#include <iostream>
#include<string.h>
#include<time.h>
#include <iterator>
using namespace std;
class Kisi {
protected:
	string isim, soyisim;
	bool isAlphabetic(const string& str) {
		for (char c : str) {
			if (!isalpha(c)) {
				return false;
			}
		}
		return true;
	}
public:
	Kisi(string isim_ = "", string soyisim_ = "") {
		setIsım(isim_);
		setSoyisim(soyisim_);
		cout << "Kisi yapici metodu calisti" << endl;
	}
	string getIsım()const { return isim; }
	string getSoyisim() const { return soyisim; }
	void setIsım(string isim_) {
		if (isAlphabetic(isim_) == 1) {
			isim = isim_;
		}
		else { cout << "Lutfen ozel karakter Kullanmayin" << endl; }

	}
	void setSoyisim(string soyisim_) {
		if (isAlphabetic(soyisim_) == 1) {
			soyisim = soyisim_;
		}
		else { cout << "Lutfen ozel karakter Kullanmayin" << endl; }
	}
	void yazdir() {
		cout << "Kisinin adi soyadi : " << isim << " " << soyisim << endl;
	}

};
class Ogrenci:public Kisi {
private:
	string ID;
	int puan;
	bool passOrFail;
	bool containsOnlyDigits(const string& str) {
		for (char c : str) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}
public:
	Ogrenci();
	Ogrenci(string isim_, string soyisim_, string ID_):Kisi(isim_,soyisim_){
		setID(ID_);
		cout << "Ogrenci yapici metodu calisti." << endl;
	}
	string getID()const { return ID; }
	string getIsim() const { return isim; }
	string getSoyisim() const { return soyisim; }
	int getPuan()const { return puan; }
	bool kaldiMİ() const { return passOrFail; }
	void setID(string ID_) { 
		if (containsOnlyDigits(ID_) == 1) {
			ID = ID_;
		}
		else { cout << "Lutfen gecerli bir ID giriniz." << endl; }
	}
	void setPuan(int puan_ = 0) { puan = puan_; }
	void setGectiMİ(bool passFail) { passOrFail = passFail; }
	void yazdir() {
		cout << "......................" << endl;
		Kisi::yazdir();
		cout << "ID si : " << ID << "\n" << "Puani : " << puan << endl;
		cout << "......................" << endl;
	}
};
class Ogretmen :public Kisi {
	string departman;
public:
	Ogretmen(string name_, string surname_, string dep_): Kisi(name_,surname_) {
		setDep(dep_);
		cout << "Ogretmen yapici metodu calisti." << endl;
	}
	void setDep(string dep) { departman = dep; }
	string getDep()const { return departman; }
	void yazdir() {
		cout << "......................" << endl;
		Kisi::yazdir();
		cout << "Departmani : " << departman << endl;
		cout << "......................" << endl;
	}
	void ogrenciDrm(Ogrenci* OgrenciArray,int boyut) {
		//size_t boyut = sizeof(*OgrenciArray) / sizeof(OgrenciArray[0]);
		for (int i = 0; i < boyut; i++) {
			if (OgrenciArray[i].getPuan() >= 50) {
				OgrenciArray[i].setGectiMİ(true);
			}
			else{ OgrenciArray[i].setGectiMİ(false); }	
		}
	}
	void ogrenciBilgileri(Ogrenci* OgrenciArray,int boyut) {
		//size_t boyut = sizeof(*OgrenciArray) / sizeof(OgrenciArray[0]);
		cout << "Dersten kalma durumlari : " << endl;
		for (int i = 0; i < boyut; i++) {
			cout << OgrenciArray[i].getIsim() << " " << OgrenciArray[i].getSoyisim();
			cout << " : " << OgrenciArray[i].kaldiMİ()<<endl ;
		}

	}

};
int main()
{
	srand(time(NULL));

	Ogretmen t1("Salih", "Turk", "YTM");
	t1.yazdir();

	Ogrenci ogrenciler[] = { {"Sinan","Turan","1"},{"Habibe","Karagoz","2"},{"Melisa","Isik","3"} };
	size_t boyut1 = sizeof(ogrenciler) / sizeof(ogrenciler[0]);

	for (int i = 0; i < size(ogrenciler); i++) {
			ogrenciler[i].setPuan(rand()%100);
	}
	
	t1.ogrenciDrm(ogrenciler,boyut1);
	t1.ogrenciBilgileri(ogrenciler,boyut1);
	

}

#include <iostream>
using namespace std;
class Arac
{
	string  plaka;
	int girisSaati, cikisSaati, meblag;
	enum Boy boy;
	static int toplamMeblag;

public:
	static int sayac;
	Arac(string plaka,Boy boy,int gsaati);
	Arac(){}
	string getPlaka() { return plaka; }
	int getGSaati() { return girisSaati; }
	int getCSaati() { return cikisSaati; }
	Boy getBoy() { return boy; }
	int getMeblag() { return meblag; }
	static int getTMeblag() { return toplamMeblag; }
	void setPlaka(string _plaka) { plaka = _plaka; }
	void setGSaati(int _girisSaati) { girisSaati = _girisSaati; }
	void setCSaati(int _cikisSaati) { cikisSaati = _cikisSaati; }
	void setBoy(Boy _boy) { boy = _boy; }
	void setMeblag(int _meblag) { meblag = _meblag; }
	void hesapla(Arac &oth);

};

enum Boy { kucuk, orta, buyuk };

Arac::Arac(string plaka, Boy boy, int gsaati)
{
	setPlaka(plaka);
	setGSaati(gsaati);
	setBoy(boy);

}

void Araclariyazdir(Arac* araclar) {
	cout << "\n\n\nOtoparktaki araclar :" << endl;
	cout << "......................." << endl;
	for (int i = 0; i < Arac::sayac; i++) {
		cout << araclar[i].getPlaka() << endl;
		cout << "......................." << endl;
	}
}
void Arac::hesapla(Arac& oth)
{
	int x;
	int sure= oth.getCSaati() - oth.getGSaati();
	switch(oth.getBoy())
	{
	case 0:
		if (sure <= 3) {
			x = 4;
			oth.setMeblag(x);
			oth.toplamMeblag += x;
		}
		else  {
			int y = sure - 3;
			x = 4 + (y * 1);
			oth.setMeblag(x);
			oth.toplamMeblag += x;

		}
		break;
	case 1:
		if ( sure <= 3) {
			x = 6;
			oth.setMeblag(x);
			oth.toplamMeblag += x;

		}
		else {
			int y = sure - 3;
			x = 6 + (y * 2);
			oth.setMeblag(x);
			oth.toplamMeblag += x;

		}
		break;
	case 2:
		if ( sure <= 3) {
			x = 7;
			oth.setMeblag(x);
			oth.toplamMeblag += x;

		}
		else {
			int y = sure - 3;
			x = 7 + (y * 3);
			oth.setMeblag(x);
			oth.toplamMeblag += x;
		}
		break;
	default:
		cout << "Deger hesaplanamadi" << endl;
	}	
}

void KomutListesi() {
	cout << "Arac girisi icin  : 1" << endl;
	cout << "---------------------" << endl;
	cout << "Arac cikisi icin  : 2" << endl;
	cout << "---------------------" << endl;
	cout << "Sonlandirmak icin : 3" << endl;
	cout << "---------------------" << endl;
}

void AracGirisi(Arac* araclar) {
	
		string plaka;
		Boy boy;
		int saat, secim;
		cout << "------------------------------------------" << endl;
		cout << "Aracin plakasini giriniz: ";
		cin >> plaka;
		cout << "Aracin buyukulugunu giriniz(0:kucuk/1:orta/2:buyuk): ";
		cin >> secim;
		if (secim == 0) {
			boy = Boy::kucuk;
		}
		else if (secim == 1) {
			boy = Boy::orta;
		}
		else
			boy = Boy::buyuk;

		cout << "Aracin giris saatini giriniz: ";
		cin >> saat;
		cout << "\n";


		Arac arac(plaka, boy, saat);
		araclar[arac.sayac] = arac;
		Arac::sayac++;
}

void AracCikisi(Arac* araclar) {
	if (Arac::sayac != 0) {
		string CPlaka;
		Araclariyazdir(araclar);
		cout << "Lutfen cikis yapacak aracin plakasini giriniz : ";
		cin >> CPlaka;
		Arac result;
		int i;
		for (i = 0; i < Arac::sayac; i++) {
			if (araclar[i].getPlaka() == CPlaka) {
				result = araclar[i];
				break;
			}
		}
		int saat;
		cout << "Aracin cikis saatini giriniz : ";
		cin >> saat;
		result.setCSaati(saat);
		result.hesapla(result);
		cout << "\nAracin odemesi gereken meblag : " << result.getMeblag() << "TL\n\n\n" << endl;
		for (int j = i; j < Arac::sayac; j++) {
			araclar[j] = araclar[j + 1];
		}
		Arac::sayac--;
	}
	else
		cout << "\nOtoparkta arac yok!!!\n\n\n" << endl;


}
void Sonlandir() {

	cout << "\n\n\nToplam kazanc : " << Arac::getTMeblag() << "TL" << endl;
}

int Arac::sayac = 0;
int Arac::toplamMeblag = 0;

int main()
{
	int komut;
	bool devam = true;
	Arac araclar[20];
	do {
		KomutListesi();
		cout << "bir komut seciniz : ";
		cin >> komut;

		switch (komut) {
		case 1:
			if (Arac::sayac < 20) {
				AracGirisi(araclar);
			}
			else
				cout << "\nOtoparkta yer yok!!!\n\n\n" << endl;
			break;
		case 2:
			AracCikisi(araclar);
			break;
		case 3:
			Sonlandir();
			devam = false;
			break;

		default:
			cout << "\nYanlis komut girdiniz\n\n\n" << endl;
			break;
		}
	} while (devam);    
}


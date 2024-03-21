#include <iostream>
using namespace std;

class Mal
{
	string malAdi;
	int fiyat;
public:
	static int sayac;
	Mal(){}
	Mal(string ad,int fiyat);
	~Mal();
	void setMalAdi(string _malAdi) { malAdi = _malAdi; }
	string getMalAdi() { return malAdi; }

	void setFiyat(int _fiyat) { fiyat = _fiyat < 0 ? 0 : _fiyat; }
	int getFiyat() { return fiyat; }
};

Mal::Mal(string ad, int fiyat)
{
	setMalAdi(ad);
	setFiyat(fiyat);
}

Mal::~Mal()
{
}

class Musteri
{
	string musteriAdi;
	int promosyon, hesaplanmisOdeme, indirimliOdeme;
public:
	Mal sepet[30];

	Musteri(string ad="Bilinmiyor",int _promosyon=100,int _hesaplanmisOdeme=0,int _indirimliOdeme=0);
	
	void setMusteriAdi(string ad) { musteriAdi = ad; }
	string getMusteriAdi() { return musteriAdi; }
	
	void setPromosyon(int _promosyon) { promosyon = _promosyon > 100 || _promosyon < 0 ? 100 : _promosyon; }
	int getPromosyon() { return promosyon; }
	
	void setHesaplanmisOdeme(int tutar) { hesaplanmisOdeme = tutar; }
	int getHesaplanmisOdeme() { return hesaplanmisOdeme; }
	
	void setIndirimliOdeme(int tutar) { indirimliOdeme = tutar; }
	int getIndirimliOdeme() { return indirimliOdeme; }

	void malEkle();
	void malSil();
	void malListele();
};


Musteri::Musteri(string ad, int _promosyon, int _hesaplanmisOdeme , int _indirimliOdeme ) 
{
	setMusteriAdi(ad);
	setPromosyon(_promosyon);
	setHesaplanmisOdeme(_hesaplanmisOdeme);
	setIndirimliOdeme(_indirimliOdeme);
}

void Musteri::malEkle()
{
	if (Mal::sayac < 30) {
		cout << "Malin adini giriniz: ";
		string ad;
		cin >> ad;
		cout << "Urunun fiyatini giriniz: ";
		int fiyat;
		cin >> fiyat;
		Mal result(ad, fiyat);
		hesaplanmisOdeme += fiyat;
		indirimliOdeme += (fiyat * promosyon) / 100;
		sepet[Mal::sayac] = result;
		Mal::sayac++;
	}
	else cout << "Sepet Dolu!!!" << endl;
}

void Musteri::malSil()
{
	if (Mal::sayac != 0) {
		cout << "Lutfen sileceginiz urunun adini giriniz : ";
		string urun;
		cin >> urun;
		for (int i = 0; i < Mal::sayac; i++) {
			if (urun == sepet[i].getMalAdi()) {
				hesaplanmisOdeme -= sepet[i].getFiyat();
				indirimliOdeme -= (sepet[i].getFiyat() * promosyon) * 100;
				if (i == 30) {
					for (int j = i; j < Mal::sayac; j++) {
						sepet[j] = sepet[j + 1];
					}
				}
				Mal::sayac--;
				break;
			}
		}
		cout << "Urun sepetten kaldirildi..." << endl;
	}
	else cout << "Sepette urun bulunamadi" << endl;
}

void Musteri::malListele()
{
	cout << "Sepetteki urunlerin listesi : " << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < Mal::sayac; i++) {
		cout << "Urunun adi    : " << sepet[i].getMalAdi() << endl;
		cout << "Urunun fiyati : " << sepet[i].getFiyat() << endl;
		cout << "------------------------------" << endl;
	}
	cout << "Toplam tutar    : " <<hesaplanmisOdeme<<"TL" << endl;
	Mal::sayac != 0 ? cout << "Indirimli tutar : " << indirimliOdeme << "TL" << endl : cout << "Indirimli tutar : " << 0 << "TL" << endl;
		
}
void komutListesi() {
	cout << "(1)Mal ekle" << endl;
	cout << "------------------" << endl;
	cout << "(2)Mal sil" << endl;
	cout << "------------------" << endl;
	cout << "(3)Mallari listele" << endl;
	cout << "------------------\n" << endl;

}

int Mal::sayac = 0;
int main()
{
	Musteri m1("Ali", 80);
	Musteri m2("Ayse",20);
	Musteri m3;
	int musteri, komut;
	bool devam = true;
	do {
		cout << "\n(1)" << m1.getMusteriAdi() << endl;
		cout << "---------------------------" << endl;
		cout << "(2)" << m2.getMusteriAdi() << endl;
		cout << "---------------------------" << endl;
		cout << "(3)" << m3.getMusteriAdi() << endl;
		cout << "---------------------------" << endl;
		cout << "(4)Sonlandir" << endl;
		cout << "---------------------------\n" << endl;
		cout << "Lutfen Seciniz : ";
		cin >> musteri;
		switch (musteri)
		{
		case 1:
			komutListesi();
			cout << "Lutfen bir komut seciniz : ";
			cin >> komut;
			if (komut == 1)m1.malEkle();
			else if (komut == 2)m1.malSil();
			else if (komut == 3)m1.malListele();
			break;
		case 2:
			komutListesi();
			cout << "Lutfen bir komut seciniz : ";
			cin >> komut;
			if (komut == 1)m2.malEkle();
			else if (komut == 2)m2.malSil();
			else if (komut == 3)m2.malListele();
			break;
		case 3:
			komutListesi();
			cout << "Lutfen bir komut seciniz : ";
			cin >> komut;
			if (komut == 1)m3.malEkle();
			else if (komut == 2)m3.malSil();
			else if (komut == 3)m3.malListele();
			break;
		case 4:
			devam = false;
			break;
		default:
			cout << "Lutfen gecerli bir sayi giriniz!!!" << endl;
			break;
		}

	} while (devam);
}


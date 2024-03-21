#include <iostream>
using namespace std;
class Tarih{
	int gun, ay, yil;
	const int ayGunu[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const string aylar[13] = {"Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };
public:
	Tarih() { cout << "Yapici metod calisti" << endl; }
	Tarih(int g=1,int a=1,int y=1900) {
		setDate(g, a, y);		
		cout << "Yapici metod calisti" << endl; 
	}
	Tarih(const Tarih& x) {
		gun = x.gun;
		ay = x.ay;
		yil = x.yil;
		cout << "Kopyalama metodu calisti" << endl;
	}
	~Tarih() { cout << "Yikici metod calisti" << endl; }
	void setDate(int g = 1, int a = 1, int y = 1900) {
		if ((0 < g < 32) && (0 < a < 13) && (1900 < y)) {
			gun = g;
			ay = a;
			yil = y;
		}

	}
	void setGun(int g) { gun = g; }
	void setAy(int a) { ay = a; }
	void setYil(int y) { yil = y; }
	int getGun() const { return gun; }
	int getAy() const { return ay; }
	int getYil() const { return yil; }
	void yarin() { 
		if ((gun == 31)&&(ay!=12)||(gun==29)&&(ay==2)||(gun==30)&&(((ay == 4) || (ay == 6) || (ay == 9) || (ay == 11) ))) {
			gun = 1;
			ay += 1;
		}
		else if (gun == 31 && ay == 12) {
			gun = 1;
			ay = 1;
			yil += 1;
		}
		else { gun += 1; }
	}
	void yazdir() {
		cout << gun <<" " << aylar[ay-1]<< " " << yil << endl;
	}
	void karsilastir(const Tarih& x) {
		if ((yil < x.yil)||((yil == x.yil)&&(ay<x.ay))||((yil == x.yil) && (ay == x.ay)&&(gun<x.gun))) {
			cout << "Girdiginiz tarih daha bu tarihten daha ileri bir tarih" << endl;
		}
		else { cout << "Girdiginiz tarih daha bu tarihten daha geri bir tarih" << endl; }
	}
};
int main()
{
	Tarih t1(22, 1, 2004);
	t1.yazdir();
	Tarih t2(t1);
	cout << t2.getGun() << endl;
	cout << t2.getAy() << endl;
	cout << t2.getYil() << endl;
	t2.yarin();
	t2.yazdir();
	Tarih t3(31, 1, 2004);
	t3.setDate(30);
	t3.setAy(4);
	t3.setYil(2023);
	t3.yarin();
	t3.yazdir();
	t2.karsilastir(t1);
}


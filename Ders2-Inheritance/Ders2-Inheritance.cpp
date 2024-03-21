#include <iostream>
using namespace std;
// Polymorphism	: Nesnelerin farkli durumlar karsisinda farkli sonuclar uretmesi.
class anaClass {
protected://sadece alt sınıflardan erisilebilir
	
public:
	int x;
	int getX() const { return x; }
	void setX(int x_) { x = x_; }
	void yazdir() { cout <<"X : " << x << endl; }
	anaClass(int x_=0) {
		x = x_;
		cout << "anaClass Yapici metod calisti" << endl;
	}
	~anaClass() { cout << "anaClass Yikici metod calisti" << endl; }
	anaClass(const anaClass& a) {
		x = a.x;
		cout << "anaClass Kopyalama metodu calisti" << endl;
	}

};
class altClass :public anaClass {
	int y;
public:
	void setY(int y_) { y = y_; }
	int getY() const { return y; }
	void yazdir() { 
		anaClass::yazdir();
		cout <<"Y : "<< y << endl; }
	altClass() { cout << "Yapici metod calisti" << endl; }
	altClass(int x_, int y_) : anaClass(x_){
		y = y_;
		cout << "altClass Yapici metod calisti" << endl;
	}
	~altClass(){ cout << "altClass Yikici metod calisti" << endl; }
	altClass(const altClass& a_) {
		x = a_.x;
		y = a_.y;
		cout << "altClass kopyalama metodu calisti" << endl;
	}


};
class AClass {
public :
	AClass() { 
		cout << "AClass yapici metod calisti" << endl; 
	}
	~AClass() {
		cout << "AClass yikici metod calisti" << endl;  
	}
};
class BClass {
public:
	BClass() { 
		cout << "BClass yapici metod calisti" << endl; 
	}
	~BClass() { 
		cout << "BClass yikici metod calisti" << endl;  
	}
};
class CClass: public AClass,public BClass {
	CClass() {
		cout << "CClass yapici metod calisti" << endl;
	}
	~CClass() {
		cout << "CClass yikici metod calisti" << endl; 
	}
};


int main()
{

	//anaClass a2(8);
	//altClass a1(6,7);
	//a1.setX(5);// Alt Classta hicbir fonksiyon yok
	//a1.yazdirX();//Ama alt Class ana classin fonksiyonlarina da sahip.//Class uzerinde daha sonraki ornekler icin oynama yapildi.
	//
	//a1.setY(6);//Alt classlara miras aldiklari özelliklerden baska ozellikler de ekleyebiliriz.
	//a1.yazdirY();// Fakat eklenen ozellikler alt classa aittir.Ana class erisemez.

	
	
	//anaClass obj1(5);
	//altClass obj2(6,7);
	//cout << "..............." << endl;
	//altClass obj3(obj2);


	//CClass obj4();


	// FONKSIYONLARIN CIGNENMESİ
	
	// ana classta bulunan yazdır() fonksiyonuna altclassta olustururulan nesnemin de erisimi vardi.
	// alt classta ayni isimde ve ayni parametrede(parametre farkli olursa asiri yuklenme ornegi olur) 
	// bir fonksiyon yazarsam alt clastan  uretilmis bir nesnede fonksiyonu cagirdigimda ana classtaki 
	// fonksiyon yerine alt classdaki yazdir() fonksiyonu çalisir ve ana classdaki yazdir() fonksiyonu 
	// cignenmis olur. Bu duruma Fonksiyonlarin cignenmesi(Function Overriding) denir.
	
	
	//anaClass obj1(5);
	//altClass obj2(6,7);
	//cout << "..............." << endl;
	//altClass obj3(obj2);

	//obj1.yazdir();
	//obj2.yazdir();
}

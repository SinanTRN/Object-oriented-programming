#include <iostream>
using namespace std;
// fonksiyonlarin asiri yuklenmesi: isimleri ayni ama aldigi parametreler farkli fonksiyonlar 
// uretip fonksiyonun girdigim parametreye gore calismasi.
 class Student {

	 
	 float agno=0;
	 void puanHesapla(int not_) {
		 agno = float(not_) / 25;
	 }
	 string isim, soyisim, no;
 public:
	 
	 Student() {
		 cout << "parametresiz constructor calisti" << endl;
		 isim = "None";
		 soyisim = "None";
		 no = "None";

	 }
	 Student(string name){
		 cout << "1 parametreli constructor calisti" << endl;
		 isim = name;
		 soyisim = "None";
		 no = "None";
	 }
	 Student(string name,string surname) {
		 cout << "2 parametreli constructor calisti" << endl;

		 isim = name;
		 soyisim = surname;
		 no = "None";
	 }
	 Student(string name, string surname, string ID) {
		 cout << "3 parametreli constructor calisti" << endl;

		 isim = name;
		 soyisim = surname;
		 no = ID;

	 }
	 ~Student() {
		 cout << "Destructor calisti"<<endl;
	 }
	 Student(Student &x) {
		 cout << "Copy constructor calisti" << endl;
		 isim = x.isim;
		 soyisim = x.soyisim;
		 no = x.no;
	 }
	 void yazdir() {
		 cout << "Ogrencinin " << endl;
		 cout << "Ismi : " << isim << endl;
		 cout << "Soyismi : " << soyisim << endl;
		 cout << "Numarasi : " << no << endl;
		 cout << "Agnosu : " << agno << endl;
	 }
	 /* void setName(string name_) {
		 isim = name_;
		 
	 }
	 void setSurName(string surname_) {
		 soyisim = surname_;

	 }
	 void setNo(string no_) {
		 no = no_;

	 }*/

};
int main()
{
	cout << 1 % 7 << endl;
	//Student student1("Sinan","Turan","2207231062");//farkli parametrelerde farkli yapici metodlar olusturuyorum.
	//Student student2("Habibe", "Karagoz");//ve gieilen parametreye göre yapici metod calisiyor.
	//Student  student3("Melisa");//Fonksiyonların asiri yuklenmesine ornek. 
	//
	//student1.yazdir();
	//student2.yazdir();
	//student3.yazdir();
}

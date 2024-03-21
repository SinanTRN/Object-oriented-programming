#include <iostream>
using namespace std;
class Dizi {
protected:
	int *data, size, kapasite=5;
	int findIndex(int number, int a=0) {
		for (int i = a; i < size; i++) {
			if (data[i] == number) {
				return i;
			}
		}
		return -1;
	}
public:
	Dizi() {
		cout << "Array olusturuldu.kapasitesi : " << kapasite << endl;

	}
	Dizi(int x) {
		kapasite = x;
		size = 0;
		data = new int[kapasite];
		cout << "Array olusturuldu.kapasitesi : "<<kapasite << endl;
	}
	~Dizi() { 
		delete[] data;
		cout << "Distructor calisti" << endl; }
	Dizi(const Dizi& x) {
		kapasite = x.kapasite;
		size = x.size;
		data = new int[kapasite];
		for (int i = 0; i < x.size; i++) {
			data[i] = x.data[i];
		}
		cout << "CopyArray calisti" << endl;
	}
	int getSize() const { return size; }
	int getKapasite() const { return kapasite; }
	void addItem(int number) {
		if (size == kapasite) {			
			
			int* temp_Data = new int[kapasite*2];
			for (int i=0; i < size; i++) {
				temp_Data[i] = data[i];
			}
			delete[] data;
			data = temp_Data;
			kapasite *= 2;//Dizim doluysa kapasitesini 2 katına cikart
		}
		data[size] = number;
		size++;
	}
	void yazdir() {
		if (size != 0) {
			for (int i = 0; i < size; i++) {
				cout << data[i] <<" - ";
			}
		}
		cout << "\nKapasite : " << kapasite<<"  " << "Size : " << size << endl;
	}
	void removeIndex(int index) {
		if (index < 0 || index >= size) {
			cout << "HATA!! bu indexte bir eleman yok" << endl;
			return;
		}
		int a = data[index];
		for (int i = index; i < size-1; i++) {
			data[i] = data[i + 1];
		}
		size--;
		cout << a << " Elemani silindi" << endl;
	}
	void removeNumber(int number) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] == number) {
				for (int j = i; j < size - 1; j++) {
					data[j] = data[j + 1];
				}
				counter++;
				size--;
				i -= 1;
			}
		}		
		if (counter == 0) { cout << "Eleman dizide bulunamadi." << endl; }
		else cout << counter << " Tane eleman diziden cikarildi." << endl;
	}
	void findElement(int number, int index = 0) {
		int result = findIndex(number, index );
		if (result != -1) {
			cout << number << " Sayisi " << result << ". indexte bulundu" << endl;
		}
		else { cout << "Aranan eleman bulunamadi" << endl; }
	}
};
class SiraliDizi :public Dizi {
public:
	SiraliDizi(int x) :Dizi(x) {};
	SiraliDizi(const SiraliDizi& x) :Dizi(x) {};
	void addItem(int number) {
		if (size == kapasite) {
			int* temp_Data = new int[kapasite * 2];
			for (int i = 0; i < size; i++) {
				temp_Data[i] = data[i];
			}
			delete[] data;
			data = temp_Data;
			kapasite *= 2;//Dizim doluysa kapasitesini 2 katına cikart
		}
		int i;
		for ( i = size - 1; (i >= 0 && data[i] > number); i--) {
			data[i + 1] = data[i];
		}
		data[i+1] = number;
		size++;
	}
	void yazdir() {
		cout << "Sirali Dizi : " << endl;
		Dizi::yazdir();
	}
};
class SirasizDizi :public Dizi {
public:
	SirasizDizi(int x) :Dizi(x) {};
	SirasizDizi(const SirasizDizi& x) :Dizi(x) {};
	void yazdir() {
		cout << "Sirasiz Dizi : " << endl;
		Dizi::yazdir();
	}
};
int main()
{
	Dizi a(5);
	a.addItem(1);
	a.addItem(22);
	a.addItem(5);
	a.addItem(4);
	a.addItem(5);
	a.addItem(1);
	a.addItem(22);
	a.addItem(4);
	a.addItem(3);
	a.addItem(4);
	a.addItem(5);
	a.addItem(12);
	a.yazdir();
	a.removeNumber(12);
	a.findElement(22,2);
	a.yazdir();

	//Ornek 2

	//SirasizDizi ss1(10);
	//SiraliDizi sl1(10);

	//ss1.addItem(12);
	//ss1.addItem(2);
	//ss1.addItem(1);
	//ss1.addItem(13);
	//ss1.addItem(120);
	//ss1.addItem(123);
	//ss1.removeIndex(0);
	//ss1.yazdir();
	//cout << "............." << endl;
	//sl1.addItem(13);
	//sl1.addItem(12);
	//sl1.addItem(117);
	//sl1.addItem(33);
	//sl1.addItem(1);
	//sl1.addItem(3);
	//sl1.removeIndex(0);
	//sl1.yazdir();


	

}

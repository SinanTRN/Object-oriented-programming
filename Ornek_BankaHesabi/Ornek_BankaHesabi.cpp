#include <iostream>
#include <list>
#include <string>
using namespace std;

class BHesap {
    string isim, soyisim, telefon;
    float bakiye;

    static int sayac;
    int ID;

    bool isAlphabetic(const string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }

    bool containsOnlyDigits(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    friend ostream& operator<<(ostream& a, const BHesap& oth) {
        a << ".............\n" << "Kullanicinin ismi soyismi : " << oth.isim << " " << oth.soyisim <<
            "\n" << "Telefon Numarasi : " << oth.telefon << "\n" << "Bakiye : " << oth.bakiye << "\n" <<
            "Hesap numarasi : " << oth.ID << "\n............\n";
        return a;
    }
public:

    BHesap(string name_, string surname_, float bakiye_ = 0, string pNumber = " ") {
        int a = isAlphabetic(name_) && isAlphabetic(surname_);

        if (pNumber != " ") {
            int uzunluk = pNumber.length();
            int b = uzunluk == 11 && containsOnlyDigits(pNumber);
            if (b == 1) { telefon = pNumber; }
            else { cout << "Lutfen girilen bilgileri kontrol ediniz" << endl; }
        }

        if (a == 1) {
            isim = name_;
            soyisim = surname_;
            bakiye = bakiye_;
            ID = sayac;
            sayac++;
            cout << "Yapici metod calisti" << endl;
        }
        else {
            cout << "Lutfen girilen bilgileri kontrol ediniz" << endl;
        }
    }

    BHesap(const BHesap& x) {
        isim = x.isim;
        soyisim = x.soyisim;
        bakiye = x.bakiye;
        telefon = x.telefon;
        cout << "Kopyalama metodu calisti" << endl;
    }

    ~BHesap() { sayac--; cout << "Yikici metod calisti" << endl; }

    //void hesapBilgileri() {
    //    cout << "......................" << endl;
    //    cout << "Kullanicinin \n" << "Ismi Soyismi : " << isim << " " << soyisim << endl;
    //    cout << "Telefon numarasi : " << telefon << endl;
    //    cout << "Bakiyesi : " << bakiye << endl;
    //    cout << "Hesap no : " << ID << endl;
    //    cout << "......................" << endl;
    //}
    void operator-(int miktar) {
        if ((0 < miktar) && (miktar < bakiye)) {
            bakiye -= miktar;
            cout <<ID<<" numarali hesaptan " << miktar << "TL Miktarinda para cekildi " << endl;
        }
        else {
            cout << "Bakiye yetersiz" << endl;
        }
    }
 /*   void cekim(int miktar) {
        if ((0 < miktar) && (miktar < bakiye)) {
            bakiye -= miktar;
            cout << miktar << " Miktarinda para cekildi " << endl;
        }
        else {
            cout << "Bakiye yetersiz" << endl;
        }
    }*/
    void operator +(int miktar) {
        if (miktar > 0) {
            bakiye += miktar;
            cout << ID << " numarali hesaba " << miktar << "TL Miktarinda para yatirildi " << endl;
        }
    }
    //void yatir(int miktar) {
    //    if (miktar > 0) {
    //        bakiye += miktar;
    //    }
    //}

    void paraGonder(BHesap& x, int miktar) {
        if ((0 < miktar) && (miktar < bakiye)) {
            x.bakiye += miktar;
            this->bakiye -= miktar;
        }
    }

    void setName(string name) {
        if (isAlphabetic(name)) {
            isim = name;
        }
    }

    void setSurname(string surname) {
        if (isAlphabetic(surname)) {
            soyisim = surname;
        }
        else {
            cout << "Lutfen girilen bilgileri kontrol ediniz" << endl;
        }
    }

    void setPhone(string phone) {
        if (phone != " ") {
            int uzunluk = phone.length();
            int b = uzunluk == 11 && containsOnlyDigits(phone);
            if (b == 1) { telefon = phone; }
            else { cout << "Lutfen girilen bilgileri kontrol ediniz" << endl; }
        }
    }

    void setBakiye(float miktar) {
        if (0 < miktar) { bakiye += miktar; }
    }

    string getName() { return isim; }
    string getSurname() { return soyisim; }
    string getPhone() { return telefon; }
    float getBakiye() { return bakiye; }
};

int BHesap::sayac = 1;


int main() {
    BHesap k1("Sinan", "Turan", 150, "11111111111");
    BHesap k2("Habibe", "Karagoz", 150);
    BHesap k3("Melisa", "Isik");
    
    //normal yazdirma.
    //k1.hesapBilgileri();
    //k2.hesapBilgileri();
    //k2.paraGonder(k1, 50);
    //k1.hesapBilgileri();
    //k2.hesapBilgileri();

    //k3.hesapBilgileri();
    //k3.setName("Efe");
    //k3.setSurname("Hancer");
    //k3.hesapBilgileri();

    //cout << k1.getName() << " " << k1.getSurname() << endl;
    //cout << k1.getPhone() << endl;
    //cout << k1.getBakiye() << endl;

    //operator overloading
    cout << k1;
    cout << k2;
    k2.paraGonder(k1, 50);
    cout << k1;
    k1 + 100;
    cout << k1;
    k2 - 50;
    cout << k2;

    return 0;
}

#include <iostream>
#include<math.h>
using namespace std;
class ucgen {
    int a, b, c;
public:
    ucgen(int a_, int b_, int c_) {
        setValue(a_, b_, c_);
    }
    ucgen( const ucgen& x) {
        cout << "Copy constructor calisti" << endl;
        a = x.a;
        b = x.b;
        c = x.c;
    }
    ~ucgen(){
        cout << "Destructor calisti" << endl;

    }
    bool ucgenMi(int a,int b,int c ) {
        // a icin |c-b|<a< c+b
        // b icin |c-a|<b<c+a
        // c icin |b-a|<c<b+a
        if (!(abs(c - b) < a) && (a < (c + b))) return false;
        if (!(abs(c - a) < b) && (b < (c + a))) return false;
        if (!(abs(a - b) < c) && (c < (a + b))) return false;
        return true;
    }
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
    void setValue(int a_, int b_,int c_) {
        while (!ucgenMi(a_, b_, c_)) {
            cout << "Lutfen a-b-c kenarlarini giriniz " << endl;
            cin >> a_ >> b_ >> c_;
        }
        a = a_;
        b = b_;
        c = c_;
        cout << "Ucgen olusturuldu " << endl;
    }
    void cesit() {
        if ((a == b) && (a == c)) cout << "Eskenar bir ucgendir" << endl;
        if (((a != b) && (a != c))&&(b!=c)) cout << "cesitkenar bir ucgendir" << endl;
        else cout << "ikizkenar bir ucgendir"<<endl;
    }
    float Alan() {
        float alan,s;
        s = (a + b + c) / 2;
        alan = sqrt(s * (s - a) * (s - b) * (s - c));//Kenarlar yardimi ile alan hesaplama
        return alan;
    }
    int cevre() { return a + b + c; }

};
int main()
{
    int a, b, c;
    cout << "Lutfen ucgenin kenarlarini giriniz(a-b-c) : " << endl;
    cin >> a >> b >> c;
    ucgen u1(a,b,c);
    //ucgen u1 = {a,b,c};
    //ucgen u1 {a,b,c};
    ucgen u2 = u1; // copy constructor bu sekilde de calisir.Alternatifi: ucgen u2(u1);
    cout<<u1.getA()<<endl;
    cout<<u1.getB()<<endl;
    cout<<u1.getC()<<endl;
    cout << u1.Alan() << endl;
    cout << u1.cevre() << endl;

    u1.cesit();
    
    

    u2.setValue(12, 16, 20);
    cout << u2.getA()<< endl;
    cout << u2.getB()<< endl;
    cout << u2.getC()<< endl;
    
}


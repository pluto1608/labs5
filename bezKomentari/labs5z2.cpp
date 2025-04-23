#include <iostream>
#include <cstring>
using namespace std;

class kosarkar{
    private:
    char ime[30];
    int oPlata;
    public:
    kosarkar(const char *ime="",int oPlata=0){
        strncpy_s(this->ime,ime,29);
        this->oPlata=oPlata;
    }

    int getoPlata(void){return oPlata;}
    char* getIme(void){return ime;}

    ~kosarkar(){}
};

class ekipa{
    private:

    char ime[30];
    int brNaKosarkari=0,pPoeni=0,plata;
    kosarkar kosarkari[8];

    public:

    ekipa(const char *ime="",int brNaKosarkari=0,int pPoeni=0,kosarkar *kosarkari=NULL){
        strncpy_s(this->ime,ime,29);
        if(brNaKosarkari>this->brNaKosarkari)this->brNaKosarkari=brNaKosarkari;
        if(pPoeni>this->pPoeni){
            this->pPoeni=pPoeni;
            plata=pPoeni*50;
        }
        for(int i=0;i<brNaKosarkari;i++)this->kosarkari[i]=kosarkari[i];
    }
    void setpPoeni(int pPoeni){
        plata=pPoeni*50;
        this->pPoeni=pPoeni;
    }

    void pechatiPlata(kosarkar k){
        cout<<"Plata: "<<k.getoPlata()+plata<<endl;
    }

    void pechati(void){
        for(int i=0;i<brNaKosarkari;i++){
            cout<<"Ime: "<<kosarkari[i].getIme()<<endl;
            pechatiPlata(kosarkari[i]);
        }
    }
    
};

int main(){
    kosarkar k[5];
    char ime[30];
    int oPlata;
    for(int i=0;i<5;i++){
        cin>>ime>>oPlata;
        kosarkar temp(ime,oPlata);
        k[i]=temp;
    }
    ekipa nz("ne znam ne pratam kosarka",5,85,k);
    nz.pechati();
}
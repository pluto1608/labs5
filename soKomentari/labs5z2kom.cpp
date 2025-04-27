#include <iostream>
#include <cstring>
using namespace std;
//mislam deka nema nishto razlicno od prvata ako ima nesho nejasno pishete 💚
class kosarkar{
    private:
    char ime[30];
    int oPlata;
    public:
    kosarkar(const char *ime="",int oPlata=0){
        strncpy(this->ime,ime,29);
        this->ime[29] = '\0'; // napravi manuelno null-terminiranje na nizata karakteri
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
        strncpy(this->ime,ime,29);
        this->ime[29] = '\0'; // napravi manuelno null-terminiranje na nizata karakteri
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
    cout<<"I said the word crazy in front of my friend and now she keeps saying something about a rubber room "
    "filled with rats. I was confused so I asked her 'What the fuck?' but she turned into a giant rat and kept "
    "yelling about the rubber room. I tried to run to the cops and tell them there was a crazy rat following me, "
    "but then they also turned into big ass rats and bit off my dick. So then I called the fire department and "
    "told them what was happening and they said 'Damn bro, that's crazy.' Now I'm a fat rat and the military is "
    "chasing me down in helicopters. Anyone else with this issue?"<<endl;
    for(int i=0;i<5;i++){
        cin>>ime>>oPlata;
        kosarkar temp(ime,oPlata);
        k[i]=temp;
    }
    ekipa nz("ne znam ne pratam kosarka",5,85,k);
    nz.pechati();
}
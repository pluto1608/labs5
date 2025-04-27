#include <iostream>
#include <cstring>
using namespace std;

const int maksClenovi=10;

class velosipedist{
    private:
    int god,poeni;
    char imePrez[30];

    public:
    velosipedist(const char *imePrez="",int god=0,int poeni=0){//konstruktor moze odma da se
        //povika pri deklaracija na objekt
        strncpy(this->imePrez,imePrez,29);//this konkretizira deka se misli na promenlivata
        this->imePrez[29] = '\0'; // napravi manuelno null-terminiranje na nizata karakteri
        //koja pripaga na objektot a ne druga promenliva vo klasata
        this->god=god;this->poeni=poeni;//isto e kako da se vo posebni redovi samo zaso se
        //kratki gi staiv u ist red
    }

    void pechati(void){//tuka void ne prai nishto samo da znam deka namerno ne baram parametar a ne sum zaboraila
        cout<<"Ime i prezime: "<<imePrez<<endl;
        cout<<"Godini: "<<god<<endl;
        cout<<"Poeni: "<<poeni<<endl;
    }

    int getPoeni(void){return poeni;}

    ~velosipedist(){}//destruktor, se povikuva koga veke e izvrshen kodot kade se koristi objektot
};

class tim{
    private:
    char ime[30],sponzor[30];
    velosipedist clenovi[maksClenovi];
    int brNaClenovi;
    
    public:
    tim(const char *ime="",const char *sponzor="",velosipedist *clenovi=NULL,int brNaClenovi=0){
        strncpy(this->ime,ime,29);
        this->ime[29] = '\0'; // napravi manuelno null-terminiranje na nizata karakteri
        strncpy(this->sponzor,sponzor,29);
        this->sponzor[29] = '\0'; // napravi manuelno null-terminiranje na nizata karakteri
        if(brNaClenovi<=maksClenovi){
            for(int i=0;i<brNaClenovi;i++)this->clenovi[i]=clenovi[i];
        }
        this->brNaClenovi=brNaClenovi;
    }
    int poeni(void){
        int s=0;
        for(int i=0;i<brNaClenovi;i++)s+=clenovi[i].getPoeni();
        return s;
    }

    ~tim(){}
};

int main(){
    int brNaClenovi,god,poeni;
    char imePrez[30];
    cout<<"I fucked a hooker in GTA5, is it a relapse? I usually don't do this. I was afk and when I came"
    " back to my PlayStation I saw a hooker with her ass twerking next to my car and the urge was there so I"
    " went for it. Payed 100$ and now I feel bad. Is virtual sex counting as a fap or a relapse? 2 days streak "
    "atm btw."<<endl;
    cin>>brNaClenovi;
    velosipedist clenovi[brNaClenovi];
    //moze tuka da se dodade eden if za ako e pogolem brojot na clenovi od maks, me mrzi
    for(int i=0;i<brNaClenovi;i++){
        //redosledno se vnesuvaat
        cin>>imePrez>>god>>poeni;
        velosipedist temp(imePrez,god,poeni);
        clenovi[i]=temp;
    }
    tim neshto("ime","sponzor",clenovi,brNaClenovi);
    cout<<neshto.poeni()<<endl;
}
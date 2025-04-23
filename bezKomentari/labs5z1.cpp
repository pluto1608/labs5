#include <iostream>
#include <cstring>
using namespace std;

const int maksClenovi=10;

class velosipedist{
    private:
    int god,poeni;
    char imePrez[30];

    public:
    velosipedist(const char *imePrez="",int god=0,int poeni=0){
        strncpy_s(this->imePrez,imePrez,29);
        this->god=god;this->poeni=poeni;
    }

    void pechati(void){
        cout<<"Ime i prezime: "<<imePrez<<endl;
        cout<<"Godini: "<<god<<endl;
        cout<<"Poeni: "<<poeni<<endl;
    }

    int getPoeni(void){return poeni;}

    ~velosipedist(){}
};

class tim{
    private:
    char ime[30],sponzor[30];
    velosipedist clenovi[maksClenovi];
    int brNaClenovi;
    
    public:
    tim(const char *ime="",const char *sponzor="",velosipedist *clenovi=NULL,int brNaClenovi=0){
        strncpy_s(this->ime,ime,29);
        strncpy_s(this->sponzor,sponzor,29);
        if(brNaClenovi<=maksClenovi){
            for(int i=0;i<brNaClenovi;i++)this->clenovi[i]=clenovi[i];
        }
        this->brNaClenovi=brNaClenovi;
    }
    int poeni(void){
        int s=0;
        for(int i=0;i<brNaClenovi;i++){
            s+=clenovi[i].getPoeni();
            cout<<clenovi[i].getPoeni()<<endl;
        }
        return s;
    }

    ~tim(){}
};

int main(){
    int brNaClenovi,god,poeni;
    char imePrez[30];
    cin>>brNaClenovi;
    velosipedist clenovi[brNaClenovi];
    for(int i=0;i<brNaClenovi;i++){
        cin>>imePrez>>god>>poeni;
        velosipedist temp(imePrez,god,poeni);
        clenovi[i]=temp;
    }
    tim neshto("ime","sponzor",clenovi,brNaClenovi);
    cout<<neshto.poeni()<<endl;
}
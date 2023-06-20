#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template <class H>
class Heap{
    private:
        int nodi;
        int chiamate;
        H* vett;
        int maxdim;

        int left(int i){return i*2;}
        int right(int i){return ((i*2)+1);}
        int parent(int i){return i/2;}

    public:
        Heap(int dim): maxdim(dim){
            vett= new H[maxdim];
            chiamate=0;
            nodi=0;
        }

        void Heapify(int i){
            if(nodi>=1) chiamate++;
            int l= left(i);
            int r= right(i);
            int max=i;
            if(l<=nodi && vett[l]>vett[max]){max=l;}
            if(r<=nodi && vett[r]>vett[max]){max=r;}
            if(i!=max){
                swap(vett[i], vett[max]);
                Heapify(max);
            }
        }
        void Insert(H x){
            nodi++;
            vett[nodi]= x;
            int i=nodi;
            while(i>1 && vett[parent(i)]<vett[i]){
                swap(vett[parent(i)], vett[i]);
                i=parent(i);
            }
        }

        void Extract(){
            swap(vett[1], vett[nodi]);
            nodi--;
            Heapify(1);
        }

        int getchiamate(){return chiamate;}

        void stamp(){
            for(int i=1; i<=nodi; i++){
                out<<vett[i]<<" ";
            }
            out<<endl;
        }
};

int main(){
    for(int i=0; i<100; i++){
        string type; in>> type;
        int n; in>>n;

        if(type=="int"){
            Heap<int>* h= new Heap<int>(n);
            for(int j=0; j<n; j++){
                string tmp; in>> tmp;
                if(tmp=="extract") h->Extract();
                else{
                    int valore= stoi(tmp.substr(2,tmp.length()));
                    h->Insert(valore);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }

        if(type=="bool"){
            Heap<bool>* h= new Heap<bool>(n);
            for(int j=0; j<n; j++){
                string tmp; in>> tmp;
                if(tmp=="extract") h->Extract();
                else{
                    bool valore= stoi(tmp.substr(2,tmp.length()));
                    h->Insert(valore);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }

        if(type=="double"){
            Heap<double>* h= new Heap<double>(n);
            for(int j=0; j<n; j++){
                string tmp; in>> tmp;
                if(tmp=="extract") h->Extract();
                else{
                    double valore= stod(tmp.substr(2,tmp.length()));
                    h->Insert(valore);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }

        if(type=="char"){
            Heap<char>* h= new Heap<char>(n);
            for(int j=0; j<n; j++){
                string tmp; in>> tmp;
                if(tmp=="extract") h->Extract();
                else{
                    char valore= tmp[2];
                    h->Insert(valore);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }
    }
}
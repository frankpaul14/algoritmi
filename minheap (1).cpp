#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template<class H>
class Heap{
    private:
        int nodi;
        int chiamate;
        int maxdim;
        H* vett;

        int left(int i){return i*2;}
        int right(int i){return ((i*2)+1);}
        int parent(int i){return i/2;}

    public:
        Heap(int dim): maxdim(dim){
            chiamate=0;
            nodi=0;
            vett= new H[maxdim];
        }

        void Heapify(int i){
            if(nodi>=1) chiamate++;
            int l=left(i);
            int r=right(i);
            int min=i;
            if(l<=nodi && vett[l]<vett[min]){min=l;}
            if(r<=nodi && vett[r]<vett[min]){min=r;}
            if(i!=min){
                swap(vett[min],vett[i]);
                Heapify(min);
            }
        }
        void Insert(H x){
            nodi++;
            vett[nodi]= x;
            int i=nodi;
            while(i>1 && vett[parent(i)]>vett[i]){
                swap(vett[parent(i)], vett[i]);
                i=parent(i);
            }
        }
        void Extract(){
            swap(vett[1], vett[nodi]);
            nodi--;
            Heapify(1);
        }
        void stamp(){
            for(int i=1; i<=nodi; i++){
                out<<vett[i]<<" ";
            }
            out<<endl;
        }

        int getchiamate(){
            return chiamate;
        }
};

int main(){
    for(int i=0; i<100; i++){
        string type; in>>type;
        int n; in>>n;
        if(type=="int"){
            Heap<int>* h= new Heap<int>(n);
            for(int j=0; j<n; j++){
                string val; in>>val;
                if(val=="extract") h->Extract();
                else{
                    int x= stoi(val.substr(2, val.length()));
                    h->Insert(x);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }
        if(type=="bool"){
            Heap<bool>* h= new Heap<bool>(n);
            for(int j=0; j<n; j++){
                string val; in>>val;
                if(val=="extract") h->Extract();
                else{
                    bool x= stoi(val.substr(2, val.length()));
                    h->Insert(x);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }
        if(type=="double"){
            Heap<double>* h= new Heap<double>(n);
            for(int j=0; j<n; j++){
                string val; in>>val;
                if(val=="extract") h->Extract();
                else{
                    double x= stod(val.substr(2, val.length()));
                    h->Insert(x);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }
        if(type=="char"){
            Heap<char>* h= new Heap<char>(n);
            for(int j=0; j<n; j++){
                string val; in>>val;
                if(val=="extract") h->Extract();
                else{
                    char x= val[2];
                    h->Insert(x);
                }
            }
            out<<h->getchiamate()<<" ";
            h->stamp();
            delete h;
        }
    }
}
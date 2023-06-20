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
        int left(int i){return i*2;}
        int right(int i){return ((i*2)+1);}
        int parent(int i){return i/2;}
    public:
        Heap(){
            nodi=0;
            chiamate=0;
        }
        void heapify(int i){
            if(nodi>=1) chiamate++;
            int l=left(i);
            int r=right(i);
            int max=i;
            if(l<=nodi && vett[l]>vett[max]){max=l;}
            if(r<=nodi && vett[r]>vett[max]){max=r;}
            if(max!=i){
                swap(vett[max], vett[i]);
                heapify(max);
            }
        }
        void build(H* x, int n){
            vett=x;
            nodi=n;
            for(int i=nodi/2; i>0; i--){
                heapify(i);
            }
        }
        void extract(){
            int n=nodi;
            for(int i=1; i<=n; i++){
                swap(vett[nodi], vett[1]);
                nodi--;
                heapify(1);
            }
        }
        void getchiamate(){
            out<<chiamate<<endl;
        }
};
int main(){
    for(int i=0; i<100; i++){
        string type; in>>type;
        int n; in>>n;
        if(type=="int"){
            Heap<int>* h= new Heap<int>();
            int* vett= new int[n+1];
            for(int j=1; j<=n; j++){
                in>>vett[j];
            }
            h->build(vett,n);
            h->extract();
            h->getchiamate();
            delete h;
            delete []vett;
        }
        if(type=="bool"){
            Heap<bool>* h= new Heap<bool>();
            bool* vett= new bool[n+1];
            for(int j=1; j<=n; j++){
                in>>vett[j];
            }
            h->build(vett,n);
            h->extract();
            h->getchiamate();
            delete h;
            delete []vett;
        }
        if(type=="double"){
            Heap<double>* h= new Heap<double>();
            double* vett= new double[n+1];
            for(int j=1; j<=n; j++){
                in>>vett[j];
            }
            h->build(vett,n);
            h->extract();
            h->getchiamate();
            delete h;
            delete []vett;
        }
        if(type=="char"){
            Heap<char>* h= new Heap<char>();
            char* vett= new char[n+1];
            for(int j=1; j<=n; j++){
                in>>vett[j];
            }
            h->build(vett,n);
            h->extract();
            h->getchiamate();
            delete h;
            delete []vett;
        }
    }
}
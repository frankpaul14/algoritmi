#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template<class H>
class Heap{
    private:
        int nodi;
        H* vett;

        int left(int i){return i*2;}
        int right(int i){return ((i*2)+1);}
        int parent(int i){return i/2;}

    public:
        Heap(){
            nodi=0;
        }

        void Heapify(int i){
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

        void Build(H* x, int n){
            vett= x;
            nodi= n;
            for(int i=nodi/2; i>=1; i--){
                Heapify(i);
            }
        }
        
        void stamp(){
            for(int i=1; i<=nodi; i++){
                out<<vett[i]<<" ";
            }
            out<<endl;
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
                int tmp; in>>tmp;
                vett[j]= tmp;
            }
            h->Build(vett,n);
            h->stamp();
            delete h;
            delete [] vett;
        }

        if(type=="bool"){
            Heap<bool>* h= new Heap<bool>();
            bool* vett= new bool[n+1];
            for(int j=1; j<=n; j++){
                bool tmp; in>>tmp;
                vett[j]= tmp;
            }
            h->Build(vett,n);
            h->stamp();
            delete h;
            delete [] vett;
        }

        if(type=="double"){
            Heap<double>* h= new Heap<double>();
            double* vett= new double[n+1];
            for(int j=1; j<=n; j++){
                double tmp; in>>tmp;
                vett[j]= tmp;
            }
            h->Build(vett,n);
            h->stamp();
            delete h;
            delete [] vett;
        }

        if(type=="char"){
            Heap<char>* h= new Heap<char>();
            char* vett= new char[n+1];
            for(int j=1; j<=n; j++){
                char tmp; in>>tmp;
                vett[j]= tmp;
            }
            h->Build(vett,n);
            h->stamp();
            delete h;
            delete [] vett;
        }
    }
}
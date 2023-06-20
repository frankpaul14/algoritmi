#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template<class H>
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

        void Heapify(int i){
            if(nodi>=1) chiamate++;
            int l=left(i);
            int r=right(i);
            int min=i;
            if(l<=nodi && vett[l]<vett[min]){min=l;}
            if(r<=nodi && vett[r]<vett[min]){min=r;}
            if(min!=i){
                swap(vett[min],vett[i]);
                Heapify(min);
            }
        }

        void Build(H* x, int n){
            vett=x;
            nodi=n;
            for(int i=nodi/2; i>=1; i--){
                Heapify(i);
            }
        }

        H extract(){
            swap(vett[1],vett[nodi]);
            nodi--;
            Heapify(1);
            return vett[nodi+1];
        }

        void getChiamate(){
            out<<chiamate<<" ";
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
                vett[j]=tmp;
            }
            h->Build(vett,n);
            int* extr= new int[n+1];
            for(int j=n; j>=1; j--){
                extr[j]= h->extract();
            }
            h->getChiamate();
            for(int j=1; j<=n; j++){
                out<<extr[j]<<" ";
            }
            out<<endl;
            delete h;
            delete []vett;
            delete []extr;
        }
        if(type=="bool"){
            Heap<bool>* h= new Heap<bool>();
            bool* vett= new bool[n+1];
            for(int j=1; j<=n; j++){
                bool tmp; in>>tmp;
                vett[j]=tmp;
            }
            h->Build(vett,n);
            bool* extr= new bool[n+1];
            for(int j=n; j>=1; j--){
                extr[j]= h->extract();
            }
            h->getChiamate();
            for(int j=1; j<=n; j++){
                out<<extr[j]<<" ";
            }
            out<<endl;
            delete h;
            delete []vett;
            delete []extr;
        }
        if(type=="double"){
            Heap<double>* h= new Heap<double>();
            double* vett= new double[n+1];
            for(int j=1; j<=n; j++){
                double tmp; in>>tmp;
                vett[j]=tmp;
            }
            h->Build(vett,n);
            double* extr= new double[n+1];
            for(int j=n; j>=1; j--){
                extr[j]= h->extract();
            }
            h->getChiamate();
            for(int j=1; j<=n; j++){
                out<<extr[j]<<" ";
            }
            out<<endl;
            delete h;
            delete []vett;
            delete []extr;
        }
        if(type=="char"){
            Heap<char>* h= new Heap<char>();
            char* vett= new char[n+1];
            for(int j=1; j<=n; j++){
                char tmp; in>>tmp;
                vett[j]=tmp;
            }
            h->Build(vett,n);
            char* extr= new char[n+1];
            for(int j=n; j>=1; j--){
                extr[j]= h->extract();
            }
            h->getChiamate();
            for(int j=1; j<=n; j++){
                out<<extr[j]<<" ";
            }
            out<<endl;
            delete h;
            delete []vett;
            delete []extr;
        }
    }
}
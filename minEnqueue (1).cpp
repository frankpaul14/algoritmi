#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

template <class H>
class Heap{
    private:
        int nodi;
        int maxdim;
        H* vett;

        int left(int i){return i*2;}
        int right(int i){return ((i*2)+1);}
        int parent(int i){return i/2;}

    public:
        Heap(int dim): maxdim(dim){
            nodi=0;
            vett= new H[maxdim];
        }
        
        void Insert(H x){
            nodi++;
            vett[nodi]=x;
            int i=nodi;
            while(i>1 && vett[parent(i)]>vett[i]){
                swap(vett[parent(i)], vett[i]);
                i= parent(i);
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
            Heap<int>* h= new Heap<int>(n+1);
            for(int j=1; j<=n; j++){
                int tmp; in>>tmp;
                h->Insert(tmp);
            }
            h->stamp();
            delete h;
        }
        if(type=="bool"){
            Heap<bool>* h= new Heap<bool>(n+1);
            for(int j=1; j<=n; j++){
                bool tmp; in>>tmp;
                h->Insert(tmp);
            }
            h->stamp();
            delete h;
        }
        if(type=="double"){
            Heap<double>* h= new Heap<double>(n+1);
            for(int j=1; j<=n; j++){
                double tmp; in>>tmp;
                h->Insert(tmp);
            }
            h->stamp();
            delete h;
        }
        if(type=="char"){
            Heap<char>* h= new Heap<char>(n+1);
            for(int j=1; j<=n; j++){
                char tmp; in>>tmp;
                h->Insert(tmp);
            }
            h->stamp();
            delete h;
        }
    }
}
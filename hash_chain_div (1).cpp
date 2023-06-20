#include <iostream>
#include <fstream>
#include <list>
using namespace std;

template <class H>
class Hashdiv{
    private:
        int size;
        int posizioni;
        list<H>* table;

    public:
        Hashdiv<H>(int x){
            posizioni= x;
            size= 0;
            table= new list<H>[posizioni];
        }

        int funzpos(H x){
            int p= ((int)x)%posizioni;
            return p;
        }

        int insertdiv(H x){
            int pos= this-> funzpos(x);
            table[pos].push_back(x);
            size++;
            return pos;
        }
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int i=0; i<100; i++){
        string type; in>>type;
        int npos; in>>npos;
        int nkey; in>>nkey;
        if(type=="int"){
            Hashdiv<int>* h= new Hashdiv<int>(npos);
            int a[npos];
            for(int j=0; j<npos; j++){
                a[j]=0;
            }
            for(int j=0; j<nkey; j++){
                int val;
                in>>val;
                int post=h->insertdiv(val);
                a[post]++;
            }
            for(int j=0; j<npos; j++){
                out<<a[j]<<" ";
            }
        }

        if(type=="bool"){
            Hashdiv<bool>* h= new Hashdiv<bool>(npos);
            int a[npos];
            for(int j=0; j<npos; j++){
                a[j]=0;
            }
            for(int j=0; j<nkey; j++){
                bool val;
                in>>val;
                int post=h->insertdiv(val);
                a[post]++;
            }
            for(int j=0; j<npos; j++){
                out<<a[j]<<" ";
            }
        }

        if(type=="double"){
            Hashdiv<double>* h= new Hashdiv<double>(npos);
            int a[npos];
            for(int j=0; j<npos; j++){
                a[j]=0;
            }
            for(int j=0; j<nkey; j++){
                double val;
                in>>val;
                int post=h->insertdiv(val);
                a[post]++;
            }
            for(int j=0; j<npos; j++){
                out<<a[j]<<" ";
            }
        }

        if(type=="char"){
            Hashdiv<char>* h= new Hashdiv<char>(npos);
            int a[npos];
            for(int j=0; j<npos; j++){
                a[j]=0;
            }
            for(int j=0; j<nkey; j++){
                char val;
                in>>val;
                int post=h->insertdiv(val);
                a[post]++;
            }
            for(int j=0; j<npos; j++){
                out<<a[j]<<" ";
            }
        }
        out<<endl;
    }
}
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template<class H>
class MultHash{
    private:
        int slot;
        int size;
        double c;
        list<H>* table;

        int compute(H x){
            double y= x*c;
            double a= y-(int)y;
            int h=(int)(a*this->getSlotNumber());
            return h;
        }
    
    public:
        MultHash<H>(int x){
            this->slot= x;
            table= new list<H>[slot];
            size=0;
            c=0.61803;
        }
        int getSlotNumber(){
            return slot;
        }
        int getSize(){
            return size;
        }
        int insertKey(H key){
            int pos=compute(key);
            table[pos].push_back(key);
            size++;
            return pos;
        }
};

int main(){
    for(int i=0; i<100; i++){
        string type; in>>type;
        int numero_bucket; in>>numero_bucket;
        int numero_key; in>>numero_key;
        if(type=="int"){
            MultHash<int>* h= new MultHash<int>(numero_bucket);
            int a[numero_bucket];
            for(int j=0; j<numero_bucket; j++){
                a[j]=0;
            }
            for(int j=0; j<numero_key; j++){
                int tmp;
                in>>tmp;
                int pos= h->insertKey(tmp);
                a[pos]++;
            }
            for(int j=0; j<numero_bucket; j++){
                out<<a[j]<<" ";
            }
        }
        if(type=="bool"){
            MultHash<bool>* h= new MultHash<bool>(numero_bucket);
            int a[numero_bucket];
            for(int j=0; j<numero_bucket; j++){
                a[j]=0;
            }
            for(int j=0; j<numero_key; j++){
                bool tmp;
                in>>tmp;
                int pos= h->insertKey(tmp);
                a[pos]++;
            }
            for(int j=0; j<numero_bucket; j++){
                out<<a[j]<<" ";
            }
        }
        if(type=="double"){
            MultHash<double>* h= new MultHash<double>(numero_bucket);
            int a[numero_bucket];
            for(int j=0; j<numero_bucket; j++){
                a[j]=0;
            }
            for(int j=0; j<numero_key; j++){
                double tmp;
                in>>tmp;
                int pos= h->insertKey(tmp);
                a[pos]++;
            }
            for(int j=0; j<numero_bucket; j++){
                out<<a[j]<<" ";
            }
        }
        if(type=="char"){
            MultHash<char>* h= new MultHash<char>(numero_bucket);
            int a[numero_bucket];
            for(int j=0; j<numero_bucket; j++){
                a[j]=0;
            }
            for(int j=0; j<numero_key; j++){
                char tmp;
                in>>tmp;
                int pos= h->insertKey(tmp);
                a[pos]++;
            }
            for(int j=0; j<numero_bucket; j++){
                out<<a[j]<<" ";
            }
        }
        out<<endl;
    }
}
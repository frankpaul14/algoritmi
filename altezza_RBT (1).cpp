#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

#define B 0
#define R 1

template<class H>
class Nodo{
    public:
        Nodo<H> *sx,*dx,*p;
        H key;
        bool color;
        Nodo(H key): key(key), sx(NULL), dx(NULL), p(NULL), color(R){}
};

template<class H>
class RBT{
    private:
        Nodo<H>* root;
        int _altezza(Nodo<H>* n){
            if(n==NULL) return 0;
            int dx= _altezza(n->dx);
            int sx= _altezza(n->sx);
            return 1+max(sx,dx);
        }

    public:
        RBT(): root(NULL){}

        void trapianta(Nodo<H>* x,Nodo<H>* y){
            if(x->p==NULL) root=y;
            else if(x->p->dx==x) x->p->dx= y;
            else x->p->sx= y;

            if(y!=NULL) y->p=x->p;
        }

        void Rleft(Nodo<H>* x){
            if(x!=NULL){
                Nodo<H>* y= x->dx;
                if(y!=NULL){
                    x->dx= y->sx;
                    if(x->dx!= NULL) x->dx->p= x;
                }
                trapianta(x,y);
                y->sx= x;
                x->p= y;
            }
        }

        void Rright(Nodo<H>* x){
            if(x!=NULL){
                Nodo<H>* y=x->sx;
                if(y!=NULL){
                    x->sx= y->dx;
                    if(x->sx!=NULL) x->sx->p= x;
                }
                trapianta(x,y);
                y->dx= x;
                x->p= y;
            }
        }

        void insert_fixup(Nodo<H>* nuovo){
            if(nuovo->p!=NULL && nuovo->p->color==B) return;
            if(root==nuovo){
                nuovo->color= B;
                return;
            }
            Nodo<H>* padre= nuovo->p;
            Nodo<H>* nonno= padre->p;
            Nodo<H>* zio= nonno->dx;
            if(nonno->dx== padre) zio= nonno->sx;

            if(zio!=NULL && zio->color==R){
                zio->color= B;
                padre->color= B;
                nonno->color= R;
                insert_fixup(nonno);
                return;
            }

            if(nonno->sx==padre){
                if(padre->dx== nuovo){
                    Rleft(padre);
                    padre= nuovo;
                    nuovo= padre->sx;
                }
                Rright(nonno);
                nonno->color= R;
                padre->color= B;
                return;
            }
            else{
                if(padre->sx== nuovo){
                    Rright(padre);
                    padre= nuovo;
                    nuovo= padre->dx;
                }
                Rleft(nonno);
                nonno->color= R;
                padre->color= B;
                return;
            }
        }

        void insert(H x){
            Nodo<H>* nuovo= new Nodo<H>(x);
            Nodo<H>* r= root;
            Nodo<H>* tmp=NULL;
            while(r!=NULL){
                tmp=r;
                if(x>= r->key) r=r->dx;
                else r= r->sx;
            }
            nuovo->p= tmp;
            if(tmp==NULL) root=nuovo;
            else if(x>= tmp->key) tmp->dx= nuovo;
            else tmp->sx= nuovo;
            insert_fixup(nuovo);
        }

        int altezza(){
            return _altezza(root);
        }
};

int main(){
    for(int i=0; i<100; i++){
        string type;
        in>> type;
        int n;
        in>>n;
        if(type=="int"){
            RBT<int>* t= new RBT<int>();
            for(int j=0; j<n; j++){
                int a;
                in>> a;
                t->insert(a);
            }
            out<<t->altezza()<<endl;
        }
        else{
            RBT<double>* t= new RBT<double>();
            for(int j=0; j<n; j++){
                double a;
                in>>a;
                t->insert(a);
            }
            out<<t->altezza()<<endl;
        }
    }
}
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

class Edge{
public:
	int s, f, peso;

	Edge(){ s=f=peso=0;}

	Edge(int s, int f, int peso){
		this->s=s;
		this->f=f;
		this->peso=peso;
	}
};

template <class H>
class Grafo{
public:
	H* K;
	Edge** M;
	int len, n, m, nEdges;

	int findIndex(H x){
		int i=0;
		while(i<n && K[i] != x )
			++i;
		if(!(i<n))
			return -1;
		return i;
	}

	int getMin(int *pesi){
		int min=-1;

		for(int k=1; k<n; k++){
			if(pesi[k-1] > pesi[k])
				min=k;
		}
		return min;
	}

	Grafo(int len){
		this->len=len;
		n=m=0;
		nEdges=len*len;
		M=new Edge*[nEdges];
		K=new H[len];
	}

	void addNode(H x){
		K[n]=x;
		n++;
	}

	void addEdge(H x, H y, int p){
		int i=findIndex(x);
		int j=findIndex(y);

		M[m]=new Edge(i, j, p);
		m++;
	}

	string Dijkstra(H sorgente, H destinazione){
		string res="inf.";

		int start=findIndex(sorgente);
		int end=findIndex(destinazione);

		int* precedente=new int[len];
		int tmp;

		int* pesi=new int[len];

		for(int i=0; i<len; i++){
			pesi[i]=INT_MAX;
			precedente[i]=INT_MAX;
		}

		pesi[start]=0;
		precedente[start]=-1;

		for(int i=0; i<len; i++){
			tmp=getMin(pesi);

			for(int j=0; j<m; j++){
				if(pesi[M[j]->s] != INT_MAX && pesi[M[j]->s] + M[j]->peso < pesi[M[j]->f]){
					precedente[M[j]->f]=tmp;
					pesi[M[j]->f]=pesi[M[j]->s] + M[j]->peso;
				}
			}
		}
		if(pesi[end] != INT_MAX)
			res=to_string(pesi[end]);
		return res;
	}
};

template <class H>
void esec(Grafo<H>* g, H s, H f, int p, int N, int M){
	char tmp;
	for(int i=0; i<N; i++){
		in>>s;
		g->addNode(s);
	}

	for(int i=0; i<M; i++){
		in>>tmp;
		in>>s>>f>>p;
		in>>tmp;
		g->addEdge(s, f, p);
	}
	in>>s>>f;
	out<<g->Dijkstra(s, f)<<endl;
}

int main(){
for(int i=0; i<100; i++){
	int n, m, p;
	string type;
	in>>n>>m>>type;

	if(type=="int"){
		Grafo<int>* g=new Grafo<int>(n);
		int s, f;
		esec(g, s, f, p, n, m);
	}
	else if(type=="double"){
		Grafo<double>* g=new Grafo<double>(n);
		double s, f;
		esec(g, s, f, p, n, m);
	}
}
}
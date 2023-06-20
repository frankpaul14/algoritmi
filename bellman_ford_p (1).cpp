#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Edge
{
public: 
	int s,f,p;
	Edge(int s,int f,int p) : s(s) , f(f) , p(p) {}
};

class Grafo
{
private:
	int size, n, m;
	Edge ** M;
public:
	Grafo(int n) : n(n)
	{
		size = 1000;
		m = 0;
		M = new Edge*[size];
		for(int i=0; i<size; i++) M[i] = NULL;
	}

	void addEdge(int i, int j, int w)
	{
		M[m++] = new Edge(i,j,w);
	}

	void BellmanFordP(int s, int d, int k)
	{
		int source = s;
		int dest = d;

		int dist[n];
		for(int i=0; i<n; i++) dist[i] = INT_MAX;
		dist[source] = 0;

		for(int i=1; i<k+1; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(M[j] != NULL)
				{
					int u = M[j]->s;
					int v = M[j]->f;
					int w = M[j]->p;
					if(dist[u]!=INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
				}
			}
		}

		if(dist[dest] == INT_MAX) fout<<"inf."<<endl;
		else fout<<dist[dest]<<endl;
	}
};

int main()
{
	for(int j=0; j<100; j++)
	{
		int n,m,k; fin>>n>>m>>k;
		Grafo* G = new Grafo(n);
		char tmp;
		
		for(int i=0; i<m; i++)
		{
			int s,f,w;
			fin>>tmp>>s>>f>>w>>tmp;
			G->addEdge(s,f,w);
		}
		int s,f;
		fin>>s>>f;
		G->BellmanFordP(s,f,k);
	}
}
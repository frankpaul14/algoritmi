#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("input.txt");
ofstream out("output.txt");

class Activity{
    public:
        int s,f,profit;
        Activity(int s, int f): s(s), f(f){
            profit= f-s;
        }
};

void sort_activity(Activity** a, int n){
    for(int i=0;i<n; i++){
        for(int j=i+1;j<n;j++){
            if(a[i]->f > a[j]->f) swap(a[i],a[j]);
                    //se i tempi sono uguali guardiamo l'inizio che se è minore e quindi i dura di più di j allora swap
            else if(a[i]->f == a[j]->f && a[i]->s < a[j]->s) swap(a[i],a[j]);
        }
    }
}

int latestNonConflict(Activity** a, int i){
    for(int j=i-1; j>=0; j--){
        if(a[i]->s >= a[j]->f) 
            return j;
    }
    return -1;
}

int activitySelector(Activity** a, int n){
    sort_activity(a,n);
    int vett[n];
    vett[0]= a[0]->profit;
    for(int i=1;i<n;i++){
        int prof= a[i]->profit;
        int lnc= latestNonConflict(a,i);
        if(lnc!=-1) prof= prof+vett[lnc];
        if(vett[i-1]<prof) vett[i]=prof;
        else vett[i]= vett[i-1];
    }
    return vett[n-1];
}

int main(){
    for(int i=0;i<100;i++){
        int n; in>>n;
        Activity** a =new Activity*[n];
        int s,f;
        char c;
        for(int j=0;j<n;j++){
            in>>c>>s>>f>>c;
            a[j]=new Activity(s,f);
        }
        out<<activitySelector(a,n)<<endl;
    }
}
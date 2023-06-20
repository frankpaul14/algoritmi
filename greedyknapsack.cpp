#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int knapsack(vector<int> vett, int max){
    int sum=0;
    sort(vett.begin(),vett.end(), greater<int>()); //ordine decrescente usando greater<int>
    for(int i=0; i<max; i++){
        sum+=vett[i];
    }
    return sum;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int i=0; i<100; i++){
        int n;
        int max;
        in>>n;
        in>> max;
        vector<int> vett;
        for(int j=0; j<n; j++){
            int tmp;
            in>>tmp;
            vett.push_back(tmp);
        }
        out<<knapsack(vett,max)<<endl;
    }
}
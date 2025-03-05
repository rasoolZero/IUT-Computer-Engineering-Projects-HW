#include <iostream>
#include <vector>
using namespace std;

int * C;

unsigned int func(int x,int n){


    unsigned int table[x+1];
    for(int i=0;i<x+1;i++)
        table[i]=0;
    table[0]=1;
    for(int i=0; i<n; i++)
        for(int j=C[i]; j<=x; j++)
            table[j] = (table[j]%(1000000000+7))+(table[j-C[i]]%(1000000000+7));
    return table[x]%(1000000000+7);
}

int main()
{
    int n,x;
    cin >> n;
    cin >> x;
    C=new int[n+1];
    for(int i=0;i<n;i++)
        cin >> C[i];
    cout << func(x,n);

    return 0;
}

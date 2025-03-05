#include <iostream>
#define LL long long
using namespace std;
LL * arr;
LL ** memory;

LL eat(int i,int j){
    if(i>j)
        return 0;
    if(j==i+1)
        return max(arr[i],arr[j]);
    if(i==j)
        return arr[i];
    if(memory[i][j]!=0)
        return memory[i][j];

    LL i1j1=eat(i+1,j-1);
    memory[i][j]=max(arr[i]+min(i1j1,eat(i+2,j)) , arr[j]+min(i1j1,eat(i,j-2)));
    return memory[i][j];
}

int main()
{
    int n;
    cin >> n;
    arr=new LL[n];
    memory = new LL * [n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        memory[i]=(LL *)calloc(n,sizeof(LL));
    }
    cout << eat(0,n-1);
    return 0;
}

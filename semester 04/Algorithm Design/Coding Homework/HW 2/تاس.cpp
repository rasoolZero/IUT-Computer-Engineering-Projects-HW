#include <iostream>
#define ULL long long
using namespace std;

ULL * memory;

ULL func(int n){
    if(n<0)
        return 0;
    if(memory[n]!=0)
        return memory[n];
    ULL total=0;
    for(int i=1;i<=6;i++)
        total+=(func(n-i)%(1000000000+7));
    memory[n]=total%(1000000000+7);
    return total%(1000000000+7);
}

int main()
{
    int n;
    cin >> n;
    memory=new ULL[n+1];
    for(int i=0;i<=n;i++)
        memory[i]=0;
    memory[0]=1;
    cout << func(n);

    return 0;
}

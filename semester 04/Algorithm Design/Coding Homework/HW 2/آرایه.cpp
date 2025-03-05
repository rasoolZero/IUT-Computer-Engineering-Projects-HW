#include <iostream>

using namespace std;

long long ** memory;
int m,n;

unsigned long long func(short arr[],int i){
    if(i==n){
//        for(int j=0;j<n;j++)
//            cout << arr[j] << ' ';
//        cout << endl;
        return 1;
    }
    if(arr[i]!=0 && memory[i][arr[i]]!=0)
        return memory[i][arr[i]];
    if(arr[i]!=0){
        unsigned long long result=func(arr,i+1)%(1000000000+7);
        memory[i][arr[i]]=result;
        return result;
    }

    unsigned long long total=0;
    for(int j=1;j<=m;j++){
        if(i!=0){
            if(j < arr[i-1]-1 || j > arr[i-1]+1)
                continue;
        }
        if(arr[i+1]!=0){
            if(j < arr[i+1]-1 || j > arr[i+1]+1)
                continue;
        }
        if(memory[i][j] != 0){
            total = (total%(1000000000+7)) + memory[i][j];
            continue;
        }
        arr[i]=j;
        memory[i][j] = func(arr,i+1) % (1000000000+7);
        total = (total%(1000000000+7)) + memory[i][j];
    }
    arr[i]=0;

    return total%(1000000000+7);
}

int main()
{
    cin >> n >> m;
    short * arr = new short[n+1];
    memory = new long long * [n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        memory[i]=new long long [m+1];
        for(int j=0;j<=m;j++)
            memory[i][j]=0;
    }
    arr[n]=0;
    cout << func(arr,0);

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int maxCap;
    int cap=0;
    int index=0;

    int fails=0;

    vector<int> qu;

    cin >> maxCap;
    cin >> n;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        bool contains=false;
        for(int i=0;i<cap;i++)
            if(qu[i]==in)
                contains=true;
        if(contains)
            continue;
        if(cap==maxCap){
            qu[index]=in;
            index=(index+1)%maxCap;
        }
        else{
            qu.push_back(in);
            cap++;
        }
        fails++;
    }
    cout << fails;
    return 0;
}

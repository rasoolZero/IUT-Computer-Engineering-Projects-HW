#include <iostream>
#include <vector>

using namespace std;

int part(vector<int> & arr,int left,int right){
    int pivot=arr[left];
    int i=left,j=right+1;
    do{
        do
            i++;
        while(arr[i]<pivot);
        do
            j--;
        while(arr[j]>pivot);
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    int temp=arr[left];
    arr[left]=arr[j];
    arr[j]=temp;
    return j;
}


void Quick(vector<int> & arr,int left,int right){
    int j;
    if(left<right){
        j=part(arr,left,right);
        Quick(arr,left,j-1);
        Quick(arr,j+1,right);
    }
}


int main()
{
    int input;
    vector<int> arr;

    while (cin >> input)
    {
        arr.push_back(input);
    }
    Quick(arr,0,arr.size()-1);

    for(auto i : arr)
        cout << i << ' ';
    return 0;
}

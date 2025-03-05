#include <iostream>
#include <cstring>

using namespace std;

//class Line{
//public:
//    long long a,b;
//    Line(long long _a,long long _b){a=_a;b=_b;}
//
//    operator > (Line other){
//        return this->a > other.a;
//    }
//    operator >= (Line other){
//        return this->a >= other.a;
//    }
//};

unsigned long long merge(long long * arr, long long * temp, int left, int mid, int right)
{
    unsigned long long count = 0;

    int i=left;
    int j=mid;
    int k=left;
    while((i <= mid-1) && (j <= right)){

        int branchTrue = arr[i] <= arr[j];
        int branchFalse = !branchTrue;
//        cout << branchTrue << ' ' << branchFalse << endl;
        temp[k++] = branchTrue * arr[i] + branchFalse * arr[j];
        i += branchTrue;
        j += branchFalse;

        count += (mid-i)*branchFalse;
    }

    while(i <= mid-1)
        temp[k++]=arr[i++];

    while(j <= right)
        temp[k++]=arr[j++];


    memcpy(arr+left,temp+left,sizeof(long long)*(right-left+1));

    return count;
}


unsigned long long mergeSort(long long arr[], long long temp[], int left, int right)
{
    int mid;
    unsigned long long count = 0;
    if(right > left){

        mid = (right + left)/2;

        count+=mergeSort(arr, temp, left, mid);
        count+=mergeSort(arr, temp, mid+1, right);

        count+=merge(arr, temp, left, mid+1, right);
    }
    return count;
}














int partition(long long arr[], int low, int high, long long arr2[])
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)

        if (arr[j] <= pivot) {

            i++;
            swap(arr[i], arr[j]);
            swap(arr2[i], arr2[j]);
        }

    swap(arr[i+1], arr[high]);
    swap(arr2[i+1], arr2[high]);
    return i+1;
}

int partition_r(long long arr[], int low, int high,long long arr2[])
{

    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);
    swap(arr2[random], arr2[high]);

    return partition(arr, low, high,arr2);
}

void quickSort(long long arr[], int low, int high,long long arr2[])
{
    if (low < high) {

        int pi = partition_r(arr, low, high,arr2);

        quickSort(arr, low, pi - 1,arr2);
        quickSort(arr, pi + 1, high,arr2);
    }
}








int main()
{
//    int test[10]={10,9,8,7,6,5,4,3,2,1};
//    quickSort(test,0,9);
//    for(int i=0;i<10;i++)
//        cout << test[i] << endl;
    int n;
    cin >> n;
//    vector<long long> A(n),B(n);
    long long * A = new long long[n];
    long long * B = new long long[n];
    for(int i=0;i<n;i++)
        cin >> A[i] >> B[i];
    srand(*A);

    quickSort(A,0,n-1,B);


//    for(int i=0;i<n;i++)
//        cout <<A[i] <<' ' << B[i] << endl;
    cout << mergeSort(B,A,0,n-1);

//    for(int i=0;i<n;i++)
//        cout << B[i] << endl;
    return 0;
}

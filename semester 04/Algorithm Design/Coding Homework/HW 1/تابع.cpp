#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


long double median2a(vector<long long>& A ,vector<long long>& B, int a , int b , int n ){

    if(n==1)
        return (A[a]+B[b])/2.0;
    if(n==2)
        return (max(A[a], B[b])+min(A[a+1], B[b+1]))/2.0;

    int newN = n%2==0?n-n/2+1:n-n/2;
    int newStart = n%2==0?n/2-1:n/2;

    long double median1 = n%2 == 0 ?(A[a+n/2]+A[a+n/2-1]) / 2.0 : A[a+n/2];
    long double median2 = n%2 == 0 ?(B[b+n/2]+B[b+n/2-1]) / 2.0 : B[b+n/2];

    if(median1==median2)
        return median1;

    if(median1>median2)
        return median2a(A,B,a,b+newStart,newN);
    return median2a(A,B,a+newStart,b,newN);
}

int main()
{
    int n;
    cin >> n;
    vector <long long> A(n),B(n);
    long long x;
    for(int i=0;i<n;i++)
        cin >> A[i];
    for(int i=0;i<n;i++)
        cin >> B[i];

        cout << fixed;
        cout << setprecision(1) << median2a(A,B,0,0,n);
    return 0;
}

#include <iostream>
#include <string>


using namespace std;

int main()
{
    int m,n;
    cin >> n >> m;
    string matrix[n];
    int digit;
    bool toFlip;
    for(int i=0;i<n;i++){
        matrix[i]=string(m,' ');

        cin >> digit;
        toFlip=!digit;

        digit = toFlip*(!digit)+(!toFlip)*digit;
        matrix[i][0]=digit+'0';
        for(int j=1;j<m;j++){
            cin >> digit;
            digit = toFlip*(!digit)+(!toFlip)*digit;
            matrix[i][j]=digit+'0';
        }
    }

    for(int j=1;j<m;j++){
        int zeroCounter=0,oneCounter=0;
        for(int i=0;i<n;i++){
            zeroCounter+=matrix[i][j]=='0';
            oneCounter+=matrix[i][j]=='1';
        }
        if(zeroCounter>oneCounter)
            for(int i=0;i<n;i++)
                matrix[i][j] = (matrix[i][j]=='0')*'1' + (matrix[i][j]=='1')*'0';
    }
//    for(int i=0;i<n;i++)
//        cout << matrix[i] << endl;

    int long long total=0;
    for(int i=0;i<n;i++)
        total+=stoll(matrix[i],0,2);
    cout << total;

    return 0;
}

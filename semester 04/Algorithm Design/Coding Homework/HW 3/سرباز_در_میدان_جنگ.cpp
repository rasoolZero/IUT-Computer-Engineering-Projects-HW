#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>


using namespace std;
int evens,odds;
int m,n,r,c;
void filling(int ** matrix){
    stack<pair<int,int>> st;
    st.push({0,0});
    while(!st.empty()){
        pair<int,int> point = st.top();
        st.pop();
        int x=point.first;
        int y=point.second;
        if(matrix[x][y]!=0)
            continue;
//        cout << x << ' ' << y << endl;
        vector<pair<int,int>> checked;
        for(int i=-1;i<=1;i+=2)
        for(int j=-1;j<=1;j+=2){
            int newX=x+m*i;
            int newY=y+n*j;
//            cout << newX <<' ' << newY << endl;

            if(std::find(checked.begin(), checked.end(), pair<int,int>(newX,newY) ) == checked.end()){
                checked.push_back({newX,newY});
                if(newX>=0 && newX<r && newY>=0 && newY<c){
                    matrix[x][y]+=matrix[newX][newY]!=-1;
//                cout << newX <<' ' << newY << endl;
                    if(matrix[newX][newY]==0 )
                        st.push({newX,newY});
                }
            }

            newX=x+n*i;
            newY=y+m*j;
            if(std::find(checked.begin(), checked.end(), pair<int,int>(newX,newY) ) == checked.end()){
                checked.push_back({newX,newY});
                if(newX>=0 && newX<r && newY>=0 && newY<c){
                    matrix[x][y]+=matrix[newX][newY]!=-1;
//                cout << newX <<' ' << newY << endl;
                    if(matrix[newX][newY]==0 )
                        st.push({newX,newY});
                }
            }

        }
        int n=matrix[x][y];
        evens+=(!(n & 1));
        odds+=(n & 1);
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> r >> c >> m >> n;
//        cout << m << ' ' << n << endl;
        int ** matrix = (int **)calloc(r,sizeof(int *));
        for(int i=0;i<r;i++)
            matrix[i] = (int *)calloc(c,sizeof(int));

        int w;
        cin >> w;
        for(int i=0;i<w;i++){
            int a,b;
            cin >> a>>b;
            matrix[a][b]=-1;
        }

        evens=0;
        odds=0;
        filling(matrix);
//        cout <<  evens << ' ' << odds << endl;
        cout << "Case "<<i<<": " << evens << ' ' << odds << endl;
//        for(int i=0;i<r;i++){
//            for(int j=0;j<c;j++)
//                cout << matrix[i][j] << ' ';
//            cout << endl;
//        }


        for(int i=0;i<r;i++)
            free(matrix[i]);
        free(matrix);
    }
    return 0;
}

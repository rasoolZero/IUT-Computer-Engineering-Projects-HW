#include <cstdio>
#include <cstdlib>

int ** memory;
int N;
int * W;
int * L;

int tower( int i ,int limit){
    if(limit < 0)
        return -1;
    if(limit == 0 || i >= N)
        return 0;
    if(memory[i][limit]!=0)
        return memory[i][limit];


    int min_L =  ((limit-W[i] < L[i])*(limit-W[i])) + ((!(limit-W[i] < L[i])) * L[i]);

    int left = tower(i+1,limit);
    int right = tower(i+1,min_L)+1;
    memory[i][limit] = ((left > right)*left) + ((!(left > right))*right) ;

    return  memory[i][limit];
}

int main()
{
    scanf("%d",&N);
    W = (int *)malloc(sizeof(int)*1000);
    L = (int *)malloc(sizeof(int)*1000);
    memory = (int **)malloc(1001*sizeof(int *));
    while(N){
        int max_l=0;
        for(int i=0;i<N;i++){
            scanf("%d%d",W+i,L+i);
//            cin >> W[i] >> L[i];
//            toys.push_back({w,l});
//            if(L[i]>max_l)
//                max_l=L[i];
            int condition = L[i] > max_l;
            max_l = (condition*L[i])+((!condition)*max_l);
        }
//        for(int i=0;i<N;i++)
//            cout << W[i] << ' ' << L[i] << endl;
        for(int i=0;i<=N;i++){
            memory[i] = (int *)calloc(max_l*2+1,sizeof(int));
        }

        printf("%d\n",tower(0,max_l*2));
        for(int i=0;i<=N;i++)
            free(memory[i]);
        scanf("%d",&N);
    }

    return 0;
}

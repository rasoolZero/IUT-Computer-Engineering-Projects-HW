#include <iostream>
#include <math.h>

using namespace std;

typedef struct Node{
    int pid;
    int pp;
}Node;

int getParentIndex(int i){
    return (int)floor(i/2);
}

class Heap{
public:
    Heap(){
        cin >> capacity;
        heap=new Node[capacity+1];

        Node * tempArray=new Node[capacity];

        for(int i=0;i<capacity;i++)
            cin >> tempArray[i].pid;
        for(int i=0;i<capacity;i++)
            cin >> tempArray[i].pp;
        cin >> waiting_inserts;

        for(int i=0;i<capacity;i++)
            insert(tempArray[i]);
        delete[] tempArray;

    }
    ~Heap(){
        delete[] heap;
    }

    void process(){
        while(n){
            Node removed=remove();
            cout << removed.pid << ' ';
            if(waiting_inserts){
                waiting_inserts--;
                Node to_insert;
                cin >> to_insert.pid;
                cin >> to_insert.pp;
                insert(to_insert);
            }
        }
    }

private:
    Node * heap;
    int capacity;
    int n=0;

    int waiting_inserts;

    void insert(Node item){
        int i=++n;
        while((i!=1) && (item.pp < heap[getParentIndex(i)].pp || (item.pp==heap[getParentIndex(i)].pp && item.pid < heap[getParentIndex(i)].pid))){
            heap[i]=heap[getParentIndex(i)];
            i/=2;
        }
        heap[i]=item;
    }
    Node remove(){
        int parent,child;
        Node item, temp;
        item=heap[1];
        temp=heap[n--];
        parent=1;
        child=2;
        while(child<=n){
            if((child < n) && (heap[child].pp > heap[child+1].pp || ( heap[child].pp == heap[child+1].pp && heap[child].pid > heap[child+1].pid )))
                child++;
            if(temp.pp <  heap[child].pp || (temp.pp==heap[child].pp && temp.pid <=heap[child].pid  ) )break;
            heap[parent] = heap[child];
            parent = child;
            child*=2;
        }
        heap[parent] = temp;
        return item;
    }
};


int main()
{

    Heap heap;
    heap.process();
    return 0;
}

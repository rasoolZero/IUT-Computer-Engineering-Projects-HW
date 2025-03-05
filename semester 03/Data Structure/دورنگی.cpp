#include <iostream>
#include <vector>

using namespace std;

class Node{

public:
    Node()=default;
    int Color(){return color;}
    void Color(int c){color=c;}
    void Neighbors(int newN){neighbors.push_back(newN);}
    vector<int> neighbors;

private:
    int color=0;

};

class Graph{

public:
    Graph(int n){
        nodes=new Node[n];
        size=n;
    }
    ~Graph(){
        delete[] nodes;
    }
    void addNeighbors(int u,int w){
        nodes[u].Neighbors(w);
        nodes[w].Neighbors(u);
    }

    bool color(){
        for(int i=0;i<size;i++){
            bool colorOne=false,colorTwo=false;
            for(auto j : nodes[i].neighbors){
                if(nodes[j].Color() == 1)
                    colorOne=true;
                else if(nodes[j].Color() == 2)
                    colorTwo=true;

            }
            if(colorOne && colorTwo)
                return false;
            else{
                if(!colorOne)
                    nodes[i].Color(1);
                else if(!colorTwo)
                    nodes[i].Color(2);
            }
        }
        return true;
    }

    void printNeighbors(int u){
        for(auto n : nodes[u].neighbors)
            cout << n << ' ';
        cout << endl;
    }
private:
    Node * nodes;
    int size;

};


int main()
{
    int nodes;
    cin >> nodes;
    while(nodes){
//        cout << "nodes :" << nodes << endl;
        Graph g(nodes);
        int edges;
        cin >> edges;
        while(edges){
            int u,w;
            cin >> u; cin >> w;
            g.addNeighbors(u,w);
            edges--;
        }
        if(g.color())
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
        cin >> nodes;
    }



    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;
    void edge(int u,int v,bool direction){
        // direction = 0 means undirected graph and direction = 1 means directed graph
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void prinAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes->";
    cin>>n;
    int m;
    cout<<"Enter the number of edges->";
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph-> 
        g.edge(u,v,0); 
    }
    g.prinAdjList();
    return 0;
}
// input->
// Enter the number of nodes->5
// Enter the number of edges->6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4
// output->
// 4-->3, 0,    
// 3-->2, 1, 4, 
// 2-->1, 3,    
// 0-->1, 4,    
// 1-->0, 2, 3, 
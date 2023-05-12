#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map <int,list<int>> adj;
        
        // create a edge from u to v
        void edge(int u,int v, bool direction){
            adj[u].push_back(v);

            // for undirected graph direc = 0
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printList(){
            for(auto i :adj){
                cout<<i.first<<" -> ";
                for(auto j : i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};

vector<int> BFS(unordered_map <int,list<int>> &adj,unordered_map <int,bool> &visited,vector<int> &ans,int i){

    queue<int> q;
    q.push(i);
    visited[i] == 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // store front into ans
        ans.push_back(front);

        //traverse all neighours of front
        for(auto i :adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}

int main(){

    int n;
    cout<<"Number of nodes : ";
    cin>>n;
    
    int m;
    cout<<"Number of edges : ";
    cin>>m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;

        g.edge(u,v,0);      // 0 bcoz undirected
    }
    g.printList();

    vector<int> ans;
    unordered_map <int,bool> visited;
    
    // traverse all components
    for (int i = 0; i < m; i++)
    {
        if(!visited[i]){
            ans = BFS(g.adj,visited,ans,i);
        }
    }
    
    cout<<endl<<"Print bfs"<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans.at(i);
    }
    

}
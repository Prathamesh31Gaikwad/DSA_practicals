#include<iostream>
#include<queue>
using namespace std;
void dfs(int** matrix,int sv,int v,int* visited){
    cout<<sv;
    visited[sv]=1;
    for(int i=0;i<v;i++){
        if(i==sv){
            continue;
        }
        if(matrix[i][sv]==1 && visited[i]!=1){
            
            visited[i]=1;
            dfs(matrix,i,v,visited);
        }
    }
}
void bfs(int ** matrix, int sv, int v, int * visited)
{
    queue<int> s;
 
    s.push(sv);
    visited[sv]=1;
    while(!s.empty())
    {
        int curr = s.front();
        s.pop();
        cout<<curr;
        for(int i = 0; i < v; i++)
        {
            if(matrix[i][curr] == 1 && visited[i] != 1)
            {
          
                s.push(i);
                visited[i] = 1;
            }
        }

    }

}

int main(void)
{
    int v,e;
    cout<<"enter no of vertices : ";
    cin>>v;
    cout<<"enter no of edges : ";
    cin>>e;
    int** matrix=new int*[v];
    for(int i=0;i<v;i++){
        matrix[i]=new int[v];
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            matrix[i][j]=0;
        }
    }
    int* visited1=new int[v];
    for(int i=0;i<v;i++){
        visited1[i]=0;
    }
    int* visited2=new int[v];
        for(int i=0;i<v;i++){
        visited2[i]=0;
    }
    cout<<"enter the edges \n";
    int s,ee;
    for(int i=0;i<e;i++){
        cout<<"start and end : ";
        cin>>s>>ee;
        matrix[s][ee]=1;
        matrix[ee][s]=1;        
    }
    int sv,s2v;
    cout<<"enter starting vertex dfs";
    cin>>sv;
    dfs(matrix,sv,v,visited1);
cout<<"enter starting vertex bfs";
    cin>>s2v;
    bfs(matrix,s2v,v,visited2);

}
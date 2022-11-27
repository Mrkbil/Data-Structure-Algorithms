#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertices;
    cin>>vertices;
    int graph[vertices][vertices];
    for (int i=0;i<vertices;i++){
        for(int j=i;j<vertices;j++){
            if(i==j){
                graph[i][j]=0;
                continue;
            }
            cout<<i<<" to "<<j<<" Edge: ";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }
    cout<<"Matrix:"<<endl;
    for (int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    //Finding Degree
    int degree[vertices];
    for (int i=0;i<vertices;i++){
        degree[i]=0;
    }
    for (int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(graph[i][j]==1){
                degree[i]++;
            }
        }
    }
    for (int i=0;i<vertices;i++){
        cout<<degree[i]<<" ";
    }
}

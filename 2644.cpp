// 2644 촌수계산

#include<queue>
#include<stdio.h>
#include<vector>
using namespace std;

int n,s,e,m,sum;
int check[1000];
vector<vector<int>> v(105);

int main(){
    scanf("%d%d%d%d",&n,&s,&e,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<pair<int,int>> q;
    q.push(make_pair(s,0));
    check[s]=true;
    pair<int,int> temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        check[temp.first] = true;
        if(temp.first==e) break;
        for(int i=0;i<v[temp.first].size();i++)
            if(!check[v[temp.first][i]])
                q.push(make_pair(v[temp.first][i],temp.second+1));
    }
    if(check[e]) printf("%d",temp.second);
    else printf("-1");
    return 0;
}

// bfs || dfs
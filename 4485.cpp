// 4485	녹색 옷 입은 애가 젤다지?

// 그래프를 만든다음 다익스트라 할 경우 : 212ms

// bfs를 이용한 floodfill을 할 경우 : 12ms

// 그래프를 만들지않고 바로 다익스트라 할 경우 : 8ms

#include<stdio.h>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

class my_greater  {
public:
    bool operator() (const tuple<int,int,int>& arg1, const tuple<int,int,int>& arg2) const
    {
        return get<1>(arg1) > get<1>(arg2);
        return false;
    }
};
int sum[10005],n,k,f;
vector<vector<pair<int,int>>> s(20005);
void dijkstra(int x){
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,my_greater> pq;
    vector<int> dist(20005,2100000000);
    dist[x]=0;
    pq.push(make_tuple(x,0,0));
    while(!pq.empty()){
        int temp,d;
        tie(temp,d,ignore)=pq.top();
        pq.pop();
        if(d<=dist[temp]){
            for(auto i : s[temp]){
                if(dist[i.first]>i.second+dist[temp]){
                    pq.push(make_tuple(i.first,i.second,temp));
                    dist[i.first]=i.second+dist[temp];
                }
            }
        }
    }
    printf("%d\n",dist[n]+f);
}

int main(){
    int m,cnt=1;
    scanf("%d",&m);
    while(m){
        printf("Problem %d: ",cnt);
        n=m*m;
        int data[15626]={0};
        for(int i=1;i<=n;i++){
            scanf("%d",&data[i]);
        }
        f=data[1];
        for(int i=1;i<=n;i++){
            if((i-1)%m!=0){
                s[i-1].push_back(make_pair(i,data[i]));
            }
            if((i-m)>0){
                s[i-m].push_back(make_pair(i,data[i]));
            }
            if((i+m)<=n){
                s[i+m].push_back(make_pair(i,data[i]));
            }
            if((i+1)%m!=1){
                s[i+1].push_back(make_pair(i,data[i]));
            }
        }
        dijkstra(1);
        scanf("%d",&m);
        vector<vector<pair<int,int>>> new_s(20005);
        s = new_s;
        cnt++;
    }
    return 0;
}
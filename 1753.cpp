// 1753 최단경로

// http://hsp1116.tistory.com/42



#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
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

int main(){
    int v,e,k;
    scanf("%d %d %d",&v,&e,&k);
    vector<int> dist(20005,2100000000);
    vector<int> p(20005);
    vector<vector<pair<int,int>>> s(20005);
    for(int i=0;i<e;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        s[a].push_back(make_pair(b,c));
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,my_greater> pq;
    dist[k]=0;
    pq.push(make_tuple(k,0,0));
    while(!pq.empty()){
        int temp,d;
        tie(temp,d,ignore)=pq.top();
        pq.pop();
        if(d<=dist[temp]){
            for(auto x : s[temp]){
                if(dist[x.first]>x.second+dist[temp]){
                    pq.push(make_tuple(x.first,x.second,temp));
                    dist[x.first]=x.second+dist[temp];
                    p[x.first]=temp;
                }
            }
        }
    }
    for(int i=1;i<=v;i++){
        printf("%d ",i);
        int temp = p[i];
        while(temp){
            printf("%d ",temp);
            temp = p[temp];
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=v;i++){
        if(dist[i]==2100000000)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
    return 0;
}

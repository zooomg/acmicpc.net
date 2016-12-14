//2042 구간 합 구하기

//세그먼트 트리 구현

#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;

long long make(vector<long long>& v,vector<long long>& tree,int idx,int s,int e){
    if(s==e){
        return tree[idx] = v[s];
    }
    else{
        return tree[idx] = make(v,tree,idx*2,s,(s+e)/2)+make(v,tree,idx*2+1,(s+e)/2+1,e);
    }
}

void update(vector<long long>& tree,int idx,int s,int e,long long int target,long long int diff){
    if(target<s || e<target) return;
    tree[idx] = tree[idx]+diff;
    if(s!=e){
        update(tree,idx*2,s,(s+e)/2,target,diff);
        update(tree,idx*2+1,(s+e)/2+1,e,target,diff);
    }
}

long long sum(vector<long long>& tree,int idx,int s,int e,long long int l,long long int r){
    if(e<l || r<s) return 0;
    if(l<=s && e<=r) return tree[idx];
    return sum(tree,idx*2,s,(s+e)/2,l,r) + sum(tree,idx*2+1,(s+e)/2+1,e,l,r);
}

int main(){
    vector<long long> v;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int h = (int)ceil(log2(n));
    vector<long long> tree(1<<(h+1));
    for(int i=0;i<n;i++){
        long long int x;
        scanf("%lld",&x);
        v.push_back(x);
    }
    make(v,tree,1,0,n-1);
    for(int i=0;i<m+k;i++){
        long long int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x==1){
            update(tree, 1, 0, n-1, y-1, z-v[y-1]);
            v[y-1]=z;
        }
        else
            printf("%lld\n",sum(tree,1,0,n-1,y-1,z-1));
    }
    return 0;
}
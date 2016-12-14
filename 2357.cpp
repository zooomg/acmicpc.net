// 2357 최소값 최대값 

#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;

long long max_make(vector<long long>& v,vector<long long>& tree,int idx,int s,int e){
    if(s==e){
        return tree[idx] = v[s];
    }
    else{
        return tree[idx] = max(max_make(v,tree,idx*2,s,(s+e)/2),max_make(v,tree,idx*2+1,(s+e)/2+1,e));
    }
}

long long imax(vector<long long>& tree,int idx,int s,int e,long long int l,long long int r){
    if(e<l || r<s) return 0;
    if(l<=s && e<=r) return tree[idx];
    return max(imax(tree,idx*2,s,(s+e)/2,l,r), imax(tree,idx*2+1,(s+e)/2+1,e,l,r));
}

long long min_make(vector<long long>& v,vector<long long>& tree,int idx,int s,int e){
    if(s==e){
        return tree[idx] = v[s];
    }
    else{
        return tree[idx] = min(min_make(v,tree,idx*2,s,(s+e)/2),min_make(v,tree,idx*2+1,(s+e)/2+1,e));
    }
}

long long imin(vector<long long>& tree,int idx,int s,int e,long long int l,long long int r){
    if(e<l || r<s) return 1000000005;
    if(l<=s && e<=r) return tree[idx];
    return min(imin(tree,idx*2,s,(s+e)/2,l,r), imin(tree,idx*2+1,(s+e)/2+1,e,l,r));
}

int main(){
    vector<long long> v;
    int n,m;
    scanf("%d%d",&n,&m);
    int h = (int)ceil(log2(n));
    vector<long long> max_tree(1<<(h+1));
    vector<long long> min_tree(1<<(h+1));
    for(int i=0;i<n;i++){
        long long int x;
        scanf("%lld",&x);
        v.push_back(x);
    }
    max_make(v,max_tree,1,0,n-1);
    min_make(v,min_tree,1,0,n-1);
    for(int i=0;i<m;i++){
        long long int x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld %lld\n",imin(min_tree,1,0,n-1,x-1,y-1),imax(max_tree,1,0,n-1,x-1,y-1));
    }
    return 0;
}

// 인덱스트리(펜윅트리)
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

void lazy_update(vector<int> &tree, int s,int e, int idx, vector<int> &lazy){
	if(lazy[idx]!=0){
		tree[idx]+= (e-s+1)*lazy[idx];
		if(s!=e){
			lazy[idx*2]+=lazy[idx];
			lazy[idx*2+1]+=lazy[idx];
		}
		lazy[idx]=0;
	}
}

void processing(vector<int> &tree, int s, int e, int idx, vector<int> &lazy, int k){
	lazy_update(tree,s,e,idx,lazy);
	if(s==e)
		tree[idx] = tree[idx] >= k ? 1 : 0;
	if(s!=e){
		processing(tree, s, (s+e)/2, idx*2, lazy, k);
		processing(tree, (s+e)/2+1, e, idx*2+1, lazy, k);
		tree[idx] = tree[idx*2] + tree[idx*2+1];
	}
}

void update_range(vector<int> &tree, int s, int e, int idx, int l, int r, int diff, vector<int> &lazy){
	lazy_update(tree,s,e,idx,lazy);
	if(r<s || e<l)
		return;
	if(l<=s && e<=r){
		tree[idx]+=(e-s+1)*diff;
		if(s!=e){
			lazy[idx*2]+=diff;
			lazy[idx*2+1]+=diff;
		}
		return;
	}
	update_range(tree,s,(s+e)/2,idx*2,l,r,diff,lazy);
	update_range(tree,(s+e)/2+1,e,idx*2+1,l,r,diff,lazy);
	tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int seg_find(vector<int> &tree,int s,int e,int idx,int l,int r,vector<int> &lazy){
	lazy_update(tree,s,e,idx,lazy);
	if(r<s || e<l)
		return 0;
	if(l<=s && e<=r)
		return tree[idx];
	return seg_find(tree,s,(s+e)/2,idx*2,l,r,lazy)+seg_find(tree,(s+e)/2+1,e,idx*2+1,l,r,lazy);
}

int main(){
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	int size = 200000;
	int h = (int)ceil(log2(size));
	vector<int> tree(1 << (h+1)), lazy(1 << (h+1));
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		update_range(tree,0,size-1,1,a-1,b-1,1,lazy);
	}
	processing(tree,0,size-1,1,lazy,k);
	for(int i=0;i<q;i++){
		int a,b,cnt=0;
		scanf("%d%d",&a,&b);
		printf("%d\n",seg_find(tree,0,size-1,1,a-1,b-1,lazy));
	}
	return 0;
}
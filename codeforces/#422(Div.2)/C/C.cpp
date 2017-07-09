#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int BS(vector<pair<pair<int,int>,pair<int,int>>>& v, int s, int e, int key, pair<pair<int,int>,pair<int,int>>& x){
	if(s == e){
		if(v[s].first.first == key){
			if(x.second.second < v[s].second.first || v[s].second.second < x.second.first){
				return v[s].first.second;
			}
		}
		return 999999999;
	}
	if(key < v[(s+e)/2].first.first)
		return BS(v,s,(s+e)/2,key,x);
	else if(key > v[(s+e)/2].first.first)
		return BS(v,(s+e)/2+1,e,key,x);
	else{
		int num = 999999999;
		if(x.second.second < v[(s+e)/2].second.first || v[(s+e)/2].second.second < x.second.first){
			num = v[s].first.second;
		}
		return min(num,min(BS(v,s,(s+e)/2,key,x), BS(v,(s+e)/2+1,e,key,x)));
	}
}

int main(){
	int n,total;
	scanf("%d %d",&n,&total);
	vector<pair<pair<int,int>,pair<int,int>>> v;
	for(int i=0;i<n;i++){
		int l,r,cost;
		scanf("%d %d %d",&l,&r,&cost);
		v.push_back(make_pair(make_pair(r-l+1,cost),make_pair(l,r)));
	}
	sort(v.begin(),v.end(),greater<pair<pair<int,int>,pair<int,int>>>());
	int min = 999999999;
	for(auto x : v){
		int temp=0;
		if(total-x.first.first>0)
			temp = BS(v,0,n-1,total-x.first.first,x);
		if(temp!=0 && min > x.first.second + temp)
			min = x.first.second + temp;
	}
	if(min == 999999999)
		printf("-1");
	else
		printf("%d",min);
	return 0;
}
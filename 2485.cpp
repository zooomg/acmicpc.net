#include<stdio.h>

int gcd(int n, int m){
	while(m!=0){
		int t = m;
		m = n%m;
		n = t;
	}
	return n;
}

int main(){
	int n,data[100005]={0},diff[100005]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data[i]);
		diff[i] = data[i] - data[i-1];
	}
	int result,cnt=0;
	result = gcd(diff[2],diff[3]);
	for(int i=3;i<n;i++){
		result = gcd(result,diff[i]);
	}
	for(int i=2;i<=n;i++){
		cnt+=diff[i]/result-1;
	}
	printf("%d",cnt);
	return 0;
}
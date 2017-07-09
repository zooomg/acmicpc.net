#include<stdio.h>

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char a[1005],b[1005];
	scanf("%s%s",a,b);
	int min=9999,s=-1;
	for(int i=0;i<m-n+1;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(a[j]!=b[i+j]){
				cnt++;
			}
		}
		if(cnt<min){
			min = cnt;
			s = i;
		}
	}
	printf("%d\n",min);
	for(int i=s;i<s+n;i++){
		if(b[i]!=a[i-s])
			printf("%d ",i-s+1);
	}
	return 0;
}
#include<stdio.h>

int main(){
	int n,k,s,y,data[2][7]={0},cnt=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d %d",&s,&y);
		data[s][y]++;
	}
	for(int i=0;i<2;i++){
		for(int j=1;j<7;j++){
			if(data[i][j]!=0)
				cnt += data[i][j]/k;
				if(data[i][j]%k != 0)
					cnt += 1;
		}
	}
	printf("%d",cnt);
	return 0;
}
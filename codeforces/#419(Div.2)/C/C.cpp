#include<stdio.h>

int main(){
	int n,m,data[105][105]={0},row[105]={0},col[105]={0},cnt=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&data[i][j]);
		}
	}
	if(n<=m){
		for(int i=0;i<n;i++){
			int min = 2100000000;
			for(int j=0;j<m;j++)
				if(min > data[i][j])
					min = data[i][j];
			for(int j=0;j<m;j++)
				data[i][j]-=min;
			row[i] = min;
			cnt+=min;
		}
		for(int j=0;j<m;j++){
			int min = 2100000000;
			for(int i=0;i<n;i++)
				if(min > data[i][j])
					min = data[i][j];
			for(int i=0;i<n;i++)
				data[i][j]-=min;
			col[j] = min;
			cnt+=min;
		}
	}
	else {
		for(int j=0;j<m;j++){
			int min = 2100000000;
			for(int i=0;i<n;i++)
				if(min > data[i][j])
					min = data[i][j];
			for(int i=0;i<n;i++)
				data[i][j]-=min;
			col[j] = min;
			cnt+=min;
		}
		for(int i=0;i<n;i++){
			int min = 2100000000;
			for(int j=0;j<m;j++)
				if(min > data[i][j])
					min = data[i][j];
			for(int j=0;j<m;j++)
				data[i][j]-=min;
			row[i] = min;
			cnt+=min;
		}
	}
	bool flag = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(data[i][j]!=0){
				printf("-1");
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}
	if(!flag){
		printf("%d\n",cnt);
		for(int i=0;i<n;i++){
			for(int j=0;j<row[i];j++){
				printf("row %d\n", i+1);
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<col[i];j++){
				printf("col %d\n", i+1);
			}
		}
	}
	return 0;
}
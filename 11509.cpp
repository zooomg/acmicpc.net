// COCI 2015/2016
// 화살을 동시에 쐈다고 생각하고
// 화살 쏘는 상황을 Arrow 배열에 저장
#include<stdio.h>

int main(){
	int n,data[1000005]={0},arrow[1000005]={0},max=-1,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
		max = max < data[i] ? data[i] : max;
	}
	for(int i=0;i<n;i++){
		if(arrow[data[i]+1]){
			arrow[data[i]+1]--;
			arrow[data[i]]++;
		}
		else{
			arrow[data[i]]++;
		}
	}
	for(int i=0;i<max+1;i++){
		cnt+=arrow[i];
	}
	printf("%d",cnt);
	return 0;
}
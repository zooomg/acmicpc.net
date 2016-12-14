// 2562	 최대값	
// KOI 2007 지역본선 초등부 1번

#include<stdio.h>

int main(){
	int i;
	int max = 0;
	int max_idx;
	for (i = 0; i < 9; i++){
		int x;
		scanf("%d", &x);
		if (max < x){
			max = x;
			max_idx = i;
		}
	}
	printf("%d\n%d", max, max_idx+1);
	return 0;
}
// 최대값을 배열에서 찾을 수 있는지
// 굳이 배열안써도 찾을 수 있음 바로바로
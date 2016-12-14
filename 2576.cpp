// 2576 	홀수
// KOI 2006 지역본선 초등부 1번

#include<stdio.h>

int main(){
	int data[10] = { 0 };
	int i;
	for (i = 0; i < 7; i++){
		scanf("%d", &data[i]);
	}
	int sum = 0, min = 9999999;
	for (i = 0; i < 7; i++){
		if (data[i] % 2 == 1){
			if (min>data[i]){
				min = data[i];
			}
			sum += data[i];
		}
	}
    if(sum==0)
        printf("-1");
	else printf("%d\n%d", sum, min);
	return 0;
}
// 홀수를 찾아 모두 더하고
// 홀수 중 최소값을 찾는다
// 그렇다면 홀수라면 최소값인지 확인하고
// 최소값이든 아니든 모두 더해준다
// 2588 	곱셈
// KOI 2005 지역본선 초등부 2번

#include<stdio.h>

int main(){
	int data1[10] = { 0 };
	int data2[10] = { 0 };
	int result[100] = { 0 };
	int sum = 0;
	int i, j;
	int x, y;
	scanf("%d %d", &x, &y);
	for (i = 2; i >= 0; i--){
		data1[i] = x % 10;
		x /= 10;
		data2[i] = y % 10;
		y /= 10;
	}
	int ten;
	for (i = 2; i >= 0; i--){
		ten = 1;
		for (j = 2; j >= 0; j--){
			result[i] += data1[j] * data2[i] * ten;
			ten *= 10;
		}
	}
	ten = 1;
	for (i = 2; i >= 0; i--){
		printf("%d\n", result[i]);
		sum += result[i] * ten;
		ten *= 10;
	}
	printf("%d\n", sum);
	return 0;
}
// 그냥 귀찮은 문제
// 규칙에 맞게 2번째 숫자를 한자리씩 잘라서 곱해준 수 출력 후
// 1,10,100을 곱해서 최종결과값에 저장
// 최종결과값 출력
// 2490	 윷놀이

#include<stdio.h>

int main(){
	int i, sum = 0, j;
	char data[6] = {'D','C','B','A','E'};
	for (i = 0; i<3; i++){
		for (j = 0; j < 4; j++){
			int x;
			scanf("%d", &x);
			sum += x;
		}
		printf("%c\n", data[sum]);
		sum = 0;
	}
	return 0;
}

// 1을 카운트해주는게 포인트
// 1을 카운트해주는 방법에는 진짜 세어주는 것과 비슷한게
// 1을 하나의 변수에 더해주는 것
// if문을 써주는거를 더 짧게 해주기 위해
// sum에 해당하는 숫자를 키값으로 하고 value는 영어로해서
// 간단하게 바로 출력
// 1871	 좋은 자동차 번호판


#include<stdio.h>

int abs(int x){
	if (x < 0) return x*-1;
	else return x;
}
int main(){
	int n;
	scanf(“%d\n”, &n);
	int i;
	for (i = 0; i < n; i++){
		char a, b, c, s;
		int x, y, z;
		int d;
		scanf("%c%c%c%c%d", &a, &b, &c, &s, &d);
		x = (a - 'A') * 676;
		y = (b - 'A') * 26;
		z = (c - 'A');
		if (abs(x + y + z - d) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
	return 0;
}
// 이 문제는 문제 그대로 풀면 됨
// 아마 사람들은 입력을 모두 다르게 했을 거 같다
// 나는 문자는 문자대로 받고 숫자는 숫자대로 받아서 품
// 내가 처음에 문제 풀때는 x,y,z를 따로 안만들고 a,b,c에다가
// 바로 계산한 결과를 넣어줬는데
// 이 숫자가 256(char 범위)를 벗어나서 틀림
// 그래서 int형으로 변수를 만들어서 저장
// 저장한 값을 규칙에 맞게 곱해줘서 계산한 결과 출력
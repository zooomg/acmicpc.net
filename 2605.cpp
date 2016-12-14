// 2605	 줄 세우기
// KOI 2004 지역본선 초등부 2번


#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int i,j;
	int data[105] = { 0 };
	int result[105] = { 0 };
	for (i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	for (i = 0; i < n; i++){
		result[i] = i + 1;
	}
	for (i = 0; i < n; i++){
		int s=i;
		for (j = 0; j < data[i]; j++){
			int temp;
			temp = result[s];
			result[s] = result[s - 1];
			result[s - 1] = temp;
			s--;
		}
	}
	for (i = 0; i < n; i++){
		printf("%d ", result[i]);
	}
	return 0;
}
// 입력된 수만큼 뒤로 밀어주고 해당 숫자를 넣어주면 됨
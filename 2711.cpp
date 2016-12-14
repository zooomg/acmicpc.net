// 2711	 오타맨 고창영

#include<stdio.h>
#include<string.h>

int main(){
	int T;
	scanf("%d", &T);
	int i,j,data_len;
	char data[100] = { 0 };
	for (i = 0; i < T; i++){
		int hole;
		scanf("%d ", &hole);
		scanf("%s", data);
		data_len = strlen(data);
		for (j = 0; j < data_len; j++){
			if (j == hole-1) continue;
			else printf("%c",data[j]);
		}
		printf("\n");
	}
	return 0;
}
// 0으로 대체하는 방법
// 그냥 그 자리만 출력 안하는 방법

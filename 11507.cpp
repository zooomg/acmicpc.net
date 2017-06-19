// COCI 2015/2016
// 카드 더미에 빠진 카드 수 세기
// Hashing

#include<stdio.h>

int main(){
	char data[1005]={0};
	int count[5][14]={0};
	scanf("%s",data);
	for(int i=0;data[i];i+=3){
		char a,b,c;
		a = data[i];
		b = data[i+1]-'0';
		c = data[i+2]-'0';
		int bc = b*10+c;
		if(a=='P')
			count[0][bc]++;
		if(a=='K')
			count[1][bc]++;
		if(a=='H')
			count[2][bc]++;
		if(a=='T')
			count[3][bc]++;
	}
	for(int i=0;i<4;i++){
		for(int j=1;j<=13;j++){
			if(count[i][j]>1){
				printf("GRESKA");
				return 0;
			}
		}
	}
	for(int i=0;i<4;i++){
		int cnt=0;
		for(int j=1;j<=13;j++){
			if(count[i][j])
				cnt++;
		}
		printf("%d ",13-cnt);
	}
	return 0;
}
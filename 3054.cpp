#include<stdio.h>
#include<string.h>

int main(){
	char s[20],cnt=0;
	scanf("%s",s);
	int s_len = strlen(s);
	for(int j=0;j<4*s_len+1;j++){
		if((j+2)%12 == 0)
			printf("*");
		else if((j+2)%4 == 0)
			printf("#");
		else
			printf(".");
	}
	printf("\n");
	for(int i=0;i<4*s_len+1;i++){
		if((i+3)%12==0 || (i+1)%12==0)
			printf("*");
		else if(i%2)
			printf("#");
		else
			printf(".");
	}
	printf("\n");
	for(int i=0;i<4*s_len;i++){
		if((i+2)%4==0)
			printf("%c",s[cnt++]);
		else if(i!=0 && ((i-8)%12==0 || i%12==0))
			printf("*");
		else if(i%4==0)
			printf("#");
		else
			printf(".");
	}
	if(s_len%3==0)
		printf("*");
	else
		printf("#");
	printf("\n");
	for(int i=0;i<4*s_len+1;i++){
		if((i+3)%12==0 || (i+1)%12==0)
			printf("*");
		else if(i%2)
			printf("#");
		else
			printf(".");
	}
	printf("\n");
	for(int j=0;j<4*s_len+1;j++){
		if((j+2)%12 == 0)
			printf("*");
		else if((j+2)%4 == 0)
			printf("#");
		else
			printf(".");
	}
	return 0;
}
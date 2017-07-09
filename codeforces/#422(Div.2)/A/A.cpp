#include<stdio.h>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	a = a > b ? b : a;
	int result = 1;
	while(a){
		result *= a;
		a-=1;
	}
	printf("%d",result);
	return 0;
}
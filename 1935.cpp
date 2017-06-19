#include<stdio.h>

int main(){
	int n,data[30]={0},top=0;
	double stack[30]={0};
	char eq[1005];
	scanf("%d",&n);
	scanf("%s",eq);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	for(int i=0;eq[i];i++){
		if('A'<= eq[i] && eq[i] <='Z')
			stack[top++] = data[eq[i]-'A'];
		else{
			double a = stack[--top];
			double b = stack[--top];
			if(eq[i]=='+')
				stack[top++] = a+b;
			else if(eq[i]=='-')
				stack[top++] = b-a;
			else if(eq[i]=='*')
				stack[top++] = a*b;
			else if(eq[i]=='/'){
				if(a == 0) stack[top++] = 0;
				else stack[top++] = (float)b/(float)a;
			}
		}
	}
	printf("%.2lf",stack[top-1]);
	return 0;
}
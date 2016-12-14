// 1735    	 분수 합

#include<stdio.h>

int main(void) {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a = a*d+c*b;
    b = b*d;
    int t1 = a,t2 = b, t3;
    while(1){
        if(t1%t2 == 0){
            t3 = t2;
            break;
        }
        t3 = t2;
        t2 = t1%t2;
        t1 = t3;
    }
    if(a%t3 == 0 && b%t3 == 0)
        printf("%d %d",a/t3,b/t3);
    else
        printf("%d %d",a,b);
    return 0;
}
// 이 문제는 분수 꼴로 만들어준뒤
// 분모 분자의 최대공약수로 나눠주는 문제
// 그래서 이 문제의 포인트는 최대공약수를 구하는 것
// 구하는 방법에는 에라토스테네스의 체
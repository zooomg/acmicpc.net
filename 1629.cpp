// 1629 곱셈

// 알고리즘 시간에 배웠던 분할정복 예제

// 짝수일 경우 : a^6 = (a^3)*(a^3)
// 홀수일 경우 : a^3 = (a^1*a^1)*a

// O(lgN)

#include<stdio.h>
 
long long int power(long long int x,long long int y,long long int z){
    if(y==0) return 1;
    long long int d=power(x,y/2,z);
     
    if(y%2==0) return (d*d)%z;
    else return (((x*d)%z)*d)%z;
}
int main(){
    long long int a,b,c;
    long long int result;
    scanf("%lld %lld %lld",&a,&b,&c);
    result=power(a,b,c);
    printf("%lld\n",result);
    return 0;
}

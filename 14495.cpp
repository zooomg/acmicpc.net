#include<stdio.h>

int main(){
    long long int n,data[200]={1,1,1,};
    scanf("%lld",&n);
    for(int i=3;i<n;i++)
        data[i] = data[i-1]+data[i-3];
    printf("%lld",data[n-1]);
    return 0;
}
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long int a,c,d,r;
        char b;
        scanf("\n%lld %c %lld = %lld",&a,&b,&c,&d);
        if(b == '+')
            r = a+c;
        else if(b == '-')
            r = a-c;
        else if(b == '*')
            r = a*c;
        else if(b == '/')
            r = a/c;
        if(r == d)
            printf("correct\n");
        else
            printf("wrong answer\n");
    }
    return 0;
}
// 2864	 5와 6의 차이

#include<stdio.h>
#include<string.h>

int func(char s[10],int s_len,bool flag){
    int i;
    for(i=0;i<s_len;i++){
        if(flag) s[i]-='0';
        if(s[i]==6 || s[i]==5){
            if(flag) s[i]=5;
            else s[i]=6;
        }
    }int sum=0,ten=1;
    for(i=s_len-1;i>=0;i--){
        sum+=s[i]*ten;
        ten*=10;
    }
    return sum;
}

int main(){
    char s1[10],s2[10];
    scanf("%s %s",s1,s2);
    int s1_len = strlen(s1),s2_len = strlen(s2);
    printf("%d ",func(s1,s1_len,true)+func(s2,s2_len,true));
    printf("%d",func(s1,s1_len,false)+func(s2,s2_len,false));
    return 0;
}
// 문자열로 받아서 ‘0’을 빼주고
// 처음에는 6이나 5를 5로 만들어서 더해주고
// 두번째에는 6이나 5를 6으로 만들어서 더해준 결과를 출력

main(a,b,m,M,t,i){
    scanf("%d%d",&a,&b);
    m=M=a+b;
    for(i=1;a+b;i=t){
        t=i*10;
        if(a%t/i==5)M+=i;
        if(b%t/i==5)M+=i;
        if(a%t/i==6)m-=i;
        if(b%t/i==6)m-=i;
        a-=a%t;
        b-=b%t;
    }
    printf("%d %d",m,M);
}

// 더 쉬운방법은 문자열로 받아서 숫자로 바꾸는 과정을 생략하고
// 숫자로 받은 다음 %10으로 1의 자리수만 짤라서
// 5나 6일때 5로 계산하는 변수 x, 6으로 계산하는 변수 y
// 를 두고 for문 한개로 진행

// 더더 쉬운방법은 
main(a,b,m,M,t,i){
    scanf("%d%d",&a,&b);
    m=M=a+b;
    for(i=1;a+b;i=t){
        t=i*10;
        if(a%t/i==5)M+=i;
        if(b%t/i==5)M+=i;
        if(a%t/i==6)m-=i;
        if(b%t/i==6)m-=i;
        a-=a%t;
        b-=b%t;
    }
    printf("%d %d",m,M);
}
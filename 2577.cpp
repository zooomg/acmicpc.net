// 2577	 숫자의 개수
// KOI 2006 지역본선 초등부 2번

#include<stdio.h>

int main(){
    int a,b,c,data[11]={0};
    scanf("%d %d %d",&a,&b,&c);
    a *= b;
    a *= c;
    while(1){
        if(a == 0)
            break;
        data[a%10]++;
        a /= 10;
    }
    for(int i=0;i<10;i++){
        printf("%d\n",data[i]);
    }
    return 0;
}

// 숫자 다 곱하고
// %10으로 분해해서
// 0~9값을 키값으로 저장
// 저장된 값 모두 출력
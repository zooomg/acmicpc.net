// 2587 	대표값2
// KOI 2005 지역본선 초등부 1번


#include<stdio.h>

int main(){
    int a[6]={0};
    scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    int sum = a[0]+a[1]+a[2]+a[3]+a[4];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(a[i]<a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%d\n%d",sum/5,a[2]);
    return 0;
}
// 매우 간단한 문제
// 숫자 5개를 받아서 평균
// 정렬해서 중앙값
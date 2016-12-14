// 9324	 진짜 메시지

#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char data[100005]={0},check[26]={0},flag=0;
        scanf("%s",data);
        for(int j=0;data[j];j++){
            check[data[j]-'A']++;
            if(check[data[j]-'A']%3==0){
                if(data[j+1]!=data[j]){
                    printf("FAKE\n");
                    flag = 1;
                    break;
                }
                check[data[j]-'A']=0;
                j++;
            }
        }
        if(!flag)
            printf("OK\n");
    }
    return 0;
}
// 왠만해서는 %연산자로 배수 컷팅하는 것을 지양하는게 좋겠다. 예외가 발생하는듯
// 그냥 카운트를 0으로 초기화 시켜주는 것이 깔끔
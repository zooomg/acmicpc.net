// 2309	 일곱 난쟁이
// KOI 2004 지역본선 초등부 1번

#include<stdio.h>
int data[10];
int main(){
    int check[100]={0};
    for(int i=0;i<9;i++){
        scanf("%d",&data[i]);
    }
    for(int i=0;i<9;i++){
        int flag = false;
        for(int j=0;j<9;j++){
            int sum = 0,cnt = 0;
            for(int t=0;t<100;t++)
                check[t]=0;
            for(int k=0;k<9;k++){
                if(i!=j && i!=k && j!=k){
                    sum += data[k];
                    check[data[k]] = 1;
                    cnt++;
                }
                if(sum==100 && cnt==7){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    for(int i=0;i<100;i++){
        if(check[i])
            printf("%d\n",i);
    }
    return 0;
}
// 초기에 시도했던 알고리즘은 완전 탐색으로 했지만 못짬
// 생각해보면 가짜 2명만 없애고 다 더해보면 됨
// 2847	게임을 만든 동준이

#include<stdio.h>

int main(){
    int n,data[100]={0},sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    for(int i=n-1;i>=1;i--){
        if(data[i]<data[i-1]){
            sum += (data[i-1]-data[i])+1;
            data[i-1] = data[i]-1;
        }
    }
    printf("%d",sum);
}
//앞에서부터 비교해서 작은 수로 만들게 되면 9 8 7 6 이런 상황일때 불가능.
//많이 틀렸던 이유 : 같은 값을 체크를 안해줬다.
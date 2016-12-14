// 2581 소수

// 체를 구현할때
// j를 i+i부터 시작해야한다
// 왜냐하면 그냥 j는 소수이기 때문이다
// ex) 2는 소수인데 지금 i+i부터 하지 않는다면 2부터 체크되어 소수가 아닌 합성수로 보게된다

#include<stdio.h>

int main(){
    int n,m,data[10005]={0};
    data[1]=1;
    scanf("%d %d",&n,&m);
    for(int i=2;i*i<10000;i++)
        if(data[i]==0)
            for(int j=i+i;j<=10000;j+=i)
                data[j]=1;
    int sum=0,min=10005;
    for(int i=n;i<=m;i++){
        if(data[i]==0){
            sum+=i;
            if(i<min){
                min = i;
            }
        }
    }
    if(sum==0) printf("-1");
    else printf("%d\n%d",sum,min);
    return 0;
}
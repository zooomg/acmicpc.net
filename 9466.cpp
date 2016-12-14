// 9466 텀 프로젝트

#include<stdio.h>

int main(){
    int n,m;
    scanf("%d",&n);
    while(n--){
        int a[100005]={0},check[100005]={0},me[100005]={0};
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]),me[a[i]]++;
        int sum=0;
        for(int i=1;i<=m;i++){
            int idx = i;
            while(!me[idx] && !check[idx]){
                check[idx]=1;
                me[a[idx]]--;
                idx = a[idx];
                sum++;
            }
        }
        printf("%d\n",sum);
    }
}

// 위상정렬과 dfs의 콜라보

// http://www.playsw.or.kr/repo/cast/110 - 위상정렬
// => 사이클을 아예 안보면 되는구나
// -> 위상정렬은 사이클을 만나는 순간 멈추게 됨
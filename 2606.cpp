// 2606	 바이러스
// KOI 2004 지역본선 초등부 3번

#include<stdio.h>

int n,l,data[105][105],stack[105],check[105],top,idx;
int main(){
    scanf("%d %d",&n,&l);
    for(int i=0;i<l;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        data[x][y]=data[y][x]=1;
    }
    check[top]=1;
    stack[top++]=1;
    idx=1;
    while(stack[top]==0){
        int flag = 0;
        for(int i=1;i<=n;i++){
            if(data[idx][i]==1 && check[i]==false){
                check[i]=true;
                stack[top++]=i;
                idx=i;
                flag = 1;
                break;
            }
        }
        if(flag==0){
            stack[--top]=0;
            if(top<0)
                break;
            idx = stack[top-1];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(check[i])
            cnt++;
    }
    printf("%d",cnt-1);
}
// 전형적인 그래프 탐색문제
// 그래프 번호의 값이 헷갈릴 수 있는 것 빼고 구현문제(1부터 시작 or 0부터 시작)
// check 된 노드의 개수를 출력하면 됨
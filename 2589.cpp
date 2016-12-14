// 2589 	보물섬
// KOI 2005 지역본선 초등부 3번

#include<stdio.h>

char data[55][55],check[55][55];
int n,m;

int bfs(int i,int j){
    int i_q[2500]={0},j_q[2500]={0};
    int result[55][55]={0};
    int f=0,r=0;
    i_q[r]=i;
    j_q[r++]=j;
    int max=0;
    result[i][j]=0;
    while(f!=r){
        int a,b,p;
        a = i_q[f];
        b = j_q[f];
        p = result[a][b];
        check[a][b] = 1;
        if(max<p){
            max = p;
        }
        if(a+1<n && data[a+1][b]=='L' && result[a+1][b]==0){
            i_q[r]=a+1;
            j_q[r++]=b;
            result[a+1][b]=p+1;
        }
        if(b+1<m && data[a][b+1]=='L' && result[a][b+1]==0){
            i_q[r]=a;
            j_q[r++]=b+1;
            result[a][b+1]=p+1;
        }
        if(a-1>-1 && data[a-1][b]=='L' && result[a-1][b]==0){
            i_q[r]=a-1;
            j_q[r++]=b;
            result[a-1][b]=p+1;
        }
        if(b-1>-1 && data[a][b-1]=='L' && result[a][b-1]==0){
            i_q[r]=a;
            j_q[r++]=b-1;
            result[a][b-1]=p+1;
        }
        i_q[f]=0;
        j_q[f++]=0;
    }
    return max;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",data[i]);
    }
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(data[i][j]=='L'){
                int temp = bfs(i,j);
                if(max<temp)
                    max = temp;
            }
        }
    }
    printf("%d",max);
    return 0;
}
// BFS를 아무점에서 일단 시작한다.
// 가장 큰 수를 찾는다.
// 그 수가 저장된 좌표에서 다시 한번 돌린다.
// 이때, 지나간 경로는 지운다. 혹은 체크해둔다.
// 그 수가 max값이라면 max에 저장.
// 다음 보물섬을 찾는다.(1~5 반복)
// 찾은 가장 큰 max값을 출력
// 는 실패
// 위에 있는 것을 구현하려면 필요한 것이 주변 바다의 개수를 저장하는 배열 하나를 더 해서 3차원으로 진행(섬번호, 주변바다개수)
// 는 귀찮아서 모든 점에서 다 돌림
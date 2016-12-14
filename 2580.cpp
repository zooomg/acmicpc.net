// 2580	 스도쿠
// KOI 2006 지역본선 초등부 5번

// 8 0 0 0 0 0 0 0 0
// 0 0 3 6 0 0 0 0 0
// 0 7 0 0 9 0 2 0 0
// 0 5 0 0 0 7 0 0 0
// 0 0 0 0 4 5 7 0 0
// 0 0 0 1 0 0 0 3 0
// 0 0 1 0 0 0 0 6 8
// 0 0 8 5 0 0 0 1 0
// 0 9 0 0 0 0 4 0 0

#include<stdio.h>
int z_i[81],z_j[81],z_cnt;
int data[9][9]={0};


void func(int idx){
    if(idx==z_cnt){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                printf("%d ",data[i][j]);
            }
            printf("\n");
        }
        return;
    }
    int y = z_i[idx],x = z_j[idx],check[10]={0};
    for(int i=0;i<9;i++){
        check[data[y][i]]=1;
        check[data[i][x]]=1;
    }
    for(int i=(y/3)*3;i<(y/3)*3+3;i++){
        for(int j=(x/3)*3;j<(x/3)*3+3;j++){
            check[data[i][j]]=1;
        }
    }int i;
    for(i=1;i<10;i++){
        if(!check[i])
            break;
    }
    for(;i<10;i++){
        if(!check[i]){
            data[y][x]=i;
            check[i]=1;
            func(idx+1);
            data[y][x]=0;
            check[i]=0;
        }
    }
}
int main(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            scanf("%d",&data[i][j]);
            if(data[i][j]==0){
                z_i[z_cnt]=i;
                z_j[z_cnt++]=j;
            }
        }
    func(0);
    return 0;
}
// 백트래킹
// 시간을 줄이기 위해 0인 숫자 자리를 저장
// 저장된 자리만 탐색하면 9*9를 전체 탐색하는 것보다 덜 돔
// 0인 자리의 가로 세로 9칸 숫자(0~9)를 1로 체크
// 만약에 체크되지 못한 숫자(0으로 체크된 숫자)가 있다면
// 그 숫자를 써주고 스도쿠판에서 다음 0인 숫자자리를 반복
// 중간에 가다가 이상하면 백
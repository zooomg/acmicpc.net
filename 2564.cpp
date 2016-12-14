// 2564	 경비원
// KOI 2007 지역본선 초등부 3번

// 동서남북
// 왼쪽(위) 오른쪽(아래)
// 	0   1
// 서 => x m-x
// 동 => x m-x
// 남 => x n-x
// 북 => x n-x

// 동근이
// 남2
// 	동4 - data[k][1] + m-x(= data[i][1])
// 	서3 - data[k][0] + m-x(= data[i][1])
// 	남2 - abs(data[k][0] - data[i][0])
// 	북1 - min(data[k][0]+data[i][0],data[k][1]+data[i][1])		+ m
// 북1
// 	동4 - data[k][1] + data[i][0]
// 	서3 - data[k][0] + data[i][0]
// 	남2 - min(data[k][0]+data[i][0],data[k][1]+data[i][1])		+ m
// 	북1 - abs(data[k][0] - data[i][0])
// 서3
// 	동4 - min(data[k][0]+data[i][0],data[k][1]+data[i][1])		+ n
// 	서3 - abs(data[k][0] - data[i][0])
// 	남2 - data[k][1] + data[i][0]
// 	북1 - data[k][0] + data[i][0]
// 동4
// 	동4 - abs(data[k][0] - data[i][0])
// 	서3 - min(data[k][0]+data[i][0],data[k][1]+data[i][1])		+ n
// 	남2 - data[k][1] + data[i][1]
// 	북1 - data[k][0] + data[i][1]
// 10 5
// 3
// 1 4
// 3 2
// 2 3
// 2 8

// 29

// 10 5
// 3
// 2 4
// 3 3
// 1 8
// 1 3

// 33 // 29

// 확인할점
// 동근의 위치 동서남북 돌려보기
// 같은 dir의 상점과 위치 바꿔보기

#include<stdio.h>
#define ABS(a)(((a) < (0))?-(a):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))

struct pair{
    int dir;
    int d[2];
};
pair store[100];
int main(){
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<t+1;i++){
        scanf("%d %d",&store[i].dir,&store[i].d[0]);
        if(store[i].dir>=3)
            store[i].d[1] = m-store[i].d[0];
        else
            store[i].d[1] = n-store[i].d[0];
    }
    int key1,key2;
    key1 = store[t].dir <= 2 ? m : n;
    key2 = ((store[t].dir%2)+1)%2;
    int sum=0;
    for(int i=0;i<t;i++){
        int temp = store[t].dir - store[i].dir;
        if(temp == 0)
            sum+=ABS(store[i].d[0]-store[t].d[0]);
        else if((key2==1 && temp == 1) || (key2==0 && temp == -1))
            sum+=MIN(store[i].d[0]+store[t].d[0],store[i].d[1]+store[t].d[1])+key1;
        else if(temp == 2 || temp == -2)
            sum+=store[t].d[key2]+store[i].d[key2];
        else
            sum+=store[t].d[!key2]+store[i].d[key2];
    }
    printf("%d",sum);
    return 0;
}
// 각 상점별 2개의 거리 저장
// 동근이의 방향와 상점의 방향에 따른
// 계산 값을 적어보고
// 규칙을 찾아서 코드로 옮김
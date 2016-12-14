// 2579	 계단 오르기
// KOI 2006 지역본선 초등부 4번

// 연속 3계단 밟으면 안됨
// 연속을 체크하는 뭔가 있어야됨

// 그렇다면 이전 2계단 + 자기자신을 포함해
// dp[i][0] = 연속으로 밟지 않은 애
// dp[i][1] = 연속으로 밟은 애
// dp[i][0] = max(data[i]+dp[i-2][0],data[i]+dp[i-2][1],dp[i-1][1])
// dp[i][1] = data[i]+dp[i-1][0]

// dp[i-1][1]이 되는 순간 다음번에는 무조건 밟아야됨
// 그래서 넣었으면 안됨
// 무조건 자기자신을 밟은 상태여야함
// 과정과 결론이 달라서는 안됨
// 과정에서는 안밟고 지나가고 마지막에 밟고 그런거 없음
// dp[i]는 항상 조건에 맞는 답을 가지고 있어야함
// 1. 연속 3계단 x
// 2. 자기자신 무조건 밟기
// 3. 최대

// data[i]+dp[i-1] 이 되는 순간 다음 애는 못밟음

// 10 20 15 25 10 20

// 10 30 35 55

// dp[0]=data[0]
// dp[1]=data[0]+data[1]
// dp[2]=max(0~2) + max(0~2)

// 10 20 25 15 10 20

// 20 25 10 20

// 10 30 45 

// 6
// 1 1 0 0 1 1

// 1 1 
// 1 2 

// 1 1 2 1
// 1 2 1 1

// 연속으로 안밟는 경우 발생

#include<stdio.h>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))

int main(){
    int n,data[300]={0},dp[300][2]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    dp[0][0]=dp[0][1]=data[0];
    dp[1][0]=data[1];
    dp[1][1]=data[1]+data[0];
    if(n==1){ printf("%d",data[0]); return 0;}
    else if(n==2){ printf("%d",dp[1][1]); return 0;}
    //else if(n==3){ printf("%d",MAX(data[0],data[1])+data[2]); return 0;}
    for(int i=2;i<n-1;i++){
        dp[i][0] = MAX(data[i]+dp[i-2][0],data[i]+dp[i-2][1]);
        dp[i][1] = data[i]+dp[i-1][0];
    }
    dp[n-1][0]=MAX(MAX(dp[n-3][0],dp[n-3][1]),dp[n-2][0])+data[n-1];
    printf("%d",dp[n-1][0]);
    return 0;
}
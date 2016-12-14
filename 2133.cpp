// 2133 타일채우기

// 초기 생각했던 점화식 : dp[i] = dp[i-2]*3 + dp[i-4]*2

// 추가된 점화식 : dp[i]  = dp[i-2]*3 + SUM(dp[i-j]*2) j : 4 ~ i

// j를 돌리는 이유는 
// ￼
// 가 중간에 들어가는 경우가 있기 떄문

// 저 모양을 0 2 4 ~ 번째에 채워서 타일을 만들 수 있기 때문

// 초기 점화식에서는 저 모양들이 중간에 들어가는 경우가 고려되지 못함

#include<stdio.h>

int main(){
    int n,dp[35]={0};
    dp[0]=1;
    dp[2]=3;
    for(int i=4;i<=30;i+=2){
        dp[i]=dp[i-2]*3;
        for(int j=4;j<=i;j+=2)
            dp[i]+=dp[i-j]*2;
    }
    scanf("%d",&n);
    if(n%2) printf("0");
    else printf("%d",dp[n]);
    return 0;
}
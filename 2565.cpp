// 2565	 전깃줄
// KOI 2007 지역본선 초등부 4번

// 1 8
// 2 2
// 3 9
// 4 1
// 6 4
// 7 6
// 9 7
// 10 10

// 1 2 3 4 6 7 9 10 
// 8 2 9 1 4 6 7 10 
// 1 2 1 3 2 2 2 1

// 1-8
// 3-9
// 4-1

// 4 2 6 7 9 1 3 10 
// 1 2 4 6 7 8 9 10

// 처음에는 a를 오름차순으로 정렬한 뒤
// b를 최장부분감소수열을 찾아서 출력 했으나,
// 문제에서 없애야할 전깃줄 숫자를 보니
// b를 오름차순으로 정렬한 뒤
// a를 LIS를 구해서 출력한 값이였다.

#include<stdio.h>
struct pair{
    int a;
    int b;
};
pair data[101];
int main(){
    int n,dp[101]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&data[i].a,&data[i].b);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(data[i].b>data[j].b){
                pair temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    data[n].a=501;
    for(int i=0;i<=n;i++){
        dp[i]=1;
        for(int j=0;j<=i;j++){
            if(data[i].a>data[j].a && dp[i]<=dp[j]){
                dp[i] = dp[j]+1;
            }
        }
    }
    printf("%d",n-dp[n]+1);
    return 0;
}
// 수열에서 최소 SWAP으로 혹은 최소 커팅으로
// 오름차순 혹은 내림차순으로 만들어야 하는 문제는
// LIS를 의심해볼 필요가 있다.

// http://dyngina.tistory.com/16
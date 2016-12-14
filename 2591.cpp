// 2591	 숫자카드
// KOI 2005 지역본선 초등부 5번

// 2 1
// 20 1
// 201 1
// 27 2
// 271 2
// 2712 4
// 27123 6
// 271233 10
// 2712334 16
// 27123334 26
// 271233334 42
// 271230 

// 7 1
// 72 1

// 1 1
// 12 2
// 123 3
// 1230 2
// 12301 2
// 123012 4
// 1230123 6
// 12301231 10
// 123012310 6
// 12301230 4
// 1230120 2
// 1231 5
// 12312 8

// i번째 숫자가 0이되는 순간 앞 수와 하나가 된다.
// 그래서 경우의 수는 예를들어 123에서 1230이 되었을때
// 1 2 // 30 이런식으로, 그래서 1 2와 경우의 수가 같다.
// 0이 온 다음 수는 어떤 숫자가 와도 경우의 수에 영향을 미치지 못한다.
// (무조건 1개로 따로 다녀야하기 때문)
// 예를 들어 1230 12301
// 1 2 // 30 1

// if(data[i-1]*10 + data[i] <=34)
// 	dp[i] = dp[i-1]+dp[i-2];
// else
// 	dp[i] = dp[i-1];


// 1011121314151617181920212223242526272829
// 1183744
#include<stdio.h>
char data[45]={0};
int data_len;
int func(int idx,bool check[45]){
    int i;
    for(i=0;i<data_len;i++){
        if(!check[i])
            break;
    }
    if(idx==data_len && i==data_len)
        return 1;
    int cnt=0;
    if(idx==i){
    for(int i=idx;i<data_len;i++){
        if(data[i]==0)
            return cnt;
        if(data[i]*10+data[i+1]<=34){
            check[i]=check[i+1]=true;
            cnt+=func(idx+2,check);
            check[i]=check[i+1]=false;
        }
        check[i]=true;
        cnt+=func(idx+1,check);
        check[i]=false;
    }
    }
    return cnt;
}
int main(){
    scanf("%s",data);
    int i;
    for(i=0;data[i];i++){
        data[i]-='0';
    }
    data[i]=200;
    data_len = i;
    bool check[45]={0};
    printf("%d",func(0,check));
    return 0;
}
// => 시간초과, 케이스 숫자 커질수록 부정확
// => O(2^N)

// 1011121314151617181920212223242526272829
// 2367488
#include<stdio.h>

int main(){
    int dp[45]={0};
    char data[45]={0};
    scanf("%s",data);
    int i;
    for(i=0;data[i];i++){
        data[i]-='0';
    }
    data[i]=200;
    int data_len = i;
    if(data[0]==0)
        dp[0]=0;
    else
        dp[0]=1;
    if(data[0]*10+data[1]<=34){
        dp[1]=dp[0]+1;
    }
    else if(data[1]==0){
        dp[1]=1;
    }
    else{
        dp[1]=1;
    }
    for(i=2;i<data_len;i++){
        if(data[i]==0){
            dp[i]=dp[i-2];
        }
        else if(data[i-1]==0 && data[i]!=0){
            dp[i]=dp[i-1];
        }
        else if(data[i-1]*10+data[i]<=34){
            dp[i]=dp[i-1]+dp[i-2];
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    printf("%d",dp[data_len-1]);
    return 0;
}
// 피보나치
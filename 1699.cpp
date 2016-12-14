// 1699 제곱수의 합

// #include<stdio.h>

// int dp[100005];
// int main(){
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<317;i++){
//         dp[i*i]=1;
//     }
//     for(int i=2;i<=n;i++){
//         if(dp[i]!=1){
//             int min = 999999;
//             for(int j=1;i>j*j;j++){
//                 min = min > dp[i-j*j]+1 ? dp[i-j*j]+1 : min;
//             }
//             dp[i] = min;
//         }
// //        printf("%d %d\n",i,dp[i]);
//     }
//     printf("%d",dp[n]);
//     return 0;
// }

#include <cstdio>
int main(){
	int n,m=0,i,j,a[350];
	bool v[100005];
	scanf("%d",&n);
	for(i=0; i<=n; i++) v[i]=0;
	for(i=1; i*i<=n; i++) a[m++]=i*i,v[i*i]=1;
	if(v[n]){puts("1");return 0;}
	for(i=0; i<m; i++)
		if(v[n-a[i]]){puts("2");return 0;}
	for(i=0; i<m; i++)
		for(j=i; j<m && a[j]<n-a[i]; j++)
			if(v[n-a[i]-a[j]]){puts("3"); return 0;}
	puts("4");
	return 0;
}

// 손으로 해보면 5 이상의 값이 나올 수 없나보다
// 제곱수를 포문을 적게 돌기 위해 제곱수들을 배열에 넣어 그 배열을 포문을 돌린다
// 점화식 : dp[x] = min(dp[x-i*i]+1) , dp[x] = 1 (x = 제곱수)
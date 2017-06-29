#include<stdio.h>
#define DIV 1000000007LL

long long int multi(long long int x,long long int y, long long int p){
	long long int ans = 1;
	while(y>0){
		if(y&1)
			ans = (ans*x)%p;
		x = (x*x)%p;
		y >>= 1;
	}
	return ans;
}

int main(){
	int n;
	long long int a[200005]={0},b[200005]={0},c[100005]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(n==1)
		printf("%lld",a[0]);
	else {
		if(n%2){
			for(int i=1;i<n;i++){
				if(i%2){
					b[i-1] = a[i-1] + a[i] % DIV;
				}
				else{
					b[i-1] = (a[i-1] - a[i] + DIV) % DIV;
				}
			}
			for(int i=0;i<n;i++){
				a[i] = b[i];
				b[i] = 0;
			}
			n -= 1;
		}
		long long fac[200005]={1,1,};
		for(int i=2;i<=200000;i++)
			fac[i] = (fac[i-1]*i)%DIV;
		long long inv[200005]={0};
		inv[200000] = multi(fac[200000],DIV-2,DIV);
		for(int i = 200000-1;i>0;i--)
			inv[i] = (inv[i+1]*(i+1))%DIV;
		int N = n/2 - 1;
		for(int i=0;i<=N/2;i++){
			if(i == 0){
				c[i] = 1;
				c[N-i] = 1;
			}
			else{
				c[i] = (fac[N] * inv[N-i]) % DIV;
				c[i] = (c[i] * inv[i]) % DIV;
				c[N-i] = c[i];
			}
		}
		long long int r1=0,r2=0;
		for(int i=0;i<n;i+=2){
			r1 = (r1 + a[i] * c[i/2]) % DIV;
			r2 = (r2 + a[i+1] * c[i/2]) % DIV;
			// printf("%lld %lld\n",r1,r2);
		}
		long long int flag = (n*(n-1)/2)%2;
		if(!flag)
			printf("%lld",(r1-r2+DIV)%DIV);
		else
			printf("%lld",(r1+r2+DIV)%DIV);
	}
	return 0;
}
#include<stdio.h>

int main(){
	long long int n,a[200000]={0},b[200000]={0};
	scanf("%lld",&n);
	long long temp = n*(n-1)/2;
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(n==1)
		printf("%lld",a[0]);
	else if(n==2)
		printf("%lld",(a[0]+a[1])%1000000007);
	else if(n==3)
		printf("%lld",((a[0]+a[1])%1000000007+(a[1]-a[2])%1000000007)%1000000007);
	else{
		if(n%2){
			for(int i=0;i<n-1;i++){
				if((i+1)%2)
					b[i] = (a[i] + a[i+1] + 1000000007) % 1000000007;
				else
					b[i] = (a[i] - a[i+1] + 1000000007) %1000000007;
			}
			for(int i=0;i<n-1;i++){
				a[i] = b[i];
				b[i] = 0;
			}
			n-=1;
		}
		int N = n/2-1;
		long long int su[200005]={0};
		for(int k=0;k<=N/2;k++){
			long long int t1=1,t2=1;
			for(int i=1;i<=k;i++){
				t1 = (t1 * (N-i+1))%1000000007;
				t2 = (t2 * i)%1000000007;
			}
			su[k] = t1/t2%1000000007;
			su[N-k] = su[k];
		}
		for(int i=0,j=1,x=0;x<=n/2;i+=2,j+=2,x++){
			b[0] = (b[0] + a[i]*su[i/2]%1000000007)%1000000007;
			b[1] = (b[1] + a[j]*su[i/2]%1000000007)%1000000007;
		}
		if(temp%2)
			b[0] = (b[0] + b[1])%1000000007;
		else
			b[0] = (b[0] - b[1])%1000000007;
		if(b[0]<0)
			printf("%lld",b[0]+1000000007);
		else
			printf("%lld",b[0]);
	}
	return 0;
}
#include<stdio.h>

int data[1005][1005];
int main(){
    int n,m,t = 1000000007;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0)
                data[i][j] = 1;
            else
                data[i][j] = ((data[i-1][j] + data[i][j-1])%t + data[i-1][j-1])%t;
        }
    }
    printf("%d",data[n-1][m-1]);
    return 0;
}
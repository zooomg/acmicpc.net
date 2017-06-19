#include<stdio.h>

int main(){
    int n,d1[305][305]={0},d2[305][305]={0},r[305][305]={0},cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&d1[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&d2[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                 r[i][j]|=d1[i][k]&d2[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cnt+=r[i][j];
    printf("%d",cnt);
    return 0;
}
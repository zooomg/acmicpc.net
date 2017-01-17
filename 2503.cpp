// 2503 숫자야구
// KOI 2008 지역본선 초등부 3번

// 123~987까지 모든 수에 대해
// S, B 개수를 세서 비교

#include<stdio.h>

int main(){
    int n,cnt=0;
    scanf("%d",&n);
    int num[100][5]={0};
    for(int i=0;i<n;i++)
        scanf("%1d%1d%1d%d%d",&num[i][0],&num[i][1],&num[i][2],&num[i][3],&num[i][4]);
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i==j) continue;
            for(int k=1;k<10;k++){
                if(i==k || j==k) continue;
                int p=1;
                for(int l=0;l<n;l++){
                    int s=0,b=0;
                    if(num[l][0]==i)
                        s++;
                    if(num[l][1]==j)
                        s++;
                    if(num[l][2]==k)
                        s++;
                    if(num[l][1]==i || num[l][2]==i)
                        b++;
                    if(num[l][0]==j || num[l][2]==j)
                        b++;
                    if(num[l][0]==k || num[l][1]==k)
                        b++;
                    if(num[l][3]!=s || num[l][4]!=b){
                        p=0;
                        break;
                    }
                }
                if(p) cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}

// 문제 범위 잘못읽어서 한번 틀림
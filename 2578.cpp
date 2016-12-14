// 2578	 빙고
// KOI 2006 지역본선 초등부 3번

#include<stdio.h>

int main(){
    int bingo[26][6]={0},check[6][6]={0};
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++){
            int x;
            scanf("%d",&x);
            bingo[x][i]=j;
        }
    for(int k=1;k<=25;k++){
        int x,i;
        scanf("%d",&x);
        for(i=1;i<=5;i++){
            if(bingo[x][i]!=0)
                break;
        }
        check[i][bingo[x][i]]=1;
        int cnt=0;
        for(int a=1;a<=5;a++){
            int s1 = check[5][a]+check[1][a]+check[2][a]+check[3][a]+check[4][a];
            int s2 = check[a][5]+check[a][1]+check[a][2]+check[a][3]+check[a][4];
            if(s1==5) cnt++;
            if(s2==5) cnt++;
        }int s1=0,s2=0;
        for(int a=1;a<=5;a++){
            s1 += check[6-a][a];
            s2 += check[a][a];
        }
        if(s1==5) cnt++;
        if(s2==5) cnt++;
        if(cnt>=3){
            printf("%d",k);
            break;
        }
    }
    return 0;
}
// 그냥 구현 문제
// 어떻게 빙고판을 받을지 채울지 다양하게 존재
// 어떻게 빙고판에 있는 숫자를 찾을지 다양하게 존재

#include <stdio.h>
int bingo[5][5], t, a[5], b[5], c[9], d[9], i, j, cnt;
main()
{
    for(i=0; i<25; i++)
    scanf("%d", &bingo[i/5][i%5]);
    for(i=0; i<25; i++)
    {
        scanf("%d", &t);
        for(j=0; j<25; j++)
        {
            if(bingo[j/5][j%5]==t)
            {
                a[j/5]++;if(a[j/5]==5)cnt++;
                b[j%5]++;if(b[j%5]==5)cnt++;
                c[j/5+j%5]++;if(c[j/5+j%5]==5)cnt++;
                d[j/5-j%5+4]++;if(d[j/5-j%5+4]==5)cnt++;
                break;
            }
        }
        if(cnt>=3)break;
    }
    printf("%d", i+1);
}
// 몫에 해당하는게 가로, 나머지에 해당하는게 세로
// 사회자가 부른 숫자를 받아 빙고판에 숫자를 채운 것 처럼
// j를 0부터 시작해 몫과 나머지로 빙고판에 숫자위치를 찾음
// a,b,c,d는 각각 가로줄압축, 세로줄압축, 대각선1압축, 대각선2압축
// 각각의 개수가 만약 5라면 다 채워진 경우임으로 count해줌
// count된 결과가 만약 3이상이면 빙고!
// 여기서 함정은 2줄 빙고에서 갑자기 4줄 빙고를 할 수 있으므로
// cnt가 3이상일때 탈출하도록 해줘야된다
// 딱 3일때 탈출하도록 하면 틀림
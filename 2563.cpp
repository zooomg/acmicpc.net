// 2563	 색종이
// KOI 2007 지역본선 초등부 2번

#include<stdio.h>

int main(){
    int n,data[100][100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        for(int j=x;j<x+10;j++){
            for(int k=y;k<y+10;k++){
                data[k][j]=1;
            }
        }
    }int sum=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            sum+=data[i][j];
        }
    }
    printf("%d",sum);
    return 0;
}
// 좌표에 해당하는 배열의 칸에 1을 추가함으로써
// 색칠한다는 개념으로 생각하면 된다
// 1은 색종이가 덮힌 부분
// 0은 색종이가 덮히지 않은 부분
// 덮힌 부분의 넓이를 구하려면
// 도화지에 1로 색칠된 부분의 크기를 구하면 된다.
// 그러면 1을 모두 더해주면 넓이가 된다.

// 이게 어떻게 가능하냐면
// 1*1은 1이다 만약에 점이라고 한다면 넓이가 있을 수 없다
// (1,1) (2,2)에 해당하는 사각형은 (2-1)*(2-1) = 1
// 1부터 2미만까지의 점에 색칠을 하면 넓이를 빠르게 구할 수 있다
// 지금 약을 먹고 설명하려니 횡설수설한거 같다
￼
// 빨간색 글자는 배열의 인덱스를 뜻하고
// 검은색 글자는 좌표값을 뜻한다
// 좌표와 배열을 이용한 넓이 구하기
// 자세한 설명은 제정신일때

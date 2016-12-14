// 10253 헨리

// 1차 시간초과 : x를 구하는데 for문을 돌렸다
// => 부등식을 수학식으로 바꿔보면
// 	 b <= a*x , b/a <= x , x = b/a+1
// 2차 시간초과 : a,b를 기약분수꼴로 바꿔주지 않았다
// => 쓸데없이 while문을 더 돌아서 시간초과 발생
// => gcd를 이용하여 기약분수로 바꿔줌

#include<stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,x;
        scanf("%d%d",&a,&b);
        while(a!=1){
            x=b/a+1;
            a=a*x-b,b=b*x;
            int g=gcd(a,b);
            a/=g,b/=g;
        }
        printf("%d\n",b);
    }
    return 0;
}
// b <= ax(1)
// bx(1) <= (ax(1)-b)x(2)
// bx(1)를 tb로 치환, (ax(1)-b)를 ta로 치환
// tb <= tbx(2)
// 제일 처음식과 똑같아짐
// 반복문으로 만들 수 있어짐

// 탈출 조건은 모든 분수의 합이 초기 a/b와 같아야한다
// a/b에서 1/x를 계속해서 빼주다가 분자 a가 1이 되는 순간의 b값이 정답이다
// 분자가 1이 되는 순간이 마지막 x값이기 때문이다
// x를 계속해서 구할때 a/b에서 빼준다 => ta값이 1이 되는 순간 tb의 값이 정답이다
// 2774	아름다운 수

#include<stdio.h>

int main(){
    int t;
    for(scanf("%d",&t);t;t--){
        char data[15];
        scanf("%s",data);
        bool check[10]={0};
        for(int i=0;data[i];i++){
            check[data[i]-'0']=1;
        }
        int cnt=0;
        for(int i=0;i<10;i++){
            if(check[i])
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

// 이 문제는 앞서 많이 풀었던
// 숫자를 ‘키값’으로 활용하는 문제이다.
// 서로 다른 숫자를 찾으면 되는 문제.
// 문자열로 받아서 하나씩 잘라서 어떤 숫자인지 분류해주고
// 문자로 받았기때문에 아스키 코드 값으로 들어가있으니
// ‘0’ 값을 빼주는 것이 포인트
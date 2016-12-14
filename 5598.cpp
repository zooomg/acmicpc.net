// 5598	 카이사르 암호

#include<stdio.h>

int main(){
    char s[1005]={0};
    scanf("%s",s);
    for(int i=0;s[i];i++){
        s[i]=s[i]-3;
        if(s[i]<'A')
            s[i]=s[i]-'A'+'Z'+1;
    }
    printf("%s",s);
    return 0;
}

// ‘D’와 ‘A’가 3차이가 나는 것을 알 수 있다.
// 단순히 3을 빼줄때 A B C 를 예외처리 해줘야한다.
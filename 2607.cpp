// 2607	 비슷한 단어
// KOI 2004 지역본선 초등부 4번

#include<stdio.h>
#define ABS(a)(((a) < (0))?-(a):(a))

int main(){
    int n,cnt=0,i,j;
    scanf("%d",&n);
    char s1[15],s1_check[27]={0},s1_len;
    scanf("%s",s1);
    for(i=0;s1[i];i++){
        s1_check[s1[i]-'A']+=1;
    }
    s1_len=i;
    for(i=1;i<n;i++){
        char s2[15],s2_check[27]={0},diff=0,flag=0,s2_len;
        scanf("%s",s2);
        for(j=0;s2[j];j++){
            s2_check[s2[j]-'A']+=1;
        }
        s2_len = j;
        if(ABS(s1_len-s2_len)>1)
            continue;
        for(j=0;j<27;j++){
            if(ABS(s1_check[j]-s2_check[j])==1)
                diff++;
            else if(ABS(s1_check[j]-s2_check[j])>1){
                flag = 1;
                break;
            }
        }
        if(diff<=2 && flag == 0)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
// 같은 구성을 갖는 조건 => 두 문자열 길이 차이가 0이여야한다, 같은 종류 문자로 이루어져 있어야한다.
// 비슷한 구성을 갖는 조건 => 1. 두 문자열의 길이 차이가 1이하여야한다.
// 왜냐하면 단어를 하나 더하거나 빼거나 바꾸기때문에 2이상 차이나면 단어 하나를 다루는게 불가능하기 때문이다.
// 2. 두 문자열에서 같은 단어의 개수차이가 무조건 1이여야한다.
// 2이상일 경우 단어 하나를 더해주거나 바꿔도 만족시켜 줄 수 없기 때문이다.
// 3. 두 문자열에서 같은 단어의 개수차이가 1인 단어가 2개 이하여야 한다.
// 2개일 경우 하나의 단어를 다른 단어로 바꾼 경우고
// 1개일 경우 하나의 단어를 추가하거나 빼준 경우다.
// 0개일 경우 완전히 같은 구성이다.

// 크리티컬 : OO OOOM
// 1개 차이나는 단어가 2개인데 길이 차이가 2이상인 경우
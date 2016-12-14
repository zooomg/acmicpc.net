// 10757	 큰 수 A+B

#include<stdio.h>
#include<string.h>

int main(){
    char s1[10005]={0},s2[10005]={0},r[20005]={0};
    scanf("%s %s",s1,s2);
    int s1_len = strlen(s1),s2_len = strlen(s2);
    for(int i = 0;i<s1_len/2;i++){
        char temp = s1[i]-'0';
        s1[i] = s1[s1_len-i-1]-'0';
        s1[s1_len-i-1] = temp;
    }if(s1_len%2==1) s1[s1_len/2] -= '0';
    for(int i = 0;i<s2_len/2;i++){
        char temp = s2[i]-'0';
        s2[i] = s2[s2_len-i-1]-'0';
        s2[s2_len-i-1] = temp;
    }if(s2_len%2==1) s2[s2_len/2] -= '0';
    s1_len = s1_len > s2_len ? s1_len : s2_len;
    for(int i=0;i<s1_len;i++){
        r[i] += s1[i]+s2[i];
        r[i+1] = r[i]/10;
        r[i] = r[i]%10;
    }
    if(r[s1_len]!=0)
        printf("%d",r[s1_len]);
    for(int i=s1_len-1;i>=0;i--){
        printf("%d",r[i]);
    }
    return 0;
}
// 두 수의 제일 앞자리에서 10이 넘어가게 되면 두 수의 길이 중 큰 수보다 하나 더 출력해줘야되고,
// 아니라면 출력해줘서는 안된다.
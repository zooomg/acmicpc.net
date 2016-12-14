// LCS

#include<stdio.h>

int main(){
    char s1[1005]={0},s2[1005]={0};
    scanf("%s\n%s",s1,s2);
    int data[1005][1005]={0},s1_len,s2_len;
    for(s1_len=0;s1[s1_len];s1_len++);
    for(s2_len=0;s2[s2_len];s2_len++);
    for(int i=1;i<=s1_len;i++){
        for(int j=1;j<=s2_len;j++){
            if(s1[i-1]==s2[j-1]){
                data[i][j] = data[i-1][j-1]+1;
            }
            else{
                data[i][j] = data[i][j-1] > data[i-1][j] ? data[i][j-1] : data[i-1][j];
            }
        }
    }
    printf("%d",data[s1_len][s2_len]);
    return 0;
}
// 2608	 로마 숫자
// KOI 2004 지역본선 초등부 5번

#include<stdio.h>
#include<string.h>
// 0 1 2 3 4 5 6 7 8 9 10 11 12
// 0 2 4 6 8 10 12
// I(0) => IV(1) IX(3) V(2) X(4)
// X(4) => XL(5) XC(7) L(6) C(8)
// C(8) => CD(9) CM(11) D(10) M(12)
int data[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
char giho[13][3]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
int roma(char s[20]){
    int n=0;
    for(int i=0;s[i];i++){
        for(int j=12;j>=0;j-=2){
            if(s[i]==giho[j][0]){
                if(j==0||j==4||j==8){
                    if(s[i+1]==giho[j+2][0]){
                        i++;
                        n+=data[j+1];
                    }
                    else if(s[i+1]==giho[j+4][0]){
                        i++;
                        n+=data[j+3];
                    }
                    else{
                        n+=data[j];
                    }
                }
                else{
                    n+=data[j];
                }
            }
        }
    }
    return n;
}
int main(){
    char s1[20],s2[20];
    scanf("%s %s",s1,s2);
    int result = roma(s1)+roma(s2);
    printf("%d\n",result);
    while(result){
        for(int i=12;i>=0;i--){
            if(result>=data[i]){
                result-=data[i];
                printf("%s",giho[i]);
                break;
            }
        }
    }
    return 0;
}
// greedy
// 로마자->10진수 : 0,4,8기호 다음기호가 +2 혹은 +4 가 맞다면 +1 혹은 +3 규칙
// 10진수 -> 로마자 : 큰수부터 빼주면서 로마자로 바꿔주면 짧음
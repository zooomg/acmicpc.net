// 5052 전화번호목록

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<list>
#include<algorithm>
using namespace std;
int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        string s[10005];
        int n;
        scanf("%d\n",&n);
        for(int j=0;j<n;j++)
            getline(cin,s[j]);
        sort(s,s+n);
        bool flag = false;
        for(int j=0;j<n;j++){
            if(strstr(s[j+1].c_str(),s[j].c_str())){
                printf("NO\n");
                flag = true;
                break;
            }
        }
        if(!flag) printf("YES\n");
    }
    return 0;
}


//#include<stdio.h>
//#include<string.h>
//
//int main(){
//    int n;
//    scanf("%d",&n);
//    while(n--){
//        int m;
//        bool data[10][10][100000]={0};
//        scanf("%d",&m);
//        char s[100005][15]={0};
//        for(int i=0;i<m;i++){
//            scanf("%s",s[i]);
//            for(int j=0;s[i][j];j++){
//                data[j][s[i][j]-'0'][i]=1;
//            }
//        }
//        bool flag = true;
//        for(int i=0;i<m;i++){
//            int check[100000]={0},j;
//            for(j=0;s[i][j];j++){
//                for(int k=0;k<m;k++){
//                    if(k!=i && data[j][s[i][j]-'0'][k])
//                        check[k]++;
//                }
//            }
//            int len = j;
//            for(j=0;j<m;j++){
//                if(check[j]==len){
//                    flag = false;
//                    break;
//                }
//            }
//            if(!flag) break;
//        }
//        if(flag) printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}

// http://m.blog.naver.com/kks227/220576143081
// 트라이 - 트리형태

// http://joonas-yoon.blogspot.kr/2016/03/5052.html
// 정렬 - 아이디어
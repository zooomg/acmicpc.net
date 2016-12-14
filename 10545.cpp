// 10545 뚜기뚜기메뚜기

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int key[11],p=-1;
    for(int i=1;i<=9;i++){
        int x;
        scanf("%d",&x);
        key[x]=i;
    }
    string word,board[10]={"\0","\0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    cin >> word;
    for(int i=0;i<word.length();i++){
        for(int j=0;j<10;j++){
            int t = board[j].find(word[i]);
            if(t!=string::npos){
                if(p==j) printf("#");
                for(int k=0;k<=t;k++)
                    printf("%d",key[j]);
                p=j;
            }
        }
    }
    return 0;
}
//abcdefghijklmnopqrstuvwxyz


//해싱문제
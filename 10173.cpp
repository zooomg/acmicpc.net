// 10173	니모를 찾아서 

#include<stdio.h>

int main(){
    while(1){
        char data[1005]={0};
        int flag=1;
        gets(data);
        if(data[0]=='E'&&data[1]=='O'&&data[2]=='I'&&data[3]=='\0')
            break;
        for(int i=0;data[i+3]!='\0';i++){
            if(data[i]=='N'||data[i]=='n'){
                if((data[i+1]=='e'||data[i+1]=='E')&&(data[i+2]=='m'||data[i+2]=='M')&&(data[i+3]=='o'||data[i+3]=='O')){
                    printf("Found\n");
                    flag=0;
                    break;
                }
            }
        }
        if(flag) printf("Missing\n");
    }
    return 0;
}

// gets는 newline 문자를 받지않는다(‘\n’)
// fgets는 newline 문자까지 받는다
// 9536 여우는 어떻게 울지?

// 문자열 예제로 좋은듯
// 문자열끼리 == 사용 가능
// getline 연습
// substr()

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main(void)
{
    int t;
    
    scanf("%d ", &t);
    
    while (t--)
    {
        string a, b;
        
        getline(cin, a);
        
        string s[100];
        int idx = 0;
        
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == ' ')
                idx++;
            else
                s[idx] += a[i];
        }
        
        while (1)
        {
            getline(cin, b);
            
            if (b == "what does the fox say?")
            {
                for (int i = 0; i <= idx; i++)
                    if (s[i] != "\0")
                        cout << s[i] << " ";
                break;
            }
            
            int slice, cnt = 0;
            
            for (int i = 0; i < b.length(); i++)
            {
                if (b[i] == ' ')
                    cnt++;
                if (cnt == 2)
                {
                    slice = i + 1;
                    break;
                }
            }
            
            string c = b.substr(slice);
            for (int i = 0; i <= idx; i++){
                if (s[i] == c)
                    s[i] = "\0";
            }
        }
    }
    
    return 0;
}
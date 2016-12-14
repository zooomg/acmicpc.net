// 1431 시리얼 번호

#include<stdio.h>
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d\n",&n);
    vector<tuple<int,int,string>> v;
    
    //입력
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        int sum=0;
        for(auto x : s)
            if('0'<=x&&x<='9')
                sum+=x-'0';
        v.push_back(make_tuple(s.length(),sum,s));
    }
    
    // sort
    sort(v.begin(),v.end());
    
    //출력
    for(auto x : v){
        printf("%s\n",get<2>(x).c_str());
    }
    return 0;
}

// sort가 알아서 first값이 같으면 second로 넘어가서 비교하고
// 만약 같다면 다시 third로 넘어가서 비교하기 때문에
// tuple을 사용하여 문제에 나온 비교 우선순위에 따라
// (길이, 숫자합, 알파벳순)
// 변수를 저장한 뒤 sort


struct sort_pred {
    bool operator()(const std::pair<string,int> &left, const std::pair<string,int> &right) {
        if(left.first.length() == right.first.length()){
            int sum1=0,sum2=0;
            for(char x : left.first){
                if('0' <= x && x <= '9')
                    sum1 += x-'0';
            }
            for(char x : right.first){
                if('0' <= x && x <= '9')
                    sum2 += x-'0';
            }
            if(sum1 == sum2)
                return left.second < right.second;
            else
                return sum1 < sum2;
        }
        else
            return left.first.length() < right.first.length();
    }
};
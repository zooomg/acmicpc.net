
// http://bowbowbow.tistory.com/8

// http://blog.myungwoo.kr/57

// http://koosaga.myungwoo.kr/entry/Suffix-Array-접미사-배열

// https://algospot.com/forum/read/2779/

// https://ko.wikipedia.org/wiki/접미사_배열

// https://publications.mpi-cbg.de/Manber_1993_5474.pdf

// Suffix Array - 맨버-마이어스

#include<vector>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#define MAXN 500005

int N,SA[MAXN],lcp[MAXN];
char S[MAXN];

void SuffixArray(){
    int m = 26,i;
    vector <int> cnt(max(N,m)+1,0),x(N+1,0),y(N+1,0);
    for (i=1;i<=N;i++) cnt[x[i] = S[i]-'a'+1]++;
    for (i=1;i<=m;i++) cnt[i] += cnt[i-1];
    for (i=N;i;i--) SA[cnt[x[i]]--] = i;
    for (int len=1,p=1;p<N;len<<=1,m=p){
        for (p=0,i=N-len;++i<=N;) y[++p] = i;
        for (i=1;i<=N;i++) if (SA[i] > len) y[++p] = SA[i]-len;
        for (i=0;i<=m;i++) cnt[i] = 0;
        for (i=1;i<=N;i++) cnt[x[y[i]]]++;
        for (i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for (i=N;i;i--) SA[cnt[x[y[i]]]--] = y[i];
        swap(x,y); p = 1; x[SA[1]] = 1;
        for (i=1;i<N;i++)
            x[SA[i+1]] = SA[i]+len <= N && SA[i+1]+len <= N && y[SA[i]] == y[SA[i+1]] && y[SA[i]+len] == y[SA[i+1]+len] ? p : ++p;
    }
    for(i=1;i<=N;i++) printf("%d ",SA[i]);
    printf("\nx ");
}
void LCP(){
    int i,j,k=0;
    vector <int> rank(N+1,0);
    for (i=1;i<=N;i++) rank[SA[i]] = i;
    for (i=1;i<=N;lcp[rank[i++]]=k)
        for (k?k--:0,j=SA[rank[i]-1];S[i+k]==S[j+k];k++);
    for(i=2;i<=N;i++) printf("%d ",lcp[i]);
}
int main(){
    scanf("%s",S);
    N = strlen(S);
    for(int i=N;i>=0;i--) S[i+1] = S[i];
    SuffixArray(),LCP();
    return 0;
}




#include<vector>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

//struct Comparator{
//    vector<int>& group;
//    int t;
//    Comparator(vector<int>& _group, int _t): group(_group),t(_t) {
//        group = _group;
//        t = _t;
//    }
//    bool operator () (int a, int b){
//        if(group[a] != group[b]) return group[a] < group[b];
//        return group[a+t] < group[b+t];
//    }
//};
//
//vector<int> getSuffixArray(const string& s){
//    int n = s.size();
//    int t=1;
//    vector<int> group(n+1);
//    for(int i=0;i<n;i++) group[i] = s[i];
//    group[n] = -1;
//    vector<int> perm(n);
//    for(int i=0;i<n;i++) perm[i]=i;
//    while(t<n){
//        Comparator compareUsing2T(group,t);
//        sort(perm.begin(),perm.end(),compareUsing2T);
//        t*=2;
//        if(t>=n) break;
//        vector<int> newGroup(n+1);
//        newGroup[n] = -1;
//        newGroup[perm[0]] = 0;
//        for(int i=1;i<n;i++){
//            if(compareUsing2T(perm[i-1],perm[i]))
//                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
//            else
//                newGroup[perm[i]] = newGroup[perm[i-1]];
//        }
//        group = newGroup;
//    }
//    return perm;
//}
//int commonPrefix(const string& s,int i,int j){
//    int k=0;
//    while(i<s.size() && j<s.size() && s[i] == s[j]){
//        ++i,++j,++k;
//    }
//    return k;
//}
//int countSubstrings(const string& s){
//    vector<int> a = getSuffixArray(s);
//    int ret = 0;
//    int n = a.size();
//    for(int i=0;i<n;i++)
//        printf("%d ",a[i]+1);
//    printf("\nx ");
//    for(int i=1;i<n;i++){
//        int cp=commonPrefix(s, a[i-1], a[i]);
//        printf("%d ",cp);
//    }
//    return ret;
//}
#define MAXN 500005

int N,SA[MAXN];
char S[MAXN];

void SuffixArray()
{
    int i,j,k;
    int m = 26; // 처음 알파벳 개수
    vector <int> cnt(max(N,m)+1,0),x(N+1,0),y(N+1,0);
    for (i=1;i<=N;i++) cnt[x[i] = S[i]-'a'+1]++;
    for (i=1;i<=m;i++) cnt[i] += cnt[i-1];
    for (i=N;i;i--) SA[cnt[x[i]]--] = i;
    
    for(i=1;i<=N;i++) printf("%d ",SA[i]);
    printf("\n");
    
    for (int len=1,p=1;p<N;len<<=1,m=p){
        for (p=0,i=N-len;++i<=N;){ y[++p] = i; printf("%d,%d ",p,y[p]);} printf("\t");
        for (i=1;i<=N;i++) {if (SA[i] > len) y[++p] = SA[i]-len; printf("%d,%d ",p,y[p]);}printf("\n");
        for (i=0;i<=m;i++) cnt[i] = 0;
        for (i=1;i<=N;i++) cnt[x[y[i]]]++;
        for (i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for (i=N;i;i--) SA[cnt[x[y[i]]]--] = y[i];
        swap(x,y); p = 1; x[SA[1]] = 1;
        for (i=1;i<N;i++)
            x[SA[i+1]] = SA[i]+len <= N && SA[i+1]+len <= N && y[SA[i]] == y[SA[i+1]] && y[SA[i]+len] == y[SA[i+1]+len] ? p : ++p;
    }
    printf("\n");
    for(i=1;i<=N;i++) printf("%d ",SA[i]);
}


int main(){
//    string s;
//    cin >> s;
//    getSuffixArray(s);
//    countSubstrings(s);
    scanf("%s",S);
    N = strlen(S);
    for(int i=N;i>=0;i--) S[i+1] = S[i];
    SuffixArray();
    return 0;
}


// 11004 K번째수

// 단순 sort를 이용해 k번째 수 뽑아내는 방법 시간초과
// 퀵소트 pivot을 이용해 푸는 방법 시간초과
// stl std::nth_element로 풀면 바로 풀림 망할

// #include<stdio.h>

// int n,k;
// long long int data[5000005];
// long long int quick(int l,int r){
//     int i=l,j=r;
//     long long int pivot=data[(l+r)/2];
//     while(i<=j){
//         while(pivot>data[i])
//             i++;
//         while(pivot<data[j])
//             j--;
//         if(i<=j){
//             long long int temp = data[i];
//             data[i] = data[j];
//             data[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     if(i+1<k){
//         return quick(i,r);
//     }
//     else if(i+1>k){
//         return quick(l,j);
//     }
//     else{
//         return data[i];
//     }
// }
// int main(){
//     scanf("%d%d",&n,&k);
//     for(int i=0;i<n;i++)
//         scanf("%lld",&data[i]);
//     printf("%lld",quick(0,n-1));
//     return 0;
// }

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    nth_element(v.begin(), v.begin()+k-1, v.end());
    printf("%d",v[k-1]);
    return 0;
}

// 5 3 7 6 2 1 4
// i	 p	   j
// 5 3 4 6 2 1 7
//        i  p       j
// 5 3 4 6 2 1 7
//           p    j  i
// 5 3 4 1 2 6 7

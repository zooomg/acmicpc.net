// COCI 2015/2016
// 물건 3개를 사면 가장 싼 물건 하나가 무료
// 그렇다면 3개씩 뽑아낸 상태에서 항상 제일 적은 값이 빠지니까
// 정렬된 상태에서 3개씩 뽑으면서
// 앞서서 3개로 묶였던 애들을 다시 묶으면 손해
// 이를 정리하면 내림차순으로 정렬한 뒤 3번째 값을 빼주면 답
// Greedy
#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int n,data[100005]={0},sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
		sum+=data[i];
	}
	sort(data,data+n,greater<int>());
	for(int i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	for(int i=0;i<n/3;i++){
		sum-=data[i*3+2];
	}
	printf("%d",sum);
	return 0;
}
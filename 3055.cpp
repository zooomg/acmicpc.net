#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

char data[55][55];
int flood[55][55];
int check[55][55];
int n,m,w_i[2505],w_j[2505],e_i,e_j,s_i,s_j;
int bfs(int y, int x, bool flag){
	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(y,x),0));
	if(flag) check[y][x] = 0;
	else flood[y][x]=0;
	int d_x[5] = {0,0,-1,1};
	int d_y[5] = {-1,1,0,0};
	while(!q.empty()){
		pair<pair<int,int>,int> temp = q.front();
		int i = temp.first.first;
		int j = temp.first.second;
		int v = temp.second;
		q.pop();
		for(int k=0;k<4;k++){
			int ii = i + d_x[k];
			int jj = j + d_y[k];
			if(-1 < ii && ii < n && -1 < jj && jj < m){
				if(!flag){
					 if(data[ii][jj]=='.' && (flood[ii][jj]==0 || flood[ii][jj]>v+1)){
						flood[ii][jj] = v+1;
						q.push(make_pair(make_pair(ii,jj),v+1));
					}
				}
				else{
					if((flood[ii][jj]==0 || flood[ii][jj]>v+1) && check[ii][jj]==0 && data[ii][jj]=='.'){
						check[ii][jj] = v+1;
						q.push(make_pair(make_pair(ii,jj),v+1));
					}
					if(check[ii][jj]==0 && data[ii][jj]=='D'){
						check[ii][jj] = v+1;
					}
				}
			}
		}
	}
	return check[e_i][e_j];
}

int main(){
	int cnt=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",data[i]);
		for(int j=0;j<m;j++){
			// scanf("%c",&data[i][j]);
			if(data[i][j]=='*'){
				w_i[cnt]=i;
				w_j[cnt++]=j;
			}
			else if(data[i][j]=='S'){
				s_i=i;
				s_j=j;
			}
			else if(data[i][j]=='D'){
				e_i=i;
				e_j=j;
			}
		}
		if(i==n-1) break;
		// scanf("\n");
	}
	for(int i=0;i<cnt;i++){
		bfs(w_i[i],w_j[i],0);
	}
	int num = bfs(s_i,s_j,1);
	if(num)
		printf("%d",num);
	else
		printf("KAKTUS");
	return 0;
}
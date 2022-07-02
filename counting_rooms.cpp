#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<utility>
#include<map>
#include<set>
#include<queue>
#define speedUp ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
int n,m;
bool isvalid(int i, int j){
	if(i>=0 && i < n && j >=0 && j <m)return true;
	return false;
}
 
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
 
void dfs(vector<vector<char>> &a, vector<vector<bool>> &b, int i , int j ){
	b[i][j] = true;
	for(int k = 0; k < 4; k++){
		if(isvalid(i+dr[k],j+dc[k]) && !b[i+dr[k]][j+dc[k]] && a[i+dr[k]][j+dc[k]]=='.'){
			dfs(a,b,i+dr[k],j+dc[k]);
		}
	}
}
 
void solve(void){
	cin >> n >> m;
	vector<vector<char>> a(n,vector<char> (m));
	vector<vector<bool>> b(n,vector<bool> (m,false));
	for(int i =0 ; i <n ; i++){
		for(int j = 0 ; j< m ; j++){
			cin >> a[i][j];
		}
	}
	int count = 0; 
	for(int i = 0 ; i < n ;i++){
		for(int j = 0 ; j < m ; j++){
			if(!b[i][j] && a[i][j]=='.'){
				dfs(a,b,i,j);
				count++;
			}
		}
	}
	cout << count << "\n";
}
 
int main(){
	speedUp;
	int tc=1;
	//cin >> tc;
	while(tc--){
		solve();
	}
	return 0;
}
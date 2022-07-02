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
 
void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis){
	vis[i] = true;
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		if(!vis[k]){
			dfs(k,adj,vis);
		}
	}
}
 
void solve(void){
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	int a,b;
	for(int i = 0 ; i < m; i++){
		cin >> a>> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> ans;
	vector<bool> vis(n+1,false);
	for(int i =1; i <n+1 ; i++){
		if(!vis[i]){
			dfs(i,adj,vis);
			ans.push_back(i);
		}
	}
	if(ans.size()==1){
		cout << "0\n";
	}
	else{
		cout << ans.size()-1 << "\n";
		for(int i = 1; i < ans.size() ; i++){
			cout << ans[i-1] << " " << ans[i] << "\n";
		}
	}
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
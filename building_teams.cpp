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
 
void bfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &d, vector<int> &p, int s){
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int j = 0; j < adj[v].size(); j++){
			int k = adj[v][j];
			if(!vis[k]){
				p[k] = v;
				d[k] = d[v]+1;
				vis[k] = true;
				q.push(k);
			}
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
	vector<int> d(n+1,-1);
	vector<int> p(n+1,-1);
	int s = 1;
	int t = n;
	d[s] = 1;
	p[s] = -1;
	bfs(adj,vis,d,p,s);
	if(d[n]==-1){
		cout << "IMPOSSIBLE\n";
	}
	else{
		cout << d[n] << '\n';
		int t = n;
		vector<int> ans;
		while(t!=-1){
			ans.push_back(t);
			t = p[t];
		}
		for(int i = ans.size()-1; i >=0; i--){
			cout << ans[i] << " ";
		}cout << "\n";
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
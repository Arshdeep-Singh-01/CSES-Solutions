#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int n,m;

bool isvalid(int i, int j){
    if(i<n && i>=0 && j>=0 && j <m){
        return true;
    }
    return false;
}


bool bfs(vector<vector<char>> &adj, pair<int,int> s, pair<int,int> e,vector<vector<pair<int,int>>> &par,vector<vector<bool>> &vis){
    queue<pair<int,int>> q;
    q.push(s);
    vis[s.first][s.second] = true;
    par[s.first][s.second] = {-5,-5};
    while(!q.empty()){
        pair<int,int> v = q.front();
        q.pop();
        //cout << v.first << " " << v.second << '\n';
        for(int i  = 0; i < 4; i++){
            int r = v.first + dr[i];
            int c = v.second + dc[i];
            if(isvalid(r,c) && !vis[r%n][c%m] && adj[r%n][c%m]!='#'){
                par[r][c] = v;
                vis[r][c] = true;
                q.push({r,c});
            }
        }
    }
    if(vis[e.first][e.second])return true;
    return false;
}

string get_path(vector<vector<pair<int,int>>> &par, pair<int,int> s, pair<int,int> e, vector<vector<bool>> &vis){
    string ans;
    int r = e.first;
    int c = e.second;
    pair<int,int> tr = e;
    map<int, char> mp;
    mp.insert({0,'U'});
    mp.insert({1,'R'});
    mp.insert({2,'D'});
    mp.insert({3,'L'});
    while(true){
        tr = par[r][c];
        if(tr==make_pair(-5,-5))break;
        for(int i = 0; i < 4; i++){
            int x = tr.first + dr[i];
            int y = tr.second + dc[i];
            if(isvalid(x,y) && x==r && y==c && vis[x][y]){
                ans.push_back(mp[i]);
                r = tr.first;
                c = tr.second;
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    cin >> n >> m;
    pair<int,int> s,e;
    vector<vector<char>> adj((n),vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ;j++){
            cin >> adj[i][j];
            if(adj[i][j]=='A'){
                s = {i,j};
            }
            if(adj[i][j]=='B'){
                e = {i,j};
            }
        }
    }
    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>> (m));
    bool ans = bfs(adj,s,e,par,vis);
    cout << ((ans)?"YES":"NO") << "\n";
    if(ans){
        string st = get_path(par,s,e,vis);
        cout << st.length() << "\n";
        cout << st << "\n";
    }
}
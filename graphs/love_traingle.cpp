#include<bits/stdc++.h>
using namespace std;

typedef unordered_set<int> us_int;
typedef vector<int> vc_int;
typedef unordered_map<int, vc_int> um_vc;
typedef unordered_map<int, int> um_int;

bool cycle(um_vc &g, int node, us_int &v, us_int &bv, um_int &dis, int dist, int &lnth){
  v.insert(node);
  bv.insert(node);
  dis[node] = dist;
  for(auto &tmp: g[node]){
    if(!v.count(tmp) && cycle(g, tmp, v, bv, dis, dist + 1, lnth))return true;
    else if(bv.count(tmp)){
      lnth = max(lnth, dist + 1 - dis[tmp]);
      bv.erase(tmp);
      return true;
    }
  }
  bv.erase(node);
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vc_int v(n, 0);
  for(int i=0; i<n; i++)
    cin>>v[i];
  um_vc um;
  us_int visit;
  us_int bv;
  um_int dis;
  for(int i = 1; i <= n; i++)um[i] = vc_int();
  int i = 0;
  for(auto &t: v){
    um[i].push_back(v[i]);
    i++;
  }
  int lnth = 0, flag = 0;
  for(int j = 0; j < n; j++){
    if(!visit.count(j+1)){
      cycle(um, j+1, visit, bv, dis, 0, lnth);
      if(lnth == 3){
        cout<<"YES";
        flag = 1;
        break;
      }
    }
  }
  if(flag == 0)cout<<"NO";
}

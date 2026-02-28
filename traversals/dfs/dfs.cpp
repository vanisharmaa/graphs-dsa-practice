#include <iostream>

using namespace std;

void dfs_helper(vector<vector<int>>& adjList, vector<bool>& visited, int& i) {
  if(visited[i]) return;
  cout << i << endl;
  visited[i] = true;
  for (int j = 0; j < adjList[i].size(); j++) {
    dfs_helper(adjList, visited, adjList[i][j]);
  }
}

void dfs(vector<vector<int>>& adjList) {
  vector<bool> vis(adjList.size(), false);
  for(int i=0; i<adjList.size(); i++) {
    if (!vis[i]) {
      dfs_helper(adjList, vis, i);
    }
  }
}

int main() {
  vector<vector<int>> adjList;
  vector<int> zero, first, second, third, fourth, fifth;
  zero.push_back(1);
  zero.push_back(2);
  zero.push_back(3);
  first.push_back(0);
  second.push_back(0);
  second.push_back(3);
  second.push_back(4);
  third.push_back(0);
  third.push_back(2);
  fourth.push_back(2);
  adjList.push_back(zero);
  adjList.push_back(first);
  adjList.push_back(second);
  adjList.push_back(third);
  adjList.push_back(fourth);
  adjList.push_back(fifth);
  dfs(adjList);
}
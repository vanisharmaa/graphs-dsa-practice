#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_helper(vector<vector<int>>& adjList, vector<bool>& vis, int i) {
  queue<int> q;
  // mark start as visited and enqueue
  vis[i] = true;
  q.push(i);
  q.push(-1);
  while(!q.empty()) {
    int front = q.front();
    q.pop();
    if (front != -1) {
      // print the node (do not print the level marker)
      cout << front << endl;
      for(int it: adjList[front]) {
        if(!vis[it]) {
          vis[it] = true;
          q.push(it);
        }
      }
    } else {
      if (q.empty()) {
        break;
      }
      cout << "-----------" << endl;
      q.push(-1);
    }
  }
}

void bfs(vector<vector<int>>& adjList) {
  vector<bool> vis(adjList.size(), false);
  for(int i=0; i<adjList.size(); i++) {
    if(!vis[i]) {
      bfs_helper(adjList, vis, i);
      cout << "**************" << endl;
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
  bfs(adjList);
}
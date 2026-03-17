#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int parent[300001];
int sz[300001];
bool cycle[300001];

int find(int x) {
  int root = x;
  while(parent[root] != root) root = parent[root];
  while(parent[x] != root) {
    int next = parent[x];
    parent[x] = root;
    x = next;
  }
  return root;
}

int main() {
  int n, l;
  cin >> n >> l;

  for(int i = 0; i < 300001; i++) {
    parent[i] = i;
    sz[i] = 1;
    cycle[i] = false;
  }

  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    int ra = find(a);
    int rb = find(b);

    if(ra != rb) { // different components
      if(sz[ra] < sz[rb]) {
        swap(ra, rb);
      }
      parent[rb] = ra;
      sz[ra] += sz[rb];
      cycle[ra] = cycle[ra] || cycle[rb];
      cout << "LADICA" << endl;
    }
    else {
      if(!cycle[ra]) {
        cycle[ra] = true;
        cout << "LADICA" << endl;
      }
      else cout << "SMECE" << endl;
    }
  }

  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int parent[1000005];
int sz[1000005];

int find(int x) {
  if(parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);

  if(a != b) {
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}

int main() {
  int n, q;
  cin >> n >> q;

  for(int i = 1; i < 1000005; i++) {
    sz[i] = 1;
    parent[i] = i;
  }

  while (q-->0) {
    char cmd;
    cin >> cmd;
    int a, b;

    switch(cmd) {
      case 't':
        cin >> a >> b;
        unite(a, b);
        break;
      case 's':
        cin >> a;
        cout << sz[find(a)] << endl;
        break;
      default:
        cout << "something bad happened" << endl;
        break;
    }
  }
  return 0;
}

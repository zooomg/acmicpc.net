// 2934 LRH 식물

// 1 1 1
// 1 1 2 1 1 1
// 2 2 3 2 2 1
// 2 3 4 3 3 1

#include <cstdio>
#include <vector>
using namespace std;
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<int> &tree, int i, int diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> a(100005,0);
    vector<int> tree(100005,0);
    for (int i=1; i<=n; i++) {
        int l,r,s,t;
        scanf("%d %d",&l,&r);
        s = sum(tree,l);
        t = sum(tree,r);
        printf("%d\n",s+t);
        update(tree, l, -s); update(tree,l+1,s);
        update(tree, r, -t); update(tree,r+1,t);
        update(tree, l+1, 1);
        update(tree, r, -1);
    }
    return 0;
}

// http://kthng.tistory.com/39

// https://www.acmicpc.net/blog/view/9

// https://www.acmicpc.net/blog/view/21
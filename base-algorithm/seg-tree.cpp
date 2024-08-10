#include <bits/stdc++.h>

using namespace std;

int tree[400000];
int vet[400000];

void build(int node, int l, int r) {
    if (r == l) {
        tree[node] = vet[l];
        return;
    }

    int mid = (r+l) / 2;

    build(node*2+1, l, mid);
    build(node*2+2, mid+1, r);

    tree[node] = tree[node*2+1] + tree[node*2+2];
}

int querry (int node, int cl, int cr, int l,int r) {
    //if (l < cl || r > cr) return 0; //essa parte esta provavelmente errada
    //if (l >= cl && r <= cr) return tree[node]; // a mesma coisa

    int mid = (cr+cl)/2;
    return querry(node*2+1, cl, mid, l, r) + querry(node*2+2, mid, cr, l, r);
}

int main() {
    int n; cin >> n;

    for (int i=0; i<n; i++) {
        cin >> vet[i];
    }

    build(0, 0, n-1);

    for (int i=0; i<3; i++) {
        int a, b;
        cin >> a >> b;
        cout << querry(0, 0, n-1, a, b) << " ";
    }


    return 0;
}
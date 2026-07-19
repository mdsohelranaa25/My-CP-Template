vector<ll> v;

struct Node {
    ll val;
};

Node tr[N * 4];

Node mergee(Node a, Node b) {
    Node res;
    res.val = (a.val + b.val) % MOD;
    return res;
}

void init(int id, int b, int e) {
    if (b == e) {
        tr[id].val = v[b];
        return;
    }

    int mid = (b + e) / 2;
    init(id * 2, b, mid);
    init(id * 2 + 1, mid + 1, e);
    tr[id] = mergee(tr[id * 2], tr[id * 2 + 1]);
}

void update(int id, int b, int e, int idx, ll value) {
    if (b > idx || e < idx) return;

    if (b == e) {
        tr[id].val = value;
        return;
    }

    int mid = (b + e) / 2;
    update(id * 2, b, mid, idx, value);
    update(id * 2 + 1, mid + 1, e, idx, value);
    tr[id] = mergee(tr[id * 2], tr[id * 2 + 1]);
}

Node ask(int id, int b, int e, int l, int r) {
    if (b > r || e < l) {
        Node dummy;
        dummy.val = 0;
        return dummy;
    }

    if (b >= l && e <= r) return tr[id];

    int mid = (b + e) / 2;
    Node left = ask(id * 2, b, mid, l, r);
    Node right = ask(id * 2 + 1, mid + 1, e, l, r);
    return mergee(left, right);
}
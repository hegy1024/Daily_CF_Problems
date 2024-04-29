void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i ++ ) {
        int t;
        cin >> t;
        cnt[t] ++;
    }
    int s = INF;
    for (auto [u, v]: cnt) {
        s = min(s, v + 1);
    }
    for (; s >= 2; s -- ){
        bool flag = true;
        for (auto [u, v]: cnt) {
            if ((v % s) && (v % (s - 1) > v / (s - 1))) {
                flag = false;
                break;
            }
        }
        if (flag) break;
    }
    int ans = 0;
    for (auto [u, v]: cnt) {
        ans += (v + s - 1) / s;
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt --) {
        solve();
    }
    return 0;
}

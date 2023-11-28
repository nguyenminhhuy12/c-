#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TraCuuMaxTrongDoan {
private:
    vector<int> mang;  // Mang chua cac phan tu

public:
    TraCuuMaxTrongDoan(int n) {
        mang.resize(n, 0);  // Khoi tao mang voi n phan tu, gia tri ban dau la 0
    }

    void capNhatDoan(int u, int v, int k) {
        mang[u] += k;  // Tang gia tri cua phan tu u len k don vi
        if (v + 1 < mang.size()) {
            mang[v + 1] -= k;  // Giam gia tri cua phan tu v+1 di k don vi
        }
    }

    int timMaxTrongDoan(int n) {
        int max_value = mang[0];
        int current_value = mang[0];
        for (int i = 1; i < n; i++) {
            current_value += mang[i];
            max_value = max(max_value, current_value);
        }
        return max_value;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    TraCuuMaxTrongDoan tracuu(n);

    // Doc cac phep bien doi va cap nhat gia tri cua mang
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        tracuu.capNhatDoan(u - 1, v - 1, k);  // Chuyen tu 1-indexed sang 0-indexed
    }

    int p;
    cin >> p;

    // Doc va tra loi cac cau hoi
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        int max_value = tracuu.timMaxTrongDoan(v);  // Truy van gia tri lon nhat trong doan tu 0 den v
        cout << max_value << endl;
    }

    return 0;
}

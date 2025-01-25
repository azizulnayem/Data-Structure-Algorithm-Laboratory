#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

void optimal_bst(int n, vector<double>& p, vector<double>& q) {
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = numeric_limits<double>::max();
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "Cost = " << e[1][n] << endl;
    print_optimal_bst(root, 1, n, 0);
}

void print_optimal_bst(vector<vector<int>>& root, int i, int j, int level, vector<double>& keys) {
    if (i <= j) {
        int r = root[i][j];
        cout << setw(level) << "L:" << keys[r] << endl;
        print_optimal_bst(root, i, r - 1, level + 2, keys);
        print_optimal_bst(root, r + 1, j, level + 2, keys);
    } else {
        cout << setw(level) << "R:dummy" << endl;
    }
}


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<double> p(n + 1);
    vector<double> q(n + 2);

    for (int i = 1; i <= n; ++i) {
        double key, prob;
        cout << "Key " << i << ": ";
        cin >> key >> prob;
        p[i] = prob;
    }

    for (int i = 0; i <= n; ++i) {
        double low = (i == 0) ? 0 : p[i - 1];
        double high = (i == n) ? p[n] : p[i];
        cout << "D" << i << " (";
        if (i == 0) cout << "<";
        else if (i == n) cout << ">";
        else cout << low << "-" << high;
        cout << "): ";
        cin >> q[i];
    }

    optimal_bst(n, p, q);
    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int d, m, n;
    cin >> d >> m >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int dis = 0;
    int cur = 0;
    int stops = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] - cur > m) {
            if (i == 0) {
                cout << "Can't reach destination" << endl;
                return 0;
            }
            stops++;
            cout << "stop at gas station " << stops << " (" << a[i - 1] << " miles)" << endl;
            cur = a[i - 1];
        }

        if (a[i] >= d) {
            cout << "Reached destination" << endl;
            return 0;
        }
    }

    return 0;
}

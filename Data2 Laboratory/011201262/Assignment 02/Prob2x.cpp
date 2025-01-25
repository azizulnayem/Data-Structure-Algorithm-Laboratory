#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y, N, W, P1, P2;
        cin >> X >> Y >> N >> W >> P1 >> P2;

        double p1 = P1 / 100.0;
        double p2 = P2 / 100.0;

        double max_prob = 0.0;

        for (int hits_on_first = 0; hits_on_first <= N; ++hits_on_first) {
            int hits_on_second = N - hits_on_first;
            int total_score = X * hits_on_first + Y * hits_on_second;

            if (total_score >= W) {
                double prob = 1.0;

                for (int i = 0; i < hits_on_first; ++i) {
                    prob *= p1;
                }

                for (int i = 0; i < hits_on_second; ++i) {
                    prob *= p2;
                }

                max_prob = max(max_prob, prob);
            }
        }

        cout << fixed << setprecision(6) << max_prob * 100.0 << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        string S;
        cin >> S; // S[0] is vertex 1

        vector<vector<int>> graph(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
        }

        int total_steps = 2 * K;
        // dp[t][v]: result when at vertex v after t moves
        vector<vector<char>> dp(total_steps + 1, vector<char>(N));

        // Base: after 2K moves, game ends
        for (int v = 0; v < N; v++) {
            dp[total_steps][v] = S[v];
        }

        // Backward DP
        for (int t = total_steps - 1; t >= 0; t--) {
            bool is_alice_turn = (t % 2 == 0); // t=0: Alice's first move
            for (int v = 0; v < N; v++) {
                char target = is_alice_turn ? 'A' : 'B';
                bool can_win = false;
                for (int u : graph[v]) {
                    if (dp[t + 1][u] == target) {
                        can_win = true;
                        break;
                    }
                }
                dp[t][v] = can_win ? target : (target == 'A' ? 'B' : 'A');
            }
        }

        cout << (dp[0][0] == 'A' ? "Alice" : "Bob") << '\n';
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        ans += n / i;
    }
    cout << ans << endl;
    return 0;
}
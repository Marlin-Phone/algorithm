#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

// 解析所有分数项（自动处理符号）
vector<pair<ll, ll>> parse(const string& s) {
    vector<pair<ll, ll>> res;
    string cur = "";
    int start = 0;
    if (s[0] == '-') {
        cur = "-";
        start = 1;
    }

    for (int i = start; i <= (int)s.size(); i++) {
        if (i == s.size() || s[i] == '+' || s[i] == '-') {
            if (!cur.empty() && cur != "+" && cur != "-") {
                size_t pos = cur.find('/');
                ll num = stoll(cur.substr(0, pos));
                ll den = stoll(cur.substr(pos + 1));
                res.push_back({num, den});
            }
            if (i < s.size()) cur = s[i];
            else cur = "";
        } else if (i < s.size()) {
            cur += s[i];
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;

    auto fractions = parse(s);

    ll num = 0, den = 1; // 当前结果：num/den

    for (auto [a, b] : fractions) {
        // num/den + a/b = (num * b + a * den) / (den * b)
        ll new_num = num * b + a * den;
        ll new_den = den * b;

        // 约分
        ll g = gcd(new_num, new_den);
        if (g != 0) {
            new_num /= g;
            new_den /= g;
        }

        // 保证分母为正
        if (new_den < 0) {
            new_num = -new_num;
            new_den = -new_den;
        }

        num = new_num;
        den = new_den;
    }

    if (den == 1) {
        cout << num << endl;
    } else {
        cout << num << "/" << den << endl;
    }

    return 0;
}
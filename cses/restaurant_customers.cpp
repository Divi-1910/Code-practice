#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const ll longinf = 1e18;
const int intinf = 1e9;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)

#define debug_arr(arr, n)       \
    cout << #arr << " : ";      \
    for (int i = 0; i < n; i++) \
        cerr << arr[i] << " ";  \
    cerr << endl;

#define debug_mat(mat, rows, cols)     \
    cout << #mat << " :" << endl;      \
    for (int i = 0; i < rows; i++)     \
    {                                  \
        for (int j = 0; j < cols; j++) \
            cerr << mat[i][j] << " ";  \
        cerr << endl;                  \
    }

template <class T>
void printContainer(T begin, T end)
{
    cerr << "[ ";
    for (auto it = begin; it != end; ++it)
    {
        if (it != begin)
            cerr << ", ";
        cerr << *it;
    }
    cerr << " ]" << endl;
}

long long binpow(long long base, long long power, long long mod)
{
    long long result = 1;
    base %= mod;
    while (power > 0)
    {
        if (power & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?

Input
The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.

Output
Print one integer: the maximum number of customers.
*/

void solution()
{
    // start here
    ll n;
    cin >> n;
    vector<pair<int, int>> intervals;

    for (ll i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        intervals.push_back({l, +1});
        intervals.push_back({r, -1});
    }
    sort(intervals.begin(), intervals.end());
    ll count = 0;
    ll ans = 0;

    for (ll i = 0; i < intervals.size() - 1; i++)
    {
        count = count + (intervals[i].second);
        ans = max(ans, count);
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}

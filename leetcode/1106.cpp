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

void solution()
{
    // start here
    string str;
    cin >> str;

    stack<char> op;
    stack<bool> bt;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 't')
        {
            bt.push(true);
        }
        else if (str[i] == 'f')
        {
            bt.push(false);
        }
        else if (str[i] == '!' || str[i] == '&' || str[i] == '|')
        {
            op.push(str[i]);
        }
        else if (str[i] == '(')
        {
            continue;
        }
        else if (str[i] == ')')
        {
            char curr = op.top();
            op.pop();

            if (curr == '!')
            {
                bool val = bt.top();
                bt.pop();
                bt.push(!val);
            }
            else if (curr == '&')
            {
                bool result = true;
                while (!bt.empty() && str[i - 1] != '(')
                {
                    result = result && bt.top();
                    bt.pop();
                }
                bt.push(result);
            }
            else if (curr == '|' && str[i - 1] != '(')
            {
                bool result = false;
                while (!bt.empty())
                {
                    result = result || bt.top();
                    bt.pop();
                }
                bt.push(result);
            }
        }
    }

    bool ans = bt.top();
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}

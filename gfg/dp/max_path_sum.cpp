#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
using namespace std;
// #define cerr cout
namespace __DEBUG_UTIL__
{
    using namespace std;
    template <typename T>
    concept is_iterable = requires(T &&x) { begin(x); } &&
                          !is_same_v<remove_cvref_t<T>, string>;
    void print(const char *x) { cerr << x; }
    void print(char x) { cerr << "\'" << x << "\'"; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(string x) { cerr << "\"" << x << "\""; }
    void print(vector<bool> &&v)
    { /* Overloaded this because stl optimizes vector<bool> by using
         _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    template <typename T>
    void print(T &&x)
    {
        if constexpr (is_iterable<T>)
            if (size(x) && is_iterable<decltype(*(begin(x)))>)
            { /* Iterable inside Iterable */
                int f = 0;
                cerr << "\n~~~~~\n";
                for (auto &&i : x)
                {
                    cerr << setw(2) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~\n";
            }
            else
            { /* Normal Iterable */
                int f = 0;
                cerr << "{";
                for (auto &&i : x)
                    cerr << (f++ ? "," : ""), print(i);
                cerr << "}";
            }
        else if constexpr (requires { x.pop(); }) /* Stacks, Priority Queues, Queues */
        {
            auto temp = x;
            int f = 0;
            cerr << "{";
            if constexpr (requires { x.top(); })
                while (!temp.empty())
                    cerr << (f++ ? "," : ""), print(temp.top()), temp.pop();
            else
                while (!temp.empty())
                    cerr << (f++ ? "," : ""), print(temp.front()), temp.pop();
            cerr << "}";
        }
        else if constexpr (requires { x.first; x.second; }) /* Pair */
        {
            cerr << '(', print(x.first), cerr << ',', print(x.second), cerr << ')';
        }
        else if constexpr (requires { get<0>(x); }) /* Tuple */
        {
            int f = 0;
            cerr << '(', apply([&f](auto... args)
                               { ((cerr << (f++ ? "," : ""), print(args)), ...); },
                               x);
            cerr << ')';
        }
        else
            cerr << x;
    }
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if constexpr (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t i = 0;
        for (; names[i] and names[i] != ','; i++)
            cerr << names[i];
        for (i++; names[i] and names[i] != ','; i++)
            ;
        cerr << " = {";
        for (size_t ind = 0; ind < N; ind++)
            cerr << (ind ? "," : ""), print(arr[ind]);
        cerr << "}";
        if constexpr (sizeof...(tail))
            cerr << " ||", printerArr(names + i + 1, tail...);
        else
            cerr << "]\n";
    }

}
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
#endif

int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    int n = mat.size();
    if (i < 0 or j < 0 or i >= n or j >= n)
    {
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ld = f(i + 1, j - 1, mat,dp) + mat[i][j];
    int d = f(i + 1, j, mat,dp) + mat[i][j];
    int rd = f(i + 1, j + 1, mat,dp) + mat[i][j];

    debug(ld, d, rd);
    return dp[i][j]=max(ld, max(d, rd));
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N, 0));

    for (auto i = 0; i < N; i++)
    {
        for (auto j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }

    // vector<vector<int>> dp(N+1,vector<int> (N,-1));
    // int ans = 0;
    // for (auto j = 0; j < v.size(); j++)
    // {
    //     ans = max(ans, f(0, j, v,dp));
    //     debug(ans);
    // }
    // cout << ans;
    int ans = 0;
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (auto j = 0; j < N;j++){
        dp[0][j] = v[0][j];
    }

    for (auto i = 1; i < N;i++){
        for (auto j = 0; j < N;j++){
            if(j==0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + v[i][j];
            }else if(j==N-1){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1])) + v[i][j];
            }
        }
    }

    for (auto j = 0; j < N;j++){
        ans = max(ans, dp[N - 1][j]);
    }

        debug(ans);
    return 0;
}
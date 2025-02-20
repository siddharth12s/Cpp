#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
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

int knapsack(int n,std::vector<int> &price, std::vector<int> &pages, int i, int target, std::vector<std::vector<int>> &dp){

    if(i==0){
        if(price[i]<=target){
            return pages[i];
        }

        return -1e9;
    }

    if(dp[i][target]!=-1)
        return dp[i][target];

    int notpick = knapsack(n, price, pages, i - 1, target, dp);
    int pick = -1e9;
    if(price[i]<=target){
        pick = pages[i] + knapsack(n, price, pages, i - 1, target - price[i], dp);
    }

    return dp[i][target]=std::ranges::max(pick, notpick);
}
int main(){

    int n, target_price;
    std::cin >> n >> target_price;

    std::vector<int> price(n), pages(n);
    std::vector<std::vector<int>> dp(n, std::vector<int>(target_price + 1, 0));

    for (auto i = 0; i < n;i++){
        std::cin >> price[i];
    }

    for (auto i = 0; i < n;i++){
        std::cin >> pages[i];
    }

    // int ans = knapsack(n, price, pages, n - 1, target_price, dp);
    int ans;

    for (auto i = price[0]; i <= target_price;i++){
        dp[0][i] = pages[0];
    }

    for (auto i = 1; i < n;i++){
        for (auto j = 0; j <= target_price;j++){
            int notpick = dp[i - 1][j];
            int pick = -1e9;
            if(price[i]<=j){
                pick = pages[i] + dp[i-1][j - price[i]];
            }

            dp[i][j] = std::ranges::max(pick, notpick);
        }
    }

    ans = dp[n - 1][target_price];
    if (ans == -1e9)
        ans = 0;
    std::cout << ans;

    return 0;
}
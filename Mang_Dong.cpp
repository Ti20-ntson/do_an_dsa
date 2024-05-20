/// Author : Nguyễn Thái Sơn - K18 - KHMT - UIT
/// Training ICPC 2024

#include<bits/stdc++.h>

/// #pragma GCC optimize("O3,unroll-loops")
/// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fi first
#define se second
#define TASK "test"
#define pb push_back
#define EL cout << endl
#define Ti20_ntson int main()
#define in(x) cout << x << endl
#define all(x) (x).begin(),(x).end()
#define getbit(x, i) (((x) >> (i)) & 1)
#define cntbit(x) __builtin_popcount(x)
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FORD(i,l,r) for (int i = l; i >= r; i--)
#define Debug(a,n) for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> vii;
typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

const int N = 5e5 + 5;
const int oo = INT_MAX;
const int mod = 1e9 + 7;
const int d4x[4] = {-1, 0, 1, 0} , d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

/// Tạo một struct TrieNode như sau:

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    TrieNode() {
        for (int i=0; i<26; ++i)
            child[i]=NULL;
        cnt=0;
    }
}*root;

/// Hàm thêm một xâu vào Trie:
/// Cách hoạt động tương tự như thêm một xâu ở mảng tĩnh
/// Do đó sẽ không có phần giải thích chi tiết ở các phần này

void TrieInsert(const string &s)
{
    int n=s.length();
    TrieNode* p=root;
    for (int i=0; i<n; ++i) {
        int nxt=s[i]-'a';
        if (p->child[nxt]==NULL)
            p->child[nxt]=new TrieNode();
        p=p->child[nxt];
    }
    ++p->cnt;
}

/// Hàm kiểm tra xem xâu s có trong Trie hay không:
/// Cách hoạt động tương tự như thêm một xâu ở mảng tĩnh
/// Do đó sẽ không có phần giải thích chi tiết ở các phần này

bool TrieFind(const string &s)
{
    int n=s.length();
    TrieNode* p=root;
    for (int i=0; i<n; ++i) {
        int nxt=s[i]-'a';
        if (p->child[nxt]==NULL)
            return false;
        p=p->child[nxt];
    }
    return p->cnt>0;
}


inline void Solve() {
    int Q; cin >> Q;
    /// Đọc vào số truy vấn mà mình muốn
    /// Mỗi câu hỏi sẽ có format như sau
    /// 1 xâu s : nếu muốn thêm xâu s vào tập hợp, ví dụ 1 abc
    /// 2 xâu s : nếu muốn kiểm tra xâu s có tồn tại trong tập hợp không ?
    /// Hàm bool nên true là 1 và false là 0.
    root = new TrieNode();
    FOR(i, 1, Q) {
        int type;
        string s;
        cin >> type >> s;
        /// Đọc vào từng truy vấn
        /// giờ ta cần biết sẽ là truy vấn thêm - truy vấn 1
        /// hay là truy vấn tìm kiếm - truy vấn 2

        if (type == 1) {
            /// Bây giờ đã xác định được là thêm xâu s vào tập hợp
            /// Sử dụng hàm TrieInsert
            TrieInsert(s);
        }

        else if (type == 2) {
             /// Bây giờ đã xác định được là kiểm tra xấu s có trong tập hợp không ?
            /// Sử dụng hàm TrieFind
            /// Sẽ in ra màn hình là có hay không tồn tại xâu s

            if (TrieFind(s) == true) {
                cout << "Co Ton Tai xau " << s << endl;
            }
            else cout << "Khong ton tai xau " << s << endl;

        }

    }
}

Ti20_ntson {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) {
        Solve();
    }
}



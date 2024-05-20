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

const int Trie_sz = 1e6;

/// Khai báo mảng tĩnh Trie với Trie_sz là số nút tối đa có thể tạo ra
/// 28 thể hiện cho 26 chữ cái a -> z. Thể hiện các cạnh nối
/// biến cnt thể hiện số nút đã được tạo ra từ input.

/// Mảng End[i] sẽ thể hiện xem có bao nhiêu xâu kết thúc tại nút i
/// Với độ dài của mảng là Trie_sz

int Trie[Trie_sz][28], cnt = 0, End[Trie_sz];

/// Hàm Add_Trie thể hiện cho việc thực hiện thêm xâu s vào Trie

void Add_Trie(string s) {
    /// Khai báo biến root = 0
    /// Từ biến root tức là gốc, ta sẽ lần lượt di chuyển đi các
    /// nút khác trên cây Trie
    int root = 0;

    for (char c : s) {
        /// Ta lần lượt di chuyển theo từng chữ cái của xâu s
        /// Trong case mà chưa có đường đi
        /// Ta buộc lòng thêm đỉnh mới, do đó cnt tăng lên 1
        /// Ta gán đỉnh mới đó là ++cnt sẽ thực hiện được cả 2 thao tác
        if (Trie[root][c - 'a'] == 0)
            Trie[root][c - 'a'] = ++cnt;

        root = Trie[root][c - 'a'];
    }

    /// Thực hiện đếm xem có bao nhiêu xâu s kết thúc tại đây.
    End[root]++;

}

/// Hàm tìm kiếm xâu s có tồn tại trong tập hơp ko

bool Find(string s) {
    int root = 0;
    /// Khai báo biến root = 0
    /// Từ biến root tức là gốc, ta sẽ lần lượt di chuyển đi các
    /// nút khác trên cây Trie

    for (char c : s) {
        /// Ta lần lượt di chuyển theo từng chữ cái của xâu s
        root = Trie[root][c - 'a'];

        /// Nếu ko thể di chuyển tức là root = 0.
        /// Ngay lập tức return false do xấu s ko tồn tại trong tập hợp

        if (root == 0) return false;

    }

    if (End[root]) return true;
}


inline void Solve() {
    int Q; cin >> Q;
    /// Đọc vào số truy vấn mà mình muốn
    /// Mỗi câu hỏi sẽ có format như sau
    /// 1 xâu s : nếu muốn thêm xâu s vào tập hợp, ví dụ 1 abc
    /// 2 xâu s : nếu muốn kiểm tra xâu s có tồn tại trong tập hợp không ?
    /// Hàm bool nên true là 1 và false là 0.

    FOR(i, 1, Q) {
        int type;
        string s;
        cin >> type >> s;
        /// Đọc vào từng truy vấn
        /// giờ ta cần biết sẽ là truy vấn thêm - truy vấn 1
        /// hay là truy vấn tìm kiếm - truy vấn 2

        if (type == 1) {
            /// Bây giờ đã xác định được là thêm xâu s vào tập hợp
            /// Sử dụng hàm Add_Trie
            Add_Trie(s);
        }

        else if (type == 2) {
             /// Bây giờ đã xác định được là kiểm tra xấu s có trong tập hợp không ?
            /// Sử dụng hàm Find
            /// Sẽ in ra màn hình là có hay không tồn tại xâu s

            if (Find(s) == true) {
                cout << "Co Ton Tai xau " << s << endl;
            }
            else cout << "Khong ton tai xau " << s << endl;

        }

    }
}

Ti20_ntson {
//    freopen(TASK".INP","r",stdin);
//    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ){
//        Read_Input();
        Solve();
    }
}



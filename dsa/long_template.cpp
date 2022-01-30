
//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
/*--------------------------------------------------------------------------------------------*/

using ll = long long;
using ld = long double; // or double, if TL is tight
using pii = pair<int,int>;
using pld = pair<ld,ld>;
using vpi = vector<pii>;
using vpld = vector<pld>;

template<class T> using V = vector<T>; 
template<class T, size_t SZ> using AR = array<T,SZ>; 
template<class T> using PR = pair<T,T>;

#define LOGOUTT
#define eb emplace_back
#define pb push_back
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pii pair<int,int>
#define pf push_front
#define sz(x) int((x).size())
#define rsz resize
#define bg(v) begin(v)
#define rall(v) v.rbegin(), v.rend() 

//LOOPS
#define fl(i,a,b) for (int i = (a); i < (b); ++i)
#define f0l(i,a) fl(i,0,a)
#define flex(i,a,b,c) for (int i = (a); i < (b); i += c)
#define lf(i,a,b) for (int i = (a)-1; i >= (b); --i)
#define xelf(i,a,b,c) for (int i = (a); i >= (b); i -= c)
#define l0f(i,a) lf(i,a,0)
#define rep(a) f0l(_,a)
#define each(a,x) for (auto& a: x)
#define cases ll t;cin>>t;fl(i,0,t)


const int MOD = 1e9+7; // 998244353;
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const int64_t INF = 1e18;
/*-------------------------------------------------DATA STRUCTURE------------------------------*/

template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

/*--------------------------------------------------------------------------------------------*/

// INPUT
template<class T> istream& operator >> (istream &is, vector<T>& V) { for(auto &e : V) is >> e; return is; }
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){ in>>a.F>>a.S;return in; }
template<class T> void re(complex<T>& c);
template<class T, class U> void re(pair<T,U>& p);
template<class T> void re(V<T>& v);
template<class T, size_t SZ> void re(AR<T,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(double& d) { string t; re(t); d = stod(t); }
void re(long double& d) { string t; re(t); d = stold(t); }
template<class T, class ...U> void re(T& t, U&... u) { re(t); re(u...); }

template<class T> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
template<class T, class U> void re(pair<T,U>& p) { re(p.F,p.S); }
template<class T> void re(V<T>& x) { for (auto& a: x) re(a); }
template<class T, size_t SZ> void re(AR<T,SZ>& x) { for (auto& a: x) re(a); }
template<class T> void rv(int n, V<T>& x) { x.rsz(n); re(x); }


// TO_STRING
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
string ts(bool b) { 
    #ifdef LOGOUTT
    return b ? "true" : "false"; 
    #else 
    return ts((int)b);
    #endif
}
template<class T> string ts(complex<T> c) { 
    stringstream ss; ss << c; return ss.str(); }
string ts(V<bool> v) {
    string res = "{"; f0l(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
    string res = ""; f0l(i,SZ) res += char('0'+b[i]);
    return res; }
template<class T, class U> string ts(pair<T,U> p);
template<class T> string ts(T v) { // containers with begin(), end()
    #ifdef LOGOUTT
        bool fst = 1; string res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; string res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += ts(x);
        }
        return res;
    #endif
}
template<class T, class U> string ts(pair<T,U> p) {
    #ifdef LOGOUTT
        return "("+ts(p.F)+", "+ts(p.S)+")"; 
    #else
        return ts(p.F)+" "+ts(p.S);
    #endif
}

// OUTPUT
template<class T> void pr(T x) { cout << ts(x); }
template<class T, class ...U> void pr(const T& t, const U&... u) { 
    pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
template<class T, class ...U> void ps(const T& t, const U&... u) { 
    pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.F<<" "<<a.S;return out;}
template<typename T_vector> void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class T, class ...U> void DBG(const T& t, const U&... u) {
    cerr << ts(t); if (sizeof...(u)) cerr << ", ";
    DBG(u...); } 
#ifdef LOGOUTT // compile with -DLOGOUTT, chk -> fake assert
    #define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "] = [", DBG(__VA_ARGS__)
    #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
         << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
    #define debug(...) 0
    #define chk(...) 0
#endif

#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);

/*------------------------------------------FUNCTIONS-----------------------------------------------------------*/



mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
ll lcm(ll a,ll b){
    ll x=a*b;
    return (x/__gcd(a,b));}
ll logint(ll a,ll b){
    ll i=0;
    ll k=1;
    while(a>=k)
    {
        i++;
        k*=b;
    }
    return i-1;}
ll fast_pow(ll x,ll y,ll m){
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;}

/*--------------------------------------------------Globals-----------------------------------------------------*/

const ll N=2e5+5,M=1e4;
ll tc,n,k,m;

/*--------------------------------------------------------------------------------------------------------------*/



void LogOutt()
{
    
}



void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setErr(string s) { freopen(s.c_str(),"w",stderr); }

int main(){
    setErr("errorrr.txt");
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    tc=1;
    cases
    {
        LogOutt();
        tc++;
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<<endl;    
}


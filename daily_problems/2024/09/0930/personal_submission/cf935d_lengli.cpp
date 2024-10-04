/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  bool operator<(const ModInt &a) const { return (x < a.x); }
  bool operator>(const ModInt &a) const { return (x > a.x); }
  bool operator<=(const ModInt &a) const { return (x <= a.x); }
  bool operator>=(const ModInt &a) const { return (x >= a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
  friend std::istream &operator>>(std::istream &is, ModInt &a) {int v;is >> v;a = ModInt(v);return is;}
};
constexpr unsigned MO = 1000000007;
using Mint = ModInt<MO>;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2),b(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>b[i];

    Mint fm=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0) fm*=m;
        if(b[i]==0) fm*=m;
    }
    std::vector<std::vector<Mint>> f(n+2,std::vector<Mint> (2,0));
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0 and b[i]==0){
            f[i][0]=f[i-1][0]*m;
            f[i][1]=Mint(m-1)*Mint(m)/Mint(2)*f[i-1][0]+f[i-1][1]*Mint(m)*Mint(m);
        }else if(a[i]==0){
            f[i][0]=f[i-1][0];
            f[i][1]=f[i-1][0]*(m-b[i])+f[i-1][1]*m;
        }else if(b[i]==0){
            f[i][0]=f[i-1][0];
            f[i][1]=f[i-1][0]*(a[i]-1)+f[i-1][1]*m;
        }else{
            if(a[i]==b[i]) f[i][0]=f[i-1][0],f[i][1]=f[i-1][1];
            else if(a[i]>b[i]) f[i][1]=f[i-1][1]+f[i-1][0],f[i][0]=0;
            else f[i][0]=0,f[i][1]=f[i-1][1];
        }
    }
    std::cout<<f[n][1]/fm<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
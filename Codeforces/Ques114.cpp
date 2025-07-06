// #include<bits/stdc++.h>
// using namespace std;


// void solve(){
    
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     long long t; cin>>t;
//     while(t--) solve();
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <numeric>

// using namespace std;

// #define endl "\n"
// typedef long long ll;

// const int MOD = 1e9 + 7;
// const int MAX_VAL = 100005;

// ll fact[MAX_VAL];
// ll invFact[MAX_VAL];

// ll power(ll base, ll exp) {
//     ll res = 1;
//     base %= MOD;
//     while (exp > 0) {
//         if (exp % 2 == 1) res = (res * base) % MOD;
//         base = (base * base) % MOD;
//         exp /= 2;
//     }
//     return res;
// }

// ll modInverse(ll n) {
//     return power(n, MOD - 2);
// }

// void precompute_factorials() {
//     fact[0] = 1;
//     for (int i = 1; i < MAX_VAL; i++) {
//         fact[i] = (fact[i - 1] * i) % MOD;
//     }
//     invFact[MAX_VAL - 1] = modInverse(fact[MAX_VAL - 1]);
//     for (int i = MAX_VAL - 2; i >= 0; i--) {
//         invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
//     }
// }

// ll nCr_mod_p(ll n_val, int r) {
//     if (r < 0) return 0;
//     if (r == 0) return 1;

//     ll n_mod = n_val % MOD;

//     ll numerator = 1;
//     for (int i = 0; i < r; ++i) {
//         numerator = (numerator * ((n_mod - i + MOD) % MOD)) % MOD;
//     }
//     return (numerator * invFact[r]) % MOD;
// }

// void solve() {
//     ll a, b, k;
//     cin >> a >> b >> k;

//     ll n_val = (a - 1) * k + 1;

//     ll n_ans = n_val % MOD;

//     ll C_mod = nCr_mod_p(n_val, a);

//     ll m_term = ((b - 1) * k) % MOD;
//     ll m_ans = (m_term * C_mod + 1) % MOD;

//     cout << n_ans << " " << m_ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     precompute_factorials();

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// typedef long long L;

// const int MODV = 1000000007;

// // quick power but messy naming and style
// L pw(L b, L e) {
//  L res = 1;
//  b %= MODV;
//  while (e > 0) {
//    if (e & 1) 
//        res = (res * b) % MODV;
//      b = (b * b) % MODV;
//      e >>= 1;
//  }
//  return res;
// }

// // mod inverse by pow but we call pw with weird name
// L invm(L x) {
// return pw(x, MODV - 2);
// }

// // compute nCr mod but inefficent: compute numerator each time and denominator each time
// L comb_mod(L n, int r) {
//     if (r < 0) return 0;
//     if (r == 0) return 1;
//     // n might be large; take mod for intermediate but still loop up to r
//     L nm = n % MODV;
//     L num = 1;
//     for (int i = 0; i < r; i++) {
//         // ensure positive
//         L term = (nm - i);
//         if (term < 0) term += MODV;
//         num = (num * term) % MODV;
//     }
//     // compute denom = r! mod and invert
//     L denom = 1;
//     for (int i = 1; i <= r; i++) {
//         denom = (denom * i) % MODV;
//     }
//     L invd = invm(denom);
//     return (num * invd) % MODV;
// }

// // weird solve function with odd indentation and naming
// void goSolve() {
//     L a,b,k;
//     if (!(cin>>a>>b>>k)) return;
//     // compute n_val = (a-1)*k+1 but do step by step
//     L t1 = a - 1;
//     L t2 = t1 * k;
//     L n_val = t2 + 1;
//     // modded n for printing
//     L out_n = n_val % MODV;
    
//     // compute C(n_val, a) mod
//     L C = comb_mod(n_val, (int)a);
    
//     // compute m_ans: ((b-1)*k)*C +1 mod
//     L t3 = b - 1;
//     L t4 = t3 * k;
//     L mterm = t4 % MODV;
//     L mout = ( (mterm * C) % MODV + 1 ) % MODV;
    
//     // print both; odd formatting
//       cout<< out_n<<" "<< mout << "\n";
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int T;
//     if(!(cin>>T)) return 0;
//     while(T--){
//       goSolve();
//     }
//     return 0;
// }

    #include <bits/stdc++.h>
    using namespace std;

    #define M 1000000007

    long long recPow(long long b, long long e) {
        if (e <= 0) return 1;
        if (e & 1) return (b % M * recPow((b % M * b % M) % M, e / 2)) % M;
        return recPow((b % M * b % M) % M, e / 2);
    }

    long long invMod(long long x) {
        return recPow(x, M - 2);
    }

    long long combCalc(long long N, int R) {
        if (R < 0) return 0;
        if (R == 0) return 1;
        long long nmod = N % M;
        long long num = 1;
        int i = 0;
        while (i < R) {
            long long t = nmod - i;
            if (t < 0) t += M;
            num = (num * t) % M;
            if (++i == R) break;
        }
        long long den = 1;
        for (int j = 1; j <= R; ++j) {
            den = (den * j) % M;
        }
        long long invd = invMod(den);
        return (num * invd) % M;
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        if (!(cin >> T)) return 0;
        while (T-- > 0) {
            long long a, b, k;
            if (!(cin >> a >> b >> k)) break;
            long long t1 = a - 1;
            long long t2 = t1 * k;
            long long nval = t2 + 1;
            long long out1 = nval % M;
            int rr = int(a);
            long long C = combCalc(nval, rr);
            long long u1 = b - 1;
            long long u2 = u1 * k;
            long long part = u2 % M;
            long long out2 = (part * C) % M;
            out2 = (out2 + 1) % M;
            cout << out1 << " " << out2 << "\n";
        }
        return 0;
    }

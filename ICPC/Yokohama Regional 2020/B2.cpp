#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int n, m;
    cin >> n>> m;

    int N = n + m;

    vector<int> a(n+1), b(m+1);

    // need[x] : 1~x 中有多少个数属于 A
    // type[x] : 1 -> x属于A
    //           2 -> x属于B
    vector<int>need(N + 1, -1);
    vector<int>type(N + 1, 0);

    for(int i = 1;i <= n; i++){
        cin >> a[i];
        if(a[i]){
            need[a[i]] = i;
            type[a[i]] = 1;
        }
    }

    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(b[i]){
            need[b[i]]=b[i]-i;
            type[b[i]]=2;
        }
    }

    need[0]=0;

    // 最终 1~N 中一定有 n 个属于 A
    need[N] = n;

    vector<int>belong(N + 1,0);
    // belong[x] = 1 表示 x 属于 A
    // 否则属于 B

    int last=0;

    for(int x = 1; x <= N; x++) {
        if(need[x] == -1) continue;
        int cnt = need[x] - need[last];
        if(type[x] == 1) {
            cnt--;
            belong[x] = 1;
        }
        int r = x;
        if(type[x]) r = x - 1;
        for(int i = last + 1; i <= r && cnt; i++) {
            belong[i] = 1;
            cnt--;
        }
        last = x;
    }
    vector<int>ansA,ansB;

    for(int x=1;x<=N;x++){
        if(belong[x]){
            ansA.push_back(x);
        }
        else{
            ansB.push_back(x);
        }
    }

    for(auto x:ansA){
        cout<<x<<" ";
    }
    cout<<"\n";

    for(auto x:ansB){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}
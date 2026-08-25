#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>a(n+1),ap;
    vector<int>b(n+1),bp;
    a[0] = b[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0){
            ap.push_back(a[i]);
        }
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(b[i]!=0){
            bp.push_back(b[i]);
        }
    }
    ap.push_back(INT_MAX);
    bp.push_back(INT_MAX);
    int idxa=1,idxpa=0,idxb=1,idxpb=0;
    //is filling  -- tail  
    int now = 1;
    while(now != m+n+1){
        //cout<<"now is"<<now<<"\n";///////////////////////
        if((idxb==m+1) || (b[idxb]&&b[idxb]!=now)||(idxa<=n && ap[idxpa] <= bp[idxpb] && now >= a[idxa-1] && now <= ap[idxpa] &&  (a[idxa]==0 || (a[idxa]!=0 && a[idxa]==now)))){
            //cout<<"to a.";///////////////////////
            if(a[idxa]==now){
                idxpa++;
                //cout<<"up";////////////////////////
            }
            a[idxa] = now;
            idxa++;
            now++;
            //cout<<"\n\n";/////////////////////////////
        }else{
            //cout<<"to b.";///////////////////////
            if(b[idxb]==now){
                idxpb++;
                //cout<<"up";////////////////////////
            }
            b[idxb] = now;
            idxb++;
            now++;
            //cout<<"\n\n";/////////////////////////////////////////
        }
    }

    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int j=1;j<=m;j++){
        cout<<b[j]<<" ";
    }
    cout<<"\n";
    return 0;
}

/*


6 7
0 5 0 0 0 0
0 0 3 0 8 0 12


*/

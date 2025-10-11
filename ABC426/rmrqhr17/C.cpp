#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int sege(int l,int r,vector<int>& v) {
    int sum=0;
    while (l<=r) {
        if (l%2==1) {
            sum+=v[l];
            l++;
        }
        if(r%2==0) {
            sum+=v[r];
            r--;
        }
        l/=2;
        r/=2;
    }
    return sum;
}
int segfix0(int l,int r,vector<int>& v,int y) {
    while (l>0) {
        v[l]+=y;
        l/=2;
    }
    return 0;
}
int main() {
    int ff=1048576;
    int n,q;
    cin>>n>>q;
    vector<int> v(2097152);
    int checked=0;
    for(int i=1;i<=n;i++) {
        int g=i+ff;
        while (g>0) {
            v[g]++;
            g/=2;
        }
    }
    for(int i=0;i<q;i++) {
        int x,y;
        cin>>x>>y;
        int u=sege(checked+ff+1,x+ff,v);
        if (x<=checked) {
            cout<<0<<endl;
        }
        else {

            cout<<u<<endl;
            segfix0(y+ff,n+ff,v,u);
            checked=x;
        }

    }
}
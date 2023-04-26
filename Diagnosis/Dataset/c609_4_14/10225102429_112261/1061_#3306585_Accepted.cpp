#include <iostream>
#include <vector>
const int N = 1001;
int main(){
    using namespace std;
    int n; cin>>n;
    vector<bool> makeP(N,true);
    vector<int> Prime{};
    vector<long long> ans(n+1,0);
    for(int i = 2; i<N; i++){
        if(makeP[i]){
            Prime.push_back(i);
            for(int k = i*i; k<N; k+=i) makeP[k] = false;
        }
    }
    ans[0] = 1;
    int num = Prime.size();
    for(int i = 0; i<num&&Prime[i]<=n; i++){
        for(int j = Prime[i]; j<=n; j++){
            ans[j] += ans[j-Prime[i]];
        }
    }
    cout<<ans[n];
    return 0;
}

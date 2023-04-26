
#include<algorithm>
using namespace std;

typedef struct Num{
    long long n;
    int cntO;
}Num;

bool cmp(Num A, Num B){
    if(A.cntO != B.cntO) return A.cntO > B.cntO;
    else return A.n < B.n;
}

int count_One(long long number){
    int cnt = 0;
    long long test = 1;
    for(int i = 0; i < 64; i++){
        if(number & test)
            cnt++;
        test <<= 1;
    }
    return cnt;
}

int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int N; cin>>N;
        Num nums[10001];
        for(int j = 0; j < N; j++){
            cin>>nums[j].n;
            long long tmp = nums[j].n;
            nums[j].cntO = count_One(nums[j].n);
        }
        sort(nums, nums+N, cmp);
        cout<<"case #"<<i<<':'<<endl;
        for(int j = 0; j < N; j++)
            cout<<nums[j].n<<' ';
        cout<<endl;
    }
    return 0;
}

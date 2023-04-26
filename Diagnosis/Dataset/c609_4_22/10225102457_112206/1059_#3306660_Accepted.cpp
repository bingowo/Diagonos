#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct NUM{
    bool sgn;
    string i;
    string fl;
    string num;
};

bool Cri(const NUM a, const NUM b)
    {
        if(a.sgn != b.sgn) return a.sgn;
        else if(a.sgn == false){
            if(a.i.length() != b.i.length()) return a.i.length() < b.i.length();
            else if(a.i != b.i) return a.i < b.i;
            else return a.fl < b.fl;
        }
        else{
            if(a.i.length() != b.i.length()) return a.i.length() > b.i.length();
            else if(a.i != b.i) return a.i > b.i;
            else return a.fl > b.fl;
        }
    }

int main(void){
    vector<NUM> in;
    NUM te;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> te.num;

        if(te.num[0] == '-' || te.num[0] == '+'){
            if(te.num[0] == '-') te.sgn = true;
            else te.sgn = false;

            int flt = te.num.find('.');
            if(flt == string::npos){
                te.fl = "0";
                te.i = te.num.substr(1);
            }
            else{
                te.fl = te.num.substr(flt+1);
                te.i = te.num.substr(1,flt-1);
            }
        }
        else{
            te.sgn = false;
            int flt = te.num.find('.');
            if(flt == string::npos){
                te.fl = "0";
                te.i = te.num;
            }
            else{
                te.fl = te.num.substr(flt+1);
                te.i = te.num.substr(0,flt);
            }
        }

        in.insert(in.end(),te);
    }

    sort(in.begin(),in.end(),Cri);

    for(auto e:in){
        cout << e.num << endl;
    }
    return 0;
}
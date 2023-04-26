#include<iostream>
#include<string>

using namespace std;
struct NUM{
    bool sgn;
    int num[102];
    int i1;
    int i2;
};

int trans(NUM& a){
    int re = 0;
    if(a.num[a.i2]&1){
        if(!a.sgn) a.num[a.i2]--;
        else{
            int i = a.i2;
            a.num[i]++;
            for(;i >= a.i1;i--){
                if(a.num[i] >= 9){
                    a.num[i] = 0;
                    a.num[i-1]++;
                }
                else break;
            }
            if(i < a.i1){
                a.i1--;
            }
        }
        re = 1;
    }

    a.sgn = !a.sgn;
    int pl = 0;
    for(int i = a.i1; i <= a.i2; i++){
        int te = a.num[i]&1;
        a.num[i] = (pl*10 + a.num[i]) / 2;
        pl = te;
    }
    while(!a.num[a.i1]) a.i1++;

    return re;
}

int main(void)
{
    NUM dat;
    dat.sgn = false;
    string in,out;
    cin >> in;
    if(in[0] == '+' || in[0] == '-'){
        if(in[0] == '-') dat.sgn = true;
        in = in.substr(1);
    }
    dat.i1 = dat.i2 = 1;
    dat.num[0] = 0;
    for(auto e:in){
        dat.num[dat.i2] = e-'0';
        dat.i2++;
    }
    dat.i2--;

    if(dat.num[dat.i1] == 0 && dat.i2 == 1){
        cout << "0" << endl;
        return 0;
    }
    else{
        for(;dat.num[dat.i1]==0;dat.i1++);

        while(dat.i2>=dat.i1){
            out.insert(out.begin(),trans(dat)+'0');
        }
        cout << out << endl;
    }
    return 0;
}
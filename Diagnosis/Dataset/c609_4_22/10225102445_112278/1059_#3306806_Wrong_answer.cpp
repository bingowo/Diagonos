#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    string c,d,f,g;
    if (a[0] == '-' && b[0] != '-') return true;  // a 为负数，b 为正数
    else if (a[0] != '-' && b[0] == '-') return false; // a 为正数，b 为负数
   else if (a[0] == '-' && b[0] == '-')
    {     size_t a_dot_pos = a.find('.'), b_dot_pos = b.find('.');    // a 为负数，b 为负数
    if(a_dot_pos==string::npos){a_dot_pos=a.size();c=a.substr(1,a_dot_pos-1);f="";}
    else{c=a.substr(1,a_dot_pos);f=a.substr(a_dot_pos+1,a.size()-a_dot_pos-1);}

    if(b_dot_pos==string::npos){b_dot_pos=b.size();d=b.substr(1,b_dot_pos-1);g="";}
    else{d=b.substr(1,b_dot_pos);g=b.substr(b_dot_pos+1,b.size()-b_dot_pos-1);}


    if(a_dot_pos!=b_dot_pos) return a_dot_pos>b_dot_pos;

    else
    {
    if(c!=d){return  c>d ; }
    else return f>g;
     }
/*
2
-5861.8067
-49215


*/

    }
    else
    { size_t A=a.find('+'),B=b.find('+');
      size_t a_dot_pos = a.find('.'), b_dot_pos = b.find('.');
      if(A==string::npos)A=-1;
      if(B==string::npos) B=-1;
    if(a_dot_pos==string::npos){a_dot_pos=a.size();c=a.substr(A+1,a_dot_pos-A-1);f="";}
    else{c=a.substr(A+1,a_dot_pos-A+1);f=a.substr(a_dot_pos+1,a.size()-a_dot_pos-1);}

    if(b_dot_pos==string::npos){b_dot_pos=b.size()-1;d=b.substr(B+1,b_dot_pos-B-1);g="";}
    else{d=b.substr(B+1,b_dot_pos-B+1);g=b.substr(b_dot_pos+1,b.size()-b_dot_pos-1);}


    if(a_dot_pos-A!=b_dot_pos-B) return a_dot_pos-A<b_dot_pos-B;

    else
    {
    if(c!=d){return  c<d ; }
    else return f<g;
     }


    }



}

int main() {

    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const int a,const int b)
{
    return a>b;
}
int main() {
    int sign =1;
    char m;
    cin >>m;
    if(m =='D'){
        sign =0;
    }
    int a[100],b[100];
    int i=0;
    while(cin >> a[i]){
        i++;
    }
    if(sign){
        sort(a,a+i);
    }
    else{
        sort(a,a+i,cmp);
    }
    unique_copy(a,a+i,b);
    for(int j=0;b[j];j++){
        cout << b[j] << (b[j+1]?' ':'\n');
    }
    return 0;
}
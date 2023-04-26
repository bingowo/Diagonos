#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    string in,out;
    cin >> in;
    
    int i = 0;
    for(; i < in.length()-1; i++){
        int next = i;
        while(in[next] == in[next+1]) next++;

        if(in[i] < in[next+1]){
            for(int v = 0; v <= next-i; v++){
                out.insert(out.end(),in[i]);
                out.insert(out.end(),in[i]);
            }
        }
        else {
            for(int v = 0; v <= next-i; v++)
                out.insert(out.end(),in[i]);
        }
        i = next;
    }
    out.insert(out.end(),in[i]);

    cout << out << endl;

    return 0;
}
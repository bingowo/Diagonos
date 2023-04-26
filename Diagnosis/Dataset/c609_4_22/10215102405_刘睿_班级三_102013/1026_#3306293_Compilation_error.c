#include <bits/stdc++.h>
using namespace std;

struct strcou{
    char s[21];
    int cou;
}sl[100];
bool cmp(strcou st1,strcou st2){
    if(st1.cou!=st2.cou)return st1.cou>st2.cou;
    return strcmp(st1.s,st2.s)<0;
}
int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",sl[i].s);
            set<char> st;
            int j=0;
            while (sl[i].s[j] != '\0'){
                st.insert(sl[i].s[j]);
                j++;
            }
            sl[i].cou=st.size();
        }
        sort(sl,sl+n,cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<n;i++){
            printf("%s\n",sl[i].s);
        }
    }
}

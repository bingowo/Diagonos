//#include <iostream>
//#include <cstdio>
//using namespace std;

#include<stdio.h>
#include<stdlib.h>

void solve()
{
    char s[61]; 
    //cin >> s;
    int c,t;
    for(t=0;t<61;t++)
    {
        if(isspace(c=getchar()))
            break;
        scanf("%c",&s[t]);
    }
    int num[128];
    for (int i = 0; i < 128; i++) num[i] = -1;
    int cnt = 0;
    char* p = s;
    num[*p] = 1;  //首位表示1
    while (*++p)
    {
        if (num[*p] == -1)
        {
            num[*p] = cnt;
            cnt = cnt ? cnt + 1 : 2;
        }
    }
    if (cnt < 2) cnt = 2;  //不可能1进制
    long long ans = 0;
    p = s;
    while (*p) ans = ans * cnt + num[*p++];
    printf("%lld\n", ans);
}

int main()
{
    int t; 
    //cin >> t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        //cout << "case #" << i << ":" << endl;
        printf("case #%d:\n",i);
        //solve();
    }
}

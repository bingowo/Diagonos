#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
char a[1001];
double ans;

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++){
        double e=1;
        double m;
        gets(a);
        int l=strlen(a);
        for(int i=2;i<l;i++)
        {
            m=pow(8,e);
            e++;
            ans=ans+(double)(a[i]-'0')/m;
        }
        printf("case #%d:\n",j);
        printf("%f\n",ans);
    }
    return 0;
}

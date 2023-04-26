#include <stdio.h>
#include <math.h>
#include <string.h>

char a[1001];
long double ans;

int main()
{
    int T;
    scanf("%d",&T);
    char b[1001];
    gets(b);
    for(int j=0;j<T;j++){
        double e=1;
        double m;
        ans=0;
        gets(a);
        int l=strlen(a);
        for(int i=2;i<l;i++)
        {
            m=pow(8,e);
            e++;
            ans=ans+(long double)(a[i]-48)/m;
        }
        printf("case #%d:\n",j);
        printf("%Lf\n",ans);
    }
    return 0;
}

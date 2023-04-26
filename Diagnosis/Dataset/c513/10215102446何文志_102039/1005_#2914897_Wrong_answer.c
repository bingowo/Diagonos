#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double sTo8D(char s[])
{
    int len = strlen(s);
    double ans = 0;
    for(int i = len-1;i>=2;i--)
    {
        ans = ans/8 + s[i]-'0';
        printf("s[%d] = %c, %f\n",i,s[i],ans);
    }
    ans = ans/8.0;
    //printf("%f\n",ans);
    return ans;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        char s[60];memset(s,0,60*sizeof(char));
        scanf("%s",s);
        double d = sTo8D(s);
        printf("case #%d:\n");
        printf("%f\n",d);
    }
    return 0;
}

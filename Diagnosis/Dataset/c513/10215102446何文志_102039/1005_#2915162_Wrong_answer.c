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
        //printf("s[%d] = %c, %f\n",i,s[i],ans);
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
        int flen = strlen(s)-2;
        double d = sTo8D(s);
        char ans[200];memset(ans,0,200*sizeof(char));
        sprintf(ans,"%1.150lf",d);
        printf("case #%d:\n",i);
        for(int j = 0;j<2+flen*3;j++)
        {
            printf("%c",ans[j]);
        }
        printf("\n");
    }
    return 0;
}

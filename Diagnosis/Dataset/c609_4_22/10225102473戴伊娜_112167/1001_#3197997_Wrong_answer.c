#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,R,N,t;
    scanf("%d",&T);
    int a[T-1][1];
    char s[32];
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    int m=0;
   for(int i=0;i<T;i++)
    {
        N=a[i][0];R=a[i][1];
        int j=0;
    while(N!=0)
       {
           m=N%R;
           if(m>10)
            s[j]=55+m;
           s[j]=m;
           j++;
           N=N/R;
       }
       t=strlen(s);
       for(int q=0;q<t;q++,t--)
       {
           s[q]=s[t-1];
       }
       printf("%s\n",s);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,R,N,q;
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
           if(m>9)
            s[j]=m+'A'-10;
           else
            s[j]=m+'0';
           j++;
           N=N/R;
       }
       for(q=0;q<j;q++,j--)
       {
           s[q]=s[j-1];
       }
       s[q+1]='\0';
       printf("%s\n",s);
    }
    return 0;
}

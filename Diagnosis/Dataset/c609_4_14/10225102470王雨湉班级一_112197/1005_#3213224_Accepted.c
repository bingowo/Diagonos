#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        char s[50];
        scanf("%s",s);
        int n=0,t;
        for(int j=0; s[j]; j++)
        {
            if(s[j]=='1')
                t=1;
            else if(s[j]=='0')
                t=0;
            else
                t=-1;
            n=n*3+t;
        }
        printf("case #%d:\n%d\n",i,n);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a[260];
        memset(a,-1,260*sizeof(int));
        char s[200];
        scanf("%s",&s);
        int len=strlen(s);
        int base=0;

        for(int j=0;j<len;j++)
        {
            int temp=(int)s[j];
            if(a[temp]==-1)
            {
                base++;
                if(base==1){a[temp]=1;}
                else if(base==2){a[temp]=0;}
                else {a[temp]=base-1;}
            }
        }
        long long num=0;
        if(base==1){base=2;}
        for(int j=0;j<len;j++)
        {
            int temp=(int)s[j];
            int ch=a[temp];
            num=num*base+ch;
        }
        printf("case #%I64d:\n",i);
        printf("%d\n",num);
    }

    return 0;
}

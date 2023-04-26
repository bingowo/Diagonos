#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int s[100];int res[100];int p=0;int l=0,r=0;
        s[p]=a/b;int ta=a%b;res[p]=ta;p++;
        int pl=0,pr=0;
        while(ta&&p<100)
        {
            ta=ta*10;s[p]=ta/b;ta=ta%b;res[p]=ta;
            for(int j=1;j<p;j++)
            {
                if(s[p]==s[j]&&res[p]==res[j]) {pl=j,pr=p;break;}
            }
            if(pl!=0||pr!=0) break;
            p++;
        }
        printf("case #%d:\n",i);
        printf("%d.",s[0]);
        if(ta!=0)
        {
            for(int k=1;k<pr;k++) printf("%d",s[k]);
            printf("\n");
            printf("%d-%d\n",pl,pr-1);
        }
        else
        {
            for(int j=1;j<p;j++) printf("%d",s[j]);
            printf("\n");
        }
    }
    return 0;
}

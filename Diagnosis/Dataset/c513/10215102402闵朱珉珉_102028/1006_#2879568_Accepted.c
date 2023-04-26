#include <stdio.h>
#include <string.h>
int main()
{
    int T,res,q,k=0;
    scanf ("%d",&T);
    char s[1000];
    for (int j=0;j<T;j++)
    {
        res=0;
        scanf("%s",s);
        int len =strlen(s);
        for (int i=0;i<len;i++)
        {
            if (s[i]=='-') q=-1;
            else if (s[i]=='1') q=1;
            else if(s[i]=='0') q=0;
            res=res*3+q;
        }
        printf("case #%d:\n%d\n",k++,res);
    }
    return 0;
}

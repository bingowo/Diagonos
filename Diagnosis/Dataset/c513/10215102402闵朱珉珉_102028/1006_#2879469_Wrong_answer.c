#include <stdio.h>
#include <string.h>
int main()
{
    int T,res,q,k=0;
    scanf ("%d",&T);
    char s[1000];
    for (int i=0;i<T;i++)
    {
        scanf("%s",s);
        int len =strlen(s);
        for (int i=0;i<len;i++)
        {
            if (s[i]=='-') q=-1;
            else q=(int)s[i];
            res=res*3+q;
        }
        printf("case #%d:\n%d\n",k++,res);
    }
    return 0;
}

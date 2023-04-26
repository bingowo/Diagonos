#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    fot(int i=0;i<y;i++)
    {
        char s[61];
        scanf("%s",&s);
        int a[128]; for(int i=0; i<128; i++) a[i]=-1;
        int R=0;
        char *p=s; // 指针p指向字符串第一个字符
        a[*p]=1;
        while (*++p)
        if(a[*p]==-1)
        {
            a[*p]=R;
            R=R?R+1:2;
        }
        if (R<2)
        long long N=0;
        p=s;
        while(*p)
            N=N*R+a[*p++];
        printf("case #%d: \n%11d\n",cas,N);
        
    }
}
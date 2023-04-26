#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int T; scanf("%d",&T);  /* question number  */
    for(int cas=0;cas<T;cas++)
    {
        int a[128]; for(int i=0;i<123;i++) *(a+i) = -1;   /* initialization   */
        int R=0; char s[61]; scanf("%s",s);
        char *p=s;
        *(a+*p)=1;
        while(*++p)
        {
            if(*(a+*p)==-1)
                *(a+*p)=R, R=R?R+1:2;
        }

        long long int A = 0;
        if(R<2) R = 2;
        p=s;
        while(*p)
        {
            A = A * R + *(a+*p++);
        }
        printf("case #%d:\n",cas);
        printf("%lld\n",A);
    }
    return 0;
}
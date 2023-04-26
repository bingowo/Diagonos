#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int T;
    scanf("%d",&T);
    for (int j=0;j<T;j++)
    {
        int F=0,R=0,O=0,S=0,I=0;
        printf("case #%d:\n",j);
        int code[10]={0};
        char s[100]={0};
        scanf("%s",s);
        int n=strlen(s),i,k;
        for (i=0;i<strlen(s);i++)
        {
            if (s[i]=='U')
            {
                code[4]++;
                F--; O--; R--;
            }
            if (s[i]=='W')
            {
                code[2]++;
                 O--;
            }
            if (s[i]=='Z')
            {
                code[0]++;
                 O--; R--;
            }
            if (s[i]=='X')
            {
                code[6]++;
                 S--; I--;
            }
            if (s[i]=='G')
            {
                code[8]++;
                I--;
            }

            if (s[i]=='F') F++;
            if (s[i]=='R') R++;
            if (s[i]=='O') O++;
            if (s[i]=='S') S++;
            if (s[i]=='I') I++;
        }
        if (F)
            for (i=0;i<F;i++)
            {
                code[5]++;
                I--;
            }
        if (R)
            for (i=0;i<R;i++)
                code[3]++;
        if (O)
            for (i=0;i<O;i++)
                code[1]++;
        if (S)
            for (i=0;i<S;i++)
                code[7]++;
        if (I)
            for (i=0;i<I;i++)
                code[9]++;
        for (i=0;i<10;i++)
            if (code[i])
                for (k=0;k<code[i];k++)
                    printf("%d",i);
        printf("\n");
    }


    return 0;
}

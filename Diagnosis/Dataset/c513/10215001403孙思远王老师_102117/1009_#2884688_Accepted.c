#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,T;
    int len,i,i2,i3,j,cou,all;
    char x[1000];
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        cou=0;
        gets(x);
        len=strlen(x);
        for(i=0;i<len;i++)
        {
            j=1;
            for(i2=0;i2<8;i2++)
            {
                if((x[i]|j)==x[i])cou++;
                j=j<<1;
            }
        }
        all=len*8;
        for(i3=cou;i3>0;i3--)
        {
            if((cou%i3==0)&&(all%i3==0))
            {
                cou=cou/i3;
                all=all/i3;
            }
        }
        printf("%d/%d\n",cou,all);
    }
    return 0;
}

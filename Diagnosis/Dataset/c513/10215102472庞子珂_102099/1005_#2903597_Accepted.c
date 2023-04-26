#include <stdio.h>
#include <string.h>
char oct[60],dec[180];
int main()
{
    int t,cas,len,i,j,k,tmp;
    scanf("%d\n",&cas);
    for(t-0;t<cas;++t)
    {
        gets(oct);
        len=strlen(oct);
        k=0;
        memset(dec,0,sizeof dec);
        for (i=len-1;i>=2;--i)
        {
            int n=oct[i]-'0';
            for (j=0;j<k||n;++j)
            {
                tmp=10*n+(j<k?dec[j]-'0':0);
                dec[j]=tmp/8+'0';
                n=tmp%8;
            }
            k=j;
        }
        printf("case #%d:\n0.%s\n",t,dec);
    }
    return 0;


}

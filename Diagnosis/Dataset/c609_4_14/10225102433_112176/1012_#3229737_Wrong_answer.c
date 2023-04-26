#include <stdio.h>
#include <string.h>

const int N=1005;

char str[1005];
char dest[1005];

int main()
{
    int i,j,k,tmp;
    while((scanf("%s",str) != EOF))
    {
        k=0;
        memset(dest,0,sizeof(dest));
        int len=strlen(str);
        for(i=len-1;i>1;i--)
        {
            int num=str[i]-'0';
            for(j=0;j<k || num!=0;j++)
            {
                tmp=10*num+(j<k?dest[j]-'0':0);
                dest[j]=tmp/8+'0';
                num=tmp%8;
            }
            k=j;
        }
        printf("%s [8] = 0.%s [10]\n",str,dest);
    }
    return 0;
}
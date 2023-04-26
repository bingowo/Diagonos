#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
const int N=1005;
 
int main()
{
    int i,j,k,tmp;
    int t;
    scanf("%d",&t);
    char str[N];
    char dest[N];
    for(int m=0;m<t;m++)
    {
        scanf("%s",str);
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
        printf("case #%d:\n",m);
        printf("%s\n",dest);
    }
    return 0;
}
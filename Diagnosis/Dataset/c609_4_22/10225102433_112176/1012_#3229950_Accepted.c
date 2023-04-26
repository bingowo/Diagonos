#include <stdio.h>
#include <string.h>
#define N 1005

int n;
char str[N];
char dest[N];

int main()
{
    scanf("%d",&n);
    int i,j,k,tmp;
    for(int l = 0;l < n;l++)
    {
        printf("case #%d:\n",l);
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
        printf("0.%s\n",dest);
        memset(str,'\0',sizeof(str));
        memset(dest,'\0',sizeof(dest));
    }
    return 0;
}
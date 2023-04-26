#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mul(int a,int *c)
{
    int len;
    len=strlen(c);

}

void add(int *c,int *result)
{

}

int main()
{
    int count,prime[26],i=2,if0=1,j,b[27],len,result[40]={0},prime1[26][40]={1};
    int (*p)[40]=prime1;
    char c;
    prime[0]=1;
    for(count=1;count<=25;count++)
    {
        do
        {
            if0=1;
            for(j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    if0=0;
                    break;
                }
            }
            if(if0)
            {
                prime[count]=i;
            }
            i++;
        }while(!if0);
        strcpy(*(p+count),*(p+count-1));
        mul(prime[count],*(p+count));
    }
    i=0;
    while(scanf("%c",&c)!=EOF&&c!='\n')
    {
        printf("%c hh\n",c);
        if(c==',')  continue;
        else
        {
            b[i]=c-48;
            i++;
        }
    }
    len=i;
    printf("%d\n",len);
    for(i=len-1,j=0;i>=0;i--,j++)
    {
        mul(b[i],*(p+j));
        add(*(p+j),*result);
    }
    return 0;
}

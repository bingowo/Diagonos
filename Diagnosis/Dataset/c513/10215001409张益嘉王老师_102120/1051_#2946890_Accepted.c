#include <stdio.h>
#include <stdlib.h>



char cun[65];

int zhuan(int a[],int st)
{
    int en=st+5,i,re=0;
    for(i=st;i<=en;i++)
    {
        re*=2;
        re+=a[i];
    }
    return re;

}

int main()
{
    int t,i;
    scanf("%d",&t);
    memset(cun,0,sizeof(char)*65);
    for(i=0;i<26;i++)
    {
        cun[i]='A'+i;
    }
    for(i=26;i<52;i++)
    {
        cun[i]='a'+i-26;
    }
    for(i=52;i<62;i++)
    {
        cun[i]='0'+i-52;
    }
    cun[62]='+';
    cun[63]='/';

    /*for(i=0;i<64;i++)
    {
        printf("test: cun[%d]=%c\n",i,cun[i]);
    }*/

    for(i=0;i<t;i++)
    {
        char s[120];
        int a[900],j,k=0,m,b[300];
        memset(a,0,sizeof(int)*900);
        memset(b,0,sizeof(int)*300);

        scanf("%s",s);
        int len=strlen(s);
        for(j=0;j<len;j++)
        {
            for(m=7;m>=0;m--)
            {
                a[k+m]=s[j]%2;
                s[j]/=2;
            }
            k+=8;
        }
        int sum,mid=len*8;
        if(mid%6==0) sum=mid/6;
        else sum=mid/6+1;

        //printf("i=%d,sum=%d\n",i,sum);

        for(j=0,m=0;m<sum;j+=6)
        {
            b[m++]=zhuan(a,j);
        }
        printf("case #%d:\n",i);
        for(j=0;j<sum;j++)
        {
            printf("%c",cun[b[j]]);
        }
        mid=sum%4;
        if(mid!=0)
        {
            mid=4-mid;
            for(j=0;j<mid;j++)
            {
                printf("=");
            }
        }
        printf("\n");
    }
    return 0;
}

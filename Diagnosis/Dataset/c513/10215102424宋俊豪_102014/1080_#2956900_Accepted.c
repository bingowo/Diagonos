#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t,cnt,n,b[105],a[335],c[200];
    char s[105];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        cnt=0;
        if(s[0]=='0')
        {
            printf("0\n");
            continue;
        }
        int len=strlen(s);
        memset(b,0,105);
        memset(c,0,200);
        for(int j=0; j<len; j++)
        {
            b[j]=s[j]-'0';
        }
        for(int j=0; j<335; j++)
              a[j]=0;
        while(1)
        {
            int f=1;
            for(int j=0; j<len; j++)
            {
                if(b[j]!=0)
                {
                    f=0;
                    break;
                }
            }
            if(f!=0)
            {
                break;
            }
            if(b[len-1]%2)
            {

                a[cnt++]=1;
            }
            else
            {
                a[cnt++]=0;
            }
            for(int j=0; j<len-1; j++)
            {
                if(b[j]%2)
                {
                    b[j+1]+=10;
                }
                b[j]/=2;
            }
            b[len-1]/=2;
        }
        int f=1;
        int id=0,carry;
        for(int j=0; j<cnt; j++)
        {
            carry=0;
            if(f==1&&a[j]==0)
                continue;
            else
                f=0;
            for(int q=0; q<=id; q++)
            {
                t=c[q]*2+carry;
                c[q]=t%10;
                carry=t/10;
            }
            if(carry>0)
                c[++id]=carry;
            c[0]+=a[j];
        }
        for(int j=id; j>=0; j--)
            printf("%d",c[j]);
        printf("\n");
    }
    return 0;
}

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{   char s[155],a[50];
    int n,j,len,m,t,num;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",a);
        len=strlen(a)-1;num=0;
        for (;len!=1;--len)
        {
            j=0;
            m=a[len]-'0';
            do
            {
                if (j<num)
                    t=m*10+s[j]-'0';
                else
                    t=m*10;
                s[j++]=t/8+'0';
                m=t%8;
            }while(m!=0||j<num);
            num=j;
        }
        s[num]='\0';
        printf("case #%d:\n",i);
        printf("0.%s\n",s);
    }
    return 0;
}

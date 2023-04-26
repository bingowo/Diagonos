#include <stdio.h>
#include <string.h>
int ir[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int main()
{
    int T;
    scanf("%d",&T);
    for(int h=0;h<T;h++)
    {
        char s[100]={0};
        int ia[100]={0},ib[100]={0},ic[100]={0},t=0,lena,lenb,carry=0,n,x=1;
        scanf("%s",s);
        for(int i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]==',')   
            {
                t++;x=1;continue;
            }
            else
            {
                ia[t]=(s[i]-'0')*x;
                x=x*10;
            }
        }
        lena=t+1;
        t=0;x=1;
        scanf("%s",s);
        for(int i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]==',')   
            {
                x=1;t++;continue;
            }
            else
            {
                ib[t]=(s[i]-'0')*x;
                x=x*10;
            }
        }
        lenb=t+1;
        int len=lena>lenb?lena:lenb;
        n=25;
        for(int i=0;i<len;i++)
        {
            t=ia[i]+ib[i]+carry;
            ic[i]=t%ir[n];
            carry=t/ir[n--];
        }
        if(carry)   ic[len]=carry;
        else len--;
        printf("case #%d:\n",h);
        for(int i=len;i>=0;i--)
        {
            printf("%d",ic[i]);
            if(i==0)    printf("\n");
            else    printf(",");
        }

    }
}


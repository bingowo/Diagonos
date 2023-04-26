#include <stdio.h>
#include <stdlib.h>
void reverse(char s[])
{
    int i,j=strlen(s)-1,l;
    for(i=0;i<j;i++,j--)
    { l=s[i];s[i]=s[j];s[j]=l;    }
}
void itob(int n,int r,char s[100])
{
    int i;
    char m;
    if(n>0)
    {
        for(i=0;n>0;i++)
        {
            m=n%r;
            n=n/r;
            if(m>=0 && m<=9) s[i]=m+48;
            else s[i]=m+55;
        }
    }
    else
    {
        for(i=0;n<0;i++)
        {
            m=(-n)%r;
            n=n/r;
            if(m>=0 && m<=9) s[i]=m+48;
            else s[i]=m+55;
        }
    }
      s[i]=0;
    reverse(s);

    }

int main()
{
    int t,r,n,i;
    char s[100];
    scanf("%d\n",&t);
    for(i=0;i<t;i++);
    {
        scanf("%d %d\n",&n,&r);
         itob(n,r,s);
if(n>0)
        printf("%s\n",s);
else
        printf("-""%s\n",s);

    }


    return 0;
}

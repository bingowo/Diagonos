#include<stdio.h>
int main()
{
    int t,n,r,a,c,j=-1;
    char b[32],d;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        if(n<0) a=-n;
        else a=n;
        c=a;
        while(a!=0)
        {
            a=a/r;
            j++;
        }
        b[j+1]='\0';
        while(c!=0)
        {
           if(c%r<10) d=(char)(c%r+48);
           else d=(char)(c%r+55);
           b[j]=d;
           j--;
           c=c/r;
        }

        if(n==0) printf("%c\n",'0');
        if(n>0) printf("%s\n",b);
        else printf("%c%s\n",'-',b);
    }
    return 0;

}

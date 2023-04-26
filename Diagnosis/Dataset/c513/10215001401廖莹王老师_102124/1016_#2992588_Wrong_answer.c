#include <stdio.h>
#include <stdlib.h>
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
int main()
{
    int n=0,r=0,i=0,k=0;
    scanf("%d %d",&n,&r);
    char s[500]={0};
    for(i=0;abs(n)>0;i++)
    {
        k=0;k=n%r;
        if(k<0){k=n-(n/r+1)*r;n=n/r+1;}else n=n/r;
        if(k>=0 && k<=9)s[i]=k+'0';
        else if(k>=10 && k<=19)s[i]=k-10+'A';
    }
    reverse(s);
    printf("%s",s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void itob(int n,char s[100],int r)
{
    const char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int sign=1;
    if(n<0)
    {
        sign=-1;
        n=-n;
    }


    int k=0;
    do{
        s[k]=table[n%r];
        k++;
        n=n/r;
    }while(n>0);

    if(sign==-1)
    {
        s[k]='-';
        k++;
        s[k]='\0';
    }else
    s[k]='\0';

    int i,j;
    char t;
    j=strlen(s)-1;
    for(i=0;i<j;i++,j--)
    {
      t=s[i];
      s[i]=s[j];
      s[j]=t;
    }

}




int main()
{
    int t, n,r;
    scanf("%d\n",&t);
    int m=0;
    for(m=0;m<t;)
    {scanf("%d %d",&n,&r);
    char s[100];
    itob(n,s,r);
    printf("%s\n",s);
    m++;
    }
    return 0;
}
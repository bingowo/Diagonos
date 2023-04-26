#include <stdio.h>
#include <string.h>
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}

void itob(int n,char s[100],int b)
{
     int i;
     char m;
     if(n>0)
     {
         for(i=0;n>0;i++)
     {
         m=n%b;
         n=n/b;
         if(m>=0 && m<=9)
            s[i]=m+48;
         else
            s[i]=m+55;
     }
     }
     else
     {
         for(i=0;n<0;i++)
     {
         m=(-n)%b;
         n=n/b;
         if(m>=0 && m<=9)
            s[i]=m+48;
         else
            s[i]=m+55;
     }
     }
     s[i]=0;
     reverse(s);
}

int main()
{
    int n,b;
    char s[100];
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
          scanf("%d%d",&n,&b);
    itob(n,s,b);
    if(n>0)
    printf("%s\n",s);
    else
        printf("-""%s\n",s);
    }

    return 0;
}

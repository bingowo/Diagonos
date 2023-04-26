#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,r,k,j;
    char m[100];
    int flag;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
       k=0;
       flag=0;
       scanf("%d %d",&n,&r);
       if(n<0){flag=1;n=-n;}
       if(n==0){printf("0");return 0;}
       while(n!=0)
       {
           if(n>=r)
           {
               if(n%r<10)m[k]=n%r+'0';
               else m[k]=n%r+'A'-10;
               n=/r;
               k++;
           }
           else
           {
               if(n%r<10)m[k]=n%r+'0';
               else m[k]=n%r+'A'-10;
               n=0;
               k++;
           }
           
       }
       if(flag)printf("-");
       for(j=k-1;j>=0;j--)
       printf("%c",m[j]);
       printf("\n");
    }
    return 0;
}
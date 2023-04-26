#include<stdio.h>
#define n 32
int main()
{
    int T,N,R,i=0;
    char c[n];
    scanf("%d\n",&T);
    while(scanf("%d%d",&N,&R)!=EOF)
    {
        if(N<0)
        {N=-N;
        c[0]='-';
        for(i=1;N!=0&&i<=n;i++)
     {
         if(N%R<10) c[i]=N%R+'0';
         if(N%R>=10) c[i]=N%R-10+'A';
         N=N/R;
         
     }
     c[i+1]=0;}
     else{ for(i=1;N!=0&&i<=n;i++)
     {
         if(N%R<10) c[i]=N%R+'0';
         if(N%R>=10) c[i]=N%R-10+'A';
         N=N/R;
         
     }
     c[i+1]=0;}
     int k;
     for(k=i;k>=0;k++) printf("%c",c[k]);
     printf("\n");
    }
    return 0;
}
     
    
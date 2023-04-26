#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char jz[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
    int num,i=1,j,k,N,R;char x[3];
    scanf("%d",&num);
    void zhuan(int N,int R);
    while(i<=num)
    {
        j=0;N=0;
        scanf("%s",x);j=strlen(x);
        scanf("%d",&R);
        if(x[0]=='-'){for(k=1;k<=j;k++)N=N*10+x[k]-'0';printf("-");zhuan(N,R);}
        else{for(k=0;k<j;k++)N=N*10+x[k]-48;zhuan(N,R);}
        printf("\n");
    }
}

void zhuan(int N,int R)
{
    int i=0,m,k,c;char str1[100];
    while(N>0)
    {
        c=N%R;str1[i]=jz[c];
        N=N/R;
        i++;
    }str1[i]='\0';
    for(k=i-1;k>=0;k--)printf("%c",str1[k]);
}

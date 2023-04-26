#include<stdio.h>
#include<math.h>
int main()
{
    int pro;
    scanf("%d",&pro);
    char d=getchar();
    for(int j=0;j<pro;j++)
    {
       int eig[50],i=0;
       long double res=0,tmp;
       char c;
       while((c=getchar())!='\n')
       {
           eig[i]=c-'0';
           i++;
       }

       for(int m=2;m<i;m++)
       {
           tmp=pow(8,1-m)*eig[m];
           res+=tmp;
       }
    printf("case #%d:\n%llf\n",j,res);
    }
}
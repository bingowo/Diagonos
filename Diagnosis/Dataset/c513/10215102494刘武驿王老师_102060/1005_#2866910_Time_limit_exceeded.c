#include<stdio.h>
#include<math.h>
int main()
{
    int pro;
    scanf("%d",&pro);
    for(int j=0;j<pro;j++)
    {
       int eig[50],i=0;
       double res=0;
       char c;
       while((c=getchar())!="\n")
       {
           eig[i]=c-'0';
           i++;
       }
       for(int j=2;j<i;j++)
       {
           res+=pow(8,-j+1);
       }
    printf("case #%d\n%d\n",j,res);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
void read(char s[100],int a[26])
{
    reverse(s);
    int i=0,k=25;
 for(i=0;s[i];i++)
    {
        if(s[i]!=',' && s[i+1]!=',' && s[i+1]){a[k]=s[i]-'0'+(s[i+1]-'0')*10;i=i+1;k--;}
        else if(s[i]!=','){a[k]=s[i]-'0';k--;}

    }
}
void sum(int a[26])
{   int i=25,k;
    double m,sum=0;
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    for(i=25;i>=0;i--)
    {
        m=1;
        if(i<25){for(k=25;k>i;k--)m=m*prime[k];}
        sum=sum+a[i]*m;
    }
    printf("%.0lf",sum);
}
int main()
{
    char s[100];
    int a[26]={0};
    int i;
    scanf("%s",s);
    read(s,a);
    for(i=0;i<26;i++)printf("%d",a[i]);
   printf("\n");
   sum(a);
    return 0;
}

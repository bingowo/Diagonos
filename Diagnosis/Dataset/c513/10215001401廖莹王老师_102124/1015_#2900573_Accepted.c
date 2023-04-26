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
void add(int a[26],int b[26],int c[26])
{
    int k=0,i=25;
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    for(i=25;i>=0; i--)
    {

        c[i]=(a[i]+b[i]+k)%prime[i];
        k=(a[i]+b[i]+k)/prime[i];

    }
}
void output(int c[26])
{
    int i=0;

    for(i=0;i<26 && c[i]==0;i++);
    if(i==26)printf("0");
    else
    {
         for(i=i;i<25;i++)printf("%d"",",c[i]);
    printf("%d",c[i]);
    }

}
int main()
{
    char s[100];
    int n,k,i;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
         char s[100];
    int a[26]={0},b[26]={0},c[26]={0};
    scanf("%s",s);
    read(s,a);
    scanf("%s",s);
    read(s,b);
    add(a,b,c);
    printf("case #%d:\n",k);
    output(c);
    printf("\n");
    }

    return 0;
}

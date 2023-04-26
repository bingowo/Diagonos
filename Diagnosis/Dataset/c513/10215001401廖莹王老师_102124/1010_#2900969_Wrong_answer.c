#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void reverse(char s[])
{  int c,i,j;
for(i=0,j=strlen(s)-1;i<j;i++,j--)
    c=s[i],s[i]=s[j],s[j]=c;}
void erjinzhi(int d)
{    int i,j,l,k;
    char s[100]={0};
   for(i=0;d>0;i++)
    {   if(i==0 && d==1){s[0]='1';i++;break;}
        s[i]=d%2+48;d=d/2;}
        s[i]=0;
     reverse(s);
     printf("%010s",s);
    }
void erjinzhi1wei(int d)
{    int i,j,l,k;
    char s[100]={0};
   for(i=0;d>0;i++)
    {   if(i==0 && d==1){s[0]='1';i++;break;}
        s[i]=d%2+48;d=d/2;}
        s[i]=0;
     reverse(s);
     printf("%04s",s);
    }
    void erjinzhi2wei(int d)
{    int i,j,l,k;
    char s[100]={0};
   for(i=0;d>0;i++)
    {   if(i==0 && d==1){s[0]='1';i++;break;}
        s[i]=d%2+48;d=d/2;}
        s[i]=0;
     reverse(s);
     printf("%07s",s);
    }
int main()
{
    char s[1000]={0};
    int a[1000]={0},j=0,i,k=0,m=0;
    scanf("%s",s);
    printf("0001");
    j=strlen(s);
    erjinzhi(j);
    for(i=0;i<j && s[i];)
    {
        for(m=0;m<3 && s[i];m++,i++)
        a[k]=a[k]*10+(s[i]-'0');
        k++;
    }
    if(j%3==0)
    {
         for(i=0;i<k;i++)
    {
        erjinzhi(a[i]);

    }

    }
    else if(j%3==1)
    {
         for(i=0;i<k-1;i++)
    {
        erjinzhi(a[i]);

    }
    erjinzhi1wei(a[i]);
    }
    else if(j%3==2)
    {
         for(i=0;i<k-1;i++)
    {
        erjinzhi(a[i]);

    }
    erjinzhi2wei(a[i]);
    }



    return 0;
}

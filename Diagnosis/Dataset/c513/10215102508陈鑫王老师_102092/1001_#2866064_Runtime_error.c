#include<stdio.h>
#include<stdlib.h>
char* itor(int x,int y)
{
    char a[10000],b[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i=0;
    if(x<0)
    {
        a[0]='-';
        i=i+1;
        x=-x;
    }
    while(x!=0)
    {
        if((x%y)>=10)
        {
            a[i]=b[(x%y)-10];
        }
        else a[i]='x%y';
        x=x/y;
    }
    return a;
}
int main()
{
 int t;
 scanf("%d",&t);
 int a[t][2];
 int c=0;
 while(c<t)
 {
     scanf("%d%d",&a[c][0],&a[c][1]);
     c+=1;
 }
 for(int i=0;i<t;i++)
 {
    char *p=itor(a[i][0],a[i][1]);
    for(int i=0;i<sizeof(p);i++,p++)
        printf("%c",*p);
    printf("\n");
 }
 return 0;
}

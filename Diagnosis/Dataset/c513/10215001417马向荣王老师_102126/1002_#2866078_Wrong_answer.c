#include<stdio.h>
int main()
{
    int t;
    int i=0,j=0,p=0,num=0,sz=0;
    int s[]={0};
    scanf("%d\n",&t)!=EOF;
    char a[61];
    for(i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
         while(scanf("%s\n",a)!=EOF)
         {
             int sz=sizeof(a)/sizeof(a[0]);
             for(j=0;j<sz;j++)
             {
                 int m=0;
                 while(m<sz-j)
                 {
                     if(a[j]!=a[m])
                     {
                         num+=1;
                         m++;
                     }
                     else
                     {
                         m++;
                     }
                 }//num是最小进制数
             }
             if(sz==1)
             {
                 printf("0\n");
             }
             if(sz>1 && num==1)
             {
                 while(p<sz)
                 {
                     s[p]=1;
                     p++;
                 }
                 printf("%s\n",s);
             }
         }
         
    }
    return 0;
}
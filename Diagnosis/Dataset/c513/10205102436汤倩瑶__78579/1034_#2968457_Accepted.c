#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
double p[128]={0};
int cmp(const void*a,const void*b)
{
    char p1=*((char *)a);
    char p2=*((char *)b);
    if(p[p1]>p[p2])return -1;
    else if(p[p1]<p[p2])return 1;
    else {
        if(abs(p1-p2)==32)
       return p2-p1; 
         // else return p1-p2;

    }


}



int main()
{
    int T;
    char s[105];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
   for(int j=0;j<26;j++)
   {
       scanf("%lf",&p['A'+j]);
       p['a'+j]=p['A'+j];
   }
        scanf("%s",s);
        int l=strlen(s);
        qsort(s,l,sizeof(s[0]),cmp);
        printf("case #%d:\n%s\n",i,s);


    }



}

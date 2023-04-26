#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



    int cmp(const void*a1,const void*a2)
    {
        char* a= (char*)a1;
        char* b=(char*)a2;
        char m=a[0],n=b[0];
         if(a[0]=='-') m=a[1];
        if(b[0]=='-') n=b[1];
        int sum1=0,sum2=0,len1,len2;
        len1=strlen(a);len2=strlen(b);
        if(a[0]!='-')
        {for(int i=0;i<len1;i++)
        sum1+=sum1*10+a[i]-48;}
        else {for(int i=1;i<len1;i++)
       { sum1+=sum1*10+a[i]-48;sum1=-sum1;}}
       if(b[0]!='-')
        {for(int i=0;i<len2;i++)
        sum2+=sum2*10+b[i]-48;}
        else {for(int i=1;i<len2;i++)
       { sum2+=sum2*10+a[i]-48;sum2=-sum2;}}
        
        if(m!=n) return n-m;
        else return sum1-sum2;
    }
    

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        char a[m+1][20];
        for(int k=0;k<m;k++)
        {
            scanf("%s",a[k]);
        }
       qsort(a,m,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int l=0;l<m;l++)
        printf("%s ",a[l]);
        printf("\n");
    }
    return 0;
}
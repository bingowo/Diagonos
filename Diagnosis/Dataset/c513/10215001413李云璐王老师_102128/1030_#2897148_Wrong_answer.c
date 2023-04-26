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
        if(m!=n) return n-m;
        else return atoi(a)-atoi(b);
    }
    

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        char a[m+1][19];
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
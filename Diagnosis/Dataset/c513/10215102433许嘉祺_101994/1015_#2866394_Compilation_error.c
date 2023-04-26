#include <stdio.h>
#include <stdlib.h>

int main()
{   int t;
    int lena,lenb;
    int a[26],b[26];
    int c[26]={2,3};
    scanf("%d",&t);
    memset(a,0,sizeof(int));
    memset(b,0,sizeof(int));
    
    for (int i=0;i<t;i++)
    {
    lena=0;
     lenb=0;
     char c;
        while (isspace(c=getchar())!=0) if (c!=',') {a[lena]=c;k++;}
        a[lena]=0;
        while (isspace(c=getchar())!=0) if (c!=',') {b[lenb]=c;k++;}
        b[lenb]=0;
        
    }
    
    return 0;
}

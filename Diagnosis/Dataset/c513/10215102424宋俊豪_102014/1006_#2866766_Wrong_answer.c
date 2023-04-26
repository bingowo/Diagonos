#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main()
{   int a[100];char s[100];
    a['-']=-1;
    a['0']=0;
    a['1']=1;
    int n,j,total;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   j=0;total=0;
        scanf("%s",s);
        while(s[j]!='\0')
        {
            total=total*3+a[s[j]];
            j++;
        }
        printf("case #%d:\n",i);
        printf("%lld",total);
    }
    return 0;
}

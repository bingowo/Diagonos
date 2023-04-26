#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[501],b[500];
    int id,n,a[130];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {   id=0;memset(b,0,500);
        for(int j=0; j<130; j++)
            a[j]=0;
        scanf("%s",s);
        b[0]=s[0];
        a[0]=1;
        int l=strlen(s);
        for(int j=1;j<l;j++)
            if(s[j]!=b[id])
            {
                id++;
                b[id]=s[j];
                a[id]=1;
            }
            else
            {
                a[id]++;
            }
         printf("case #%d:\n",i);
         for(int j=0;j<id+1;j++)
        {
            while(a[j]>255)
            {
                printf("255%c",b[j]);
                a[j]=a[j]-255;
            }
            printf("%d%c",a[j],b[j]);
        }
        printf("\n");
    }
    return 0;
}

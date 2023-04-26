#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;scanf("%d",&n);char *a=malloc(sizeof(int)*100000),*b=malloc(sizeof(int)*100000);
    for(int i=0;i<=n;i++)
    {
        if(i==0){a[0]='0';a[1]='\0';continue;}
        strcpy(b,a);
        int j=0;
        while(1)
        {
            if(b[j]=='0')b[j]='1';
            else if(b[j]=='1')b[j]='0';
            else break;
            j++;
        }
        strcat(a,b);
    }
    printf("%s",a);
}
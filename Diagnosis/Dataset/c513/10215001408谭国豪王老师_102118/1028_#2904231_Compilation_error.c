#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int a[30]={0},i=0,j,k,t,q;
    scanf("%c",&c);
    while(getchar()!='\n')
    {scanf("%d",&a[i]);
    i++;}
    for(j=0;j<i;j++)
    {
        for(k=j+1;k<i;k++)
        {
            if(a[j]<a[k])t=a[j];
            a[j]=a[k];
            a[k]=t;
        }
    }
  { for(q=0;q<i-1;q++)
    {
        if(a[q]==a[q+1])a[q]=999;
    }
    if(c=='D'){
        for(q=0;q<i&&a[q]!=999;q++)
            printf("%d",a[q]);
            printf(" ");
    }
    else
    {
         for(q=i-1;q>=0&&a[q]!=999;q--)
            printf("%d",a[q]);
    }
    return 0;
}



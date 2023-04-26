#include<stdio.h>
int cmp(int a,int b)
{
    if(a>b)
     {b=a;return b;}
    else return b;
}
char table[]="01";
 int length(int num)
{   int j=0;
    int e=0;
    char a[100];
    int b[100]={0};
    do{int r=num%2 ;
    a[j++]=table[r];
    num=num/2;
    }while(num);
    int k=0;
    for(j=j-1;j>=0;j--)
    {
        if (a[j]!=a[j-1])
        b[k]=b[k]+1;
        else k++;
            }

    for(;e<k;e++)
        cmp(b[e],b[e+1]);
        return b[e+1];}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int num;
        scanf("%d\n",&num);
    printf("case #%d\n",i);
    printf("%d",length(num));
    }
    return 0;
}





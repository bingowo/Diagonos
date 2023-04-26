#include <stdio.h>
void cmp(int a,int b)
{
    if(a>b)
        b=a;
}
int longth(int num)
{   int j=0;
    int e=0;
    char a[100];
    int b[100]={0};
    int*p[100];
    for(int i=0;i<100;i++)
    {
        *p[i]=b[i];
    }
    do{a[j++]=num%2;
    num=num/2;
    }while(num);
    int k=0;
    for(;j>=0;j--)
    {
        if (a[j]!=a[j--])
        *p[k]=(*p[k])+1;
        else k++;
            }
    for(;e<k;e++)
        cmp(*p[e],*p[e+1]);
        return *p[e+1];

}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int num;
        scanf("%d\n",&num);
    printf("case #%d\n",i);
    printf("%d",longth(num));
    }
    return 0;
}



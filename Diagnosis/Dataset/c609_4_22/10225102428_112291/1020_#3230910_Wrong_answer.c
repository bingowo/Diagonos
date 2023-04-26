#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(char* A, char* B)
{
    char* a = (char*) A;
    char* b = (char*) B;
    int l1=sizeof(*a)/sizeof(char);
    int l2=sizeof(*b)/sizeof(char);
    int m,n;
    for(int j=0;j<sizeof(*a);j++)m+=(int)*a;
    for(int i=0;i<sizeof(*b);i++)n+=(int)*b;

    if(l1==l2)
    {
        if(m>n)
            return 1;//a所指的元素排在b所指元素的右边
        else
            return -1;//左边
    }
    else
        return l2-l1;//按1的数目来排序

}
int main()
{
    char a[3000];
    int j=0;
    while(scanf("%c",a+j)!=EOF){
            j++;
    }
    qsort(a,j, sizeof(char), cmp);
    for(int i=0;i<j;i++)printf("%c%c",a[i],i!=j-1?' ':'\n');
    return 0;
}

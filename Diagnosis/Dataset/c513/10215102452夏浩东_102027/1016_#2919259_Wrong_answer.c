#include <stdio.h>
int main()
{
    int num=0,R=0,temp=0,i=0;
    scanf("%d %d",&num,&R);
    int L[100]={0};
    while(num!=0)
    {
        temp=num%R;
        num=num/R;
        L[i]=temp;
    }
    for(int k=i-1;k>=0;k--)
    {
        if(L[k]>9) printf("%c",L[k]-10+'A');
        else printf("%c",L[k]-'0');
    }
    return 0;
}
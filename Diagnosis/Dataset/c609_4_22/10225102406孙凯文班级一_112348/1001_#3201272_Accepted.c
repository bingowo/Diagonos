#include<stdio.h>
void a(int n,int r)
{
    char b[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(n!=0) a(n/r,r),printf("%c",b[n%r]);
}
int main()
{
    int t,n,r;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        if(n==0) printf("0");
        if(n<0) n=-n,printf("-"),a(n,r);
        else a(n,r);
        printf("\n");
    }
    return 0;
}
//记得每个输出的末尾要有\n
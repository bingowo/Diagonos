#include<stdio.h>
void a(int n,int r)
{
    char b[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
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
        a(n,r);
    }
    return 0;

}

#include <stdio.h>

int main()
{
    long long int n;
    scanf("%d",&n);
    int i=0;int x=0,y=0;
    if(n==0)
    {
        printf("(%d,%d)",x,y);
        return 0;
    }
    for(i=0;i<10000000000000;i++)
    {
        if(n>=(2*i+1)*(2*i+1)&&n<=(2*i+3)*(2*i+3))break;
    }
    int flag=0;
    long long int copy=(2*i+1)*(2*i+1);
    x=i;y=i+1;
    while(flag<(2*i+1)&&(copy!=n))
    {
        flag++;
        x--;
        copy++;
    }
    //printf("%d",);
    //printf("(%d,%d)",x,y);

    flag=0;
    while(flag<(2*i+2)&&(copy!=n))
    {
        flag++;
        y--;
        copy++;
    }
    //printf("(%d,%d)",x,y);
    flag=0;
    while(flag<(2*i+2)&&(copy!=n))
    {
        flag++;
        x++;
        copy++;
    }
    //printf("(%d,%d)",x,y);
    flag=0;
    while(flag<(2*i+2)&&(copy!=n))
    {
        flag++;
        y++;
        copy++;
    }
    //printf("(%d,%d)",x,y);
    if(copy!=n)y++;
    printf("(%d,%d)",x,y);
}

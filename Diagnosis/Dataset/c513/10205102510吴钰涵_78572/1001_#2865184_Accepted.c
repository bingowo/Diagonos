#include <stdio.h>

int trans(int num,int R)
{
    char arr[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char a[32];
    int i;
    for(i=0;num/R!=0;i++)
    {
        a[i]=arr[num%R];
        num=num/R;
    }
    a[i]=arr[num];
    for(;i>=0;i--)
        printf("%c",a[i]);
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int num,R;
        scanf("%d %d",&num,&R);
        if(num<0)
        {
            printf("-");
            num=-num;
        }
        trans(num,R);
    }
    return 0;
}

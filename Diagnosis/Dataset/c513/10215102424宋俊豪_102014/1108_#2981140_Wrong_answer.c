#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void sol(int a,int b)
{
    printf("0.");
    int f=-1,tem,j,id=0,t[200]={0};
    t[id++]=a;
    do{
        a=a*10;
        printf("%d",a/b);
        a=a%b;
        t[id++]=a;
        for(int j=0;j<id-1;j++)
        {
            if (t[j]==t[id-1])
            {   printf("\n");
                printf("%d-%d",j+1,id-1);
                f=1;
                break;
            }
        }
        if(f==1)
            break;
    }while(a!=0);
    if(f!=1)
    printf("\n");

}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         printf("case #%d:\n",i);
         scanf("%d %d",&a,&b);
         sol(a,b);
    }
}

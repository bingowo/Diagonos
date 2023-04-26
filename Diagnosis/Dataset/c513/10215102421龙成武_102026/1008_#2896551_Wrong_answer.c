#include <stdio.h>
#include <string.h>

void changebin(char *a,int num)
{
    int i=0;
    while(num>=2)
    {
        a[i++]=num%2+'0';
        num=num/2;
    }
    a[i++]=num+'0';
    a[i]=0;
}
int findit(char *a,char *b)
{
    int res,p;
    res=p=0;
    while(p<strlen(a)||p<strlen(b))
    {
        if(a[p]!=b[p])
            res++;
        p++;
    }
    return res;
}
void myPrint(int res)
{
    static int tim=0;
    printf("case #%d:\n", tim);
    //printf("0.");
    printf("%d\n",res);
    tim++;
}
int main()
{
    int i,T,num1,num2,res;
    char a[33],b[33];
    scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        scanf("%d",&num1);
        scanf("%d",&num2);

        memset(a,0,sizeof(char)*33);
        memset(a,0,sizeof(char)*33);

        changebin(a,num1);
        changebin(b,num2);

        res=findit(a,b);
        printf("%d",res);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<math.h>
int getlen(int *p,int len)
{
    len=len*3;
    p=p+len;
    while(*p==0)
    {
        p--;
        len--;
    }
    return len;
}
void div(int *p,int x,int len)
{
    //printf("div\n");
    printf("len=%d\n",len);
    int k=0;
    while (k<=len || *p!=0)
    {
        *(p+1)+=10*(*p%x);
        *p/=x;
        p++;
        k++;
    }
}
int main()
{
    int T,i,j,k,n,t,l;
    double a;
    char s[100];
    int num[200]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        memset(num,0,sizeof(num));
        scanf("%s",s);
        l=strlen(s);
        a=0;
        k=0;
        for(j=l-1;j>=2;j--)
        {
            num[0]+=(s[j]-'0');
            div(num,8,getlen(num,l-j-1));
        }
        printf("case #%d:\n0.",i);
        for(j=1;j<=getlen(num,l-2);j++)
        {
            printf("%d",num[j]);
        }
        printf("\n");
    }
    return 0;
}
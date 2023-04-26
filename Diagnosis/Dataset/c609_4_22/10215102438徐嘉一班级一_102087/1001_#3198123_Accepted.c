#include <stdio.h>
#include <stdlib.h>
#define D 37
void tran(int a,int b)
{
    int i,s[D];
    if(a<b)
    {
        if(a<10)
            printf("%d",a);
        else
            printf("%c",a-10+'A');
    }
    else
    {
        for(i=0;a;i++)
        {
            s[i]=a%b;a=a/b;
        }
        i=i-1;
        for(int j=i;j>=0;j--)
        {
            if(s[j]<10) printf("%d",s[j]);
            else printf("%c",s[j]-10+'A');
        }
    }

}
int main()
{
    int T,N[D],R[D];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {scanf("%d %d",&N[i],&R[i]);}
    for(int j=0;j<T;j++)
    {
        if(N[j]>=0) {tran(N[j],R[j]);}
        else
        {
            printf("-");
            tran(-N[j],R[j]);
        }
        printf("\n");




    }
    return 0;
}

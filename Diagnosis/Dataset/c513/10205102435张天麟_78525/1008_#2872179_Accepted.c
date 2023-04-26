#include<stdio.h>
#include<string.h>
char X[25],Y[25];
void change(int a,char A[])
{
    int i=0;
    while(a>0)
    {
        A[i]='0'+a%2;
        a=a/2;
        i++;
    }
}
int main()
{
    int T,k=0;
    scanf("%d",&T);
    for(int n=0;n<T;n++)
    {
        k=0;
        for(int b=0;b<25;b++)
        {
            X[b]='0';
            Y[b]='0';
        }
        int x,y;
        scanf("%d %d",&x,&y);
        change(x,X);
        change(y,Y);
        for(int j=0;j<25;j++)
        {
            if(X[j]!=Y[j])
            {
                k++;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}

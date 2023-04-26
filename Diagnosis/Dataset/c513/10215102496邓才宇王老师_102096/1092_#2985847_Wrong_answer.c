#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
void mult_n(int a[],int n)
{
    int i;
    for(i=N-1;i>0;i--)
        a[i]*=n;
    for(i=N-1;i>0;i--)
    {
        a[i-1] += a[i]/10;
        a[i]%=10;
    }
}void output(int a[])
{
    int i=0;
    while(i<N&& a[i]==0) i++;
    if(i>=N)
    { printf("0\n"); return;}

    while(i<N)
        printf("%d",a[i++]);
    printf("\n");

}
int main()
{
    char w[2000];
    int s[2000];
    scanf("%s",w);
    if(strlen(w)==1) printf("%d",1);
    else
    {
        if(w[0]==w[1]) s[0]=1;
        else s[0]=2;
        if(w[strlen(w)-1]==w[strlen(w)-2]) s[strlen(w)-1]=1;
        else s[strlen(w)-1]=2;
        for(int i=1;i<strlen(w)-1;i++)
        {
            if(w[i]!=w[i+1]&&w[i]!=w[i-1]) s[i]=3;
            else if((w[i]!=w[i+1]&&w[i]==w[i-1])||(w[i]==w[i+1]&&w[i]!=w[i-1])) s[i]=2;
            else s[i]=1;
        }
         int ans[100];
    ans[99]=1;
    for(int j=0;j<strlen(w);j++)
    {
        mult_n(ans,s[j]);
    }
    output(ans);
    }
}

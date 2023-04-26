#include <stdio.h>
#include <string.h>

int s[10001];
int data[11];
void weight(int n,int sum)
{
    if(n==-1)
    {
        if(sum>0)
            s[sum]=1;
        return;
    }
    weight(n-1,sum+data[n]);
    weight(n-1,sum-data[n]);
    weight(n-1,sum);
}
int main() {
    int n;
    scanf("%d",&n);
    int sum=0;
    memset(s,0,sizeof (s));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
        sum+=data[i];
    }
    weight(n,0);

    for(int i=1;i<=sum;i++)
    {
        if(s[i])
            printf("1");
        else
            printf("0");
    }
    return 0;
}

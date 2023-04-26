#include<stdio.h>
#include<string.h>
long long trans(char N[]);
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char N[60];
        scanf("%s",&N);
        printf("case #%d:\n",i);
        printf("%lld\n",trans(N));
    }
}
long long trans(char N[])
{
    int R=2;
    int a[123];
    for (int i=0;i<123;i++)    a[i]=-1;
    if (strlen(N)==1)
        return 1;
    int j=1;
    a[N[0]]=1;
    while (N[j]!='\0') 
    {
        if (a[N[j]]==-1)
        {
            a[N[j]]=0;
            break;
        }
        else
            j++; 
    }
    while (N[j]!='\0')
    {
        if (a[N[j]]==-1)
        {
            a[N[j]]=R;
            R++;
        }
        j++;
    }
    long long ans=0,k=0;
    while (k<j)
    {
        ans=ans*R+a[N[k]];
        k++;
    }
    return ans;
}
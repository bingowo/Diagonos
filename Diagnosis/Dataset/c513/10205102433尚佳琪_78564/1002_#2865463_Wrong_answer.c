#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int change(char a[],int n,int r)
{

}*/
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[100];
        int a[128];
        for(int i=0;i<128;i++)
            a[i]=-1;
        scanf("%s",s);
        a[0]=1;///////?
        int len=strlen(s);
        char *p;p=s;
        a[*p]=1;
        int digit=0,N=1;
        while(*(p++))
        {
            if(a[*p]==-1)
            {
                a[*p]=digit;
                digit=digit?digit++:2;
                N++;
            }
        }
        if(N<2)N=2;
        int num=0;
       long long sum=0;
       for(int i=0;i<len;i++)
        {
            num=a[s[i]];
            sum=sum*N+num;
            //printf("%d",N);
        }
       printf("case#%d:\n%lld\n",i,sum);
    }
    return 0;
}

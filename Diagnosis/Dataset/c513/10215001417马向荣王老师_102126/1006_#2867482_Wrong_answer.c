#include<stdio.h>
#include<math.h>
int main(void)
{
    int t=0,n=0,sz=0,tmp=0;
    long int sum=0;
    char s[10000];//输入字符串
    scanf("%d\n",&t);
    while(n<t)
    {
        scanf("%s\n",s);
        n++;
        printf("case #%d:\n",n);
        sz=sizeof(s)/sizeof(s[0]);//如果s的这位是-，那么s[i]=0；0，s[i]=1，1，s[i]=2
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='-')
            {
                s[i]=0;
            }
            if(s[i]=='0')
            {
                s[i]=1;
            }
            if(s[i]=='1')
            {
                s[i]=2;
            }
        }
        for(int j=sz;j>0;j--)
        {
            tmp=3^(sz-1);
            sum+=tmp;
        }
        printf("%ld\n",sum);
    }
    
    return 0;
}
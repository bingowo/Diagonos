#include<stdio.h>
#include<math.h>
int main(void)
{
    int t=0,n=0,sz=0;
    long long int sum=0;
    char s[10000];//输入字符串
    scanf("%d\n",&t);
    for(n=0;n<t;n++)
    {
        scanf("%s\n",s);
        n++;
        printf("case #%d:\n",n);
        sz=sizeof(s)/sizeof(s[0]);
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='-')
            {
                s[i]=-1;
            }
            sum+=s[i]*3^(sz-i-1);
        }
    }
    return 0;
}
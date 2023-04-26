#include <stdio.h>
#include <stdlib.h>//atof头文件
double res()
{
    char s[50];
    scanf("%s",s);
    switch(s[0])
    {
        case '+':return res()+res();
        case '-':return res()-res();
        case '*':return res()*res();
        case '/':return res()/res();
        default: return atof(s);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        double ans;
        ans=res();
        printf("case #%d:\n",i);
        printf("%lf\n",ans);
    }
    return 0;
}

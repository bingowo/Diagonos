#include<stdio.h>
#include<string.h>

int main()
{
    int flag=0;
    int ans=0;
    char c;
    while((c=getchar())!='\n')
    {
        if(!(c>='0'&&c<='9'))
        {
            flag=0;
        }
        else
        {
            if(c=='0'&&flag==0)
            {
                continue;
            }
            else
            {
                flag++;
            }
        }
        if(flag>ans) ans=flag;
        /*printf("c:%c  flag:%d  ans:%d\n",c,flag,ans);*/
    }
    printf("%d",);
}

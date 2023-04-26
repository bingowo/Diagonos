#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[121];
        scanf("%s",s);
        int num1=0,num2=0;
        for(int i=0;s[i]!='\0';i++)
        {
            int k =(int)s[i];
            while(k>0)
            {
                if(k%2==0) num1++;
                num++;
                k=k/2;
            }
        }
        if((num)%num1==0)
        {
            num1=1;
            num=num/num1;
        }
        printf("%d/%d\n",num1,num);
    }
    return 0;
}
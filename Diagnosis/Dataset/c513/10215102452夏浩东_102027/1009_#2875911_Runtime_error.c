#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[121];
        scanf( "%[^\n]",s);
        int num1=0,i=0;
        for(i=0;s[i]!='\0';i++)
        {
            int k =(int)s[i];
            while(k>0)
            {
                if(k%2!=0) num1++;
                k=k/2;
            }
        }
        int num=8*i;
        if(num%num1==0)
        {
        	num=num/num1;
            num1=1;
        }
        printf("%d/%d\n",num1,num);
    }
    return 0;
}
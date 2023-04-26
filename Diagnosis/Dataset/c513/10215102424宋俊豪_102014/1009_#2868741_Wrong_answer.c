#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int getline(char s[],int lim)
{
    int c,i;
    i=0;
    while((c=getchar())!=EOF&&c!='\n'&&i<lim-1)
        s[i++]=c;
    s[i]='\0';
    return i;
}
int main()
{
    char s[121];
    int cnt,n,j,total,num1,num2,t;
    scanf("%d",&n);j=getchar();
    for(int i=0; i<n; i++)
    {
        j=0;
        total=0;
        num1=0;
        num2=0;
        t=2;
        getline(s,121);
        while(s[j]!='\0')
        {
            total=s[j];
            cnt=0;
            while (cnt<8)
            {
                if (total&1==1)
                    num1++;
                else
                    num2++;
                total=total>>1;
                cnt++;
            }
            j++;
        }
        while((t<=num1)&&(t<=num2))
        {
            if ((num1%t==0)&&(num2%t==0))
            {
                num1=num1/t;
                num2=num2/t;
            }
            else
                t++;

        }
        printf("%d/%d\n",num1,num2);
    }
    return 0;
}

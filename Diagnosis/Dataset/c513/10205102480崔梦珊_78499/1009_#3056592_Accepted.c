#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char c=getchar();
    for(int i=0;i<n;i++)
    {
        char s[121]={'\0'};
        int len=0;
        int fenzi=0;
        while((c=getchar())!='\n')
        {
            s[len]=c;
            len++;
        }
        for(int j=0;j<strlen(s);j++)
        {
            char tempp=s[j];
            while(tempp)
            {
                tempp=tempp&(tempp-1);
                fenzi++;
            }
        }
        int fenmu=strlen(s)*8;
        int a=fenzi;
        int b=fenmu;
        int temp=a;
        //printf("%d\n%d\n",fenzi,fenmu);
        while(b%a)
        {
            temp=b%a;
            b=a;
            a=temp;
        }
        //printf("%d\n",temp);
        fenmu=fenmu/temp;
        fenzi=fenzi/temp;
        printf("%d/%d\n",fenzi,fenmu);
    }
    return 0;
}

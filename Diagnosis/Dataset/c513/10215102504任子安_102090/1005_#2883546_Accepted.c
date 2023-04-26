#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        char input[100]={'\0'};
        scanf("%s",&input);
        int i;
        char res[1000]={'\0'};
        int j,k=0,tmp;
        for(i=strlen(input)-1;i>1;i--)
        {
            int num=input[i]-'0';
            for(j=0;j<k || num!=0;j++)
            {
                tmp=10*num+(j<k?res[j]-'0':0);
                res[j]=tmp/8+'0';
                num=tmp%8;
            }
            k=j;
        }
        printf("case #%d:\n0.%s\n",t,res);
        t++;
    }
    return 0;
}
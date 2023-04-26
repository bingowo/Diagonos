#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        char input[100]={'\0'},ch[100]={'\0'};
        scanf("%s",&input);
        int count=1,i;
        ch[0]=input[0];
        for(i=1;i<strlen(input);i++)
        {
            int j=0,flag=0;
            for(;j<count;j++)
            {
                if(ch[j]==input[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ch[count++]=input[i];
            }
        }

        int numpad[100]={-1};
        numpad[0]=1;
        numpad[1]=0;
        for(i=2;i<count;i++)
        {
            numpad[i]=i;
        }

        int res=0;
        for(i=0;i<strlen(input);i++)
        {
            int j=0;
            for(j=0;j<count;j++)
            {
                if(input[i]==ch[j])
                {
                    res+=(numpad[j]*pow(count,strlen(input)-i-1));
                }
            }
        }
        printf("case #%d:\n%d\n",t,res);
        t++;
    }
    return 0;
}

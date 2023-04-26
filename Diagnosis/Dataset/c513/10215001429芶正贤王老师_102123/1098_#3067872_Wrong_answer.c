#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[105];
        scanf("%s",s);
        int n,num,left;
        n=strlen(s);
        int number[4]={0};
        int wrong[4]={0};
        char mark[4];
        //统计4种灯的个数
        num=n/4;
        left=n%4;
        number[0]=num;
        number[1]=num;
        number[2]=num;
        number[3]=num;
        for(int j=0;j<left;j++)
        {
            number[j]+=1;
        }
        //统计坏的个数
        for(int j=0;j<n;j++)
        {
            if(j%4 == 0)
            {
                if(s[j]=='!')
                    wrong[0]++;
                else
                    mark[0]=s[j];
            }
            
            else if(j%4 == 1)
            {
                if(s[j]=='!')
                    wrong[1]++;
                else
                    mark[1]=s[j];
            }
                   
            else if(j%4 == 2)
            {
                if(s[j]=='!')
                    wrong[2]++;
                else
                    mark[2]=s[j];
            }
            else if(j%4 == 3)
            {
                if(s[j]=='!')
                    wrong[3]++;
                else
                    mark[3]=s[j];
            }
            
            
        }
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='R')
                printf("%d ",wrong[r]);
        }
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='B')
                   printf("%d ",wrong[r]);
        }
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='Y')
                   printf("%d ",wrong[r]);
        }
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='G')
                   printf("%d",wrong[r]);
        }
        printf("\n");
        
    }
    return 0;
    
    
}




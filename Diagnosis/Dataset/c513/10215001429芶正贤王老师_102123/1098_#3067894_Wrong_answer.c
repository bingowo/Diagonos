#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[105];
        scanf("%s",s);
        int n;
        n=strlen(s);
        
        int wrong[4]={0};
        char mark[4];
        
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
        
        
        int find=0;
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='R')
            {
                printf("%d ",wrong[r]);
                find=1;
            }
        }
        if(find==0)
            printf("? ");
        
        
        find=0;
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='B')
            {
                printf("%d ",wrong[r]);
                find=1;
            }   
        }
        if(find==0)
            printf("? ");
        
        
        find=0;
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='Y')
            {
                printf("%d ",wrong[r]);
                find=1;
            }
        }
        if(find==0)
            printf("? ");
        
        
        find=0;
        for(int r=0;r<4;r++)
        {
            if(mark[r]=='G')
            {
                printf("%d",wrong[r]);
                find=1;
            }
                   
        }
        if(find==0)
            printf("?");
        printf("\n");
        
    }
    return 0;
    
    
}
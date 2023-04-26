#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char s[100],c,nums[100];
    double x=0,b=0;
    int flag=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            c=s[i];
            break;
        }
    }
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='=') flag=1;
        if(i==0)
        {
            if(s[0]==c)
            {
                x++;
                continue;
            }
            else
            {
                int j=1;
                while(isalnum(s[j])&&j<strlen(s)) j++;
                if(isalpha(s[j-1]))
                {
                    if(s[j-2]=='-')
                    {
                        x-=1;
                        continue;
                    }
                    if(s[j-2]=='+')
                    {
                        x+=1;
                        continue;
                    }
                    for(int p=0;p<j;p++)  nums[p]=s[p];
                    nums[j-1]='\0';
                    x+=atoi(nums);
                }
                else
                {
                    for(int p=0;p<j;p++)  nums[p]=s[p];
                    nums[j]='\0';
                    b-=atoi(nums);
                }
                i=j-1;
                continue;
            }
        }
        if(flag==0)
        {
        if(s[i]=='+'||s[i]=='-')
        {
            int j=i+1;
            while(isalnum(s[j])&&j<strlen(s)) j++;
            if(isalpha(s[j-1]))
            {
                if(s[j-2]=='-')
                {
                    x-=1;
                    continue;
                }
                if(s[j-2]=='+')
                {
                    x+=1;
                    continue;
                }
                int count=0;
                for(int p=i;p<j;p++)  nums[count++]=s[p];
                nums[count]='\0';
                x+=atoi(nums);
            }
            else
            {
                int count=0;
                for(int p=i;p<j;p++)  nums[count++]=s[p];
                nums[count]='\0';
                b-=atoi(nums);
            }
            i=j-1;
            continue;
        }
        }
        else
        {
        if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            if(s[i]=='=') i++;
            int j=i+1;
            while(isalnum(s[j])&&j<strlen(s)) j++;
            if(isalpha(s[j-1]))
            {
                if(s[j-2]=='-')
                {
                    x+=1;
                    continue;
                }
                if(s[j-2]=='+')
                {
                    x-=1;
                    continue;
                }
                int count=0;
                for(int p=i;p<j;p++)  nums[count++]=s[p];
                nums[count]='\0';
                x-=atoi(nums);
            }
            else
            {
                int count=0;
                for(int p=i;p<j;p++)  nums[count++]=s[p];
                nums[count]='\0';
                b+=atoi(nums);
            }
            i=j-1;
            continue;
        }
        }
    }
    printf("%c=%.3lf",c,b/x);
}

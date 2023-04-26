#include<stdio.h>
#include<string.h>

void reverse(char*s)
{
    int l=strlen(s);
    for(int i=0;i<=(l-1)/2;i++)
    {
        char p=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=p;
    }
    s[l]='\0';
}

int find_9(char *s)
{
    int flag=1;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='9')
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int  find1_9(char *s)
{
    int l=strlen(s);
    int i;
    for(i=0;i<l;i++)
    {
        if(s[i]=='9') break;
    }
    return i;
}

int main()
{
    char s[1007]，ss[1007];
    int i,j,k,t,m,tmp,len,sum;
    scanf("%s",s);
    len=strlen(s);
    reverse(s);
    s[0]++;
    m=0;
    for(i=0,sum=0;i<len;i++)
    {
        tmp=s[i]-'0'+m;
        s[i]=tmp%10+'0';
        m=tmp/10;
        sum+=s[i]-'0';
    }
    while(m)
    {
        s[len++]=m%10+'0';
        sum+=s[len-1]-'0';
        m/=10;
    }
    s[len]='\0';
     if(find_9(s) &&sum%9!=0)
    {
        reverse(s);
        printf("%s\n",s);
    }
    else
    {
        while(1)
        {
            if(find_9(s)&&sum%9!=0)
            {
                reverse(s);
                printf("%s\n",s);
                break;
            }
            else if(find_9(s)==0)
            {
                k=find1_9(s);
                s[k]++;
                for(j=0;j<k;j++) s[j]='0';//位数更小的都变成0了
                for(j=0,sum=0;j<len;j++)
                {
                    tmp=s[j]-'0'+m;
                    s[j]=tmp%10+'0';
                    m=tmp/10;
                    sum+=s[j]-'0';
                }
                while(m)
                {
                    s[len++]=m%10+'0';
                    sum+=ss[len-1]+'0';
                    m/=10;
                }
                s[len]='\0';
                if(find_9(s)&&sum%9!=0)
                {
                    reverse(s);
                    printf("%s\n",s);
                    break;
                }
            }
            else if(sum%9==0)
            {
                s[0]++;
                for(i=0,sum=0;i<len;i++)
                {
                    tmp=s[i]-'0'+m;
                    s[i]=tmp%m+'0';
                    m=tmp/10;
                    sum+=s[i]-'0';
                }
                while(m)
                {
                    s[len++]=m%10+'0';
                    sum+=s[len-1]-'0';
                    m/=10;
                }
                s[len='0'];
            }
        }
    }
    return 0;
}

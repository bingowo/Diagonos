#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    char s[100],nums[20];
    for(int i=0;i<20;i++) nums[i]='\0';
    scanf("%s",s);
    int a=1000,b=1000,c=1000;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='x'&&s[i+1]=='^')
        {
            if(i==0)
            {
                a=1;
                continue;
            }
            if(s[0]=='-')
            {
                a=-1;
                continue;
            }
            for(int j=0;j<i;j++)
            {
                nums[j]=s[j];
            }
            nums[i]='\0';
            a=atoi(nums);
            continue;
        }
        if(s[i]=='x'&&s[i+1]!='^')
        {
            if(s[i-1]=='-')
            {
                b=-1;
                continue;
            }
            if(s[i-1]=='+')
            {
                b=1;
                continue;
            }
            int flag,count=0;
            for(int j=i-1;j>=0;j--)
            {
                if(s[j]<'0'||s[j]>'9')
                {
                    flag=j+1;
                    if(s[j]=='-') flag=j;
                    break;
                }
            }
            for(int j=flag;j<i;j++)
            {
                nums[count++]=s[j];
            }
            nums[count]='\0';
            b=atoi(nums);
            continue;
        }
        if((s[i]>='0'&&s[i]<='9')&&(i+1==strlen(s)&&s[i-1]!='^'))
        {
            int flag,count=0;
            for(int j=i-1;j>=0;j--)
            {
                if(s[j]<'0'||s[j]>'9');
                {
                    flag=j+1;
                    if(s[j]=='-') flag=j;
                    if(j==0) flag=0;
                    break;
                }
            }
            for(int j=flag;j<=i;j++)
            {
                nums[count++]=s[j];
            }
            nums[count]='\0';
            c=atoi(nums);
        }
    }
    if(a==1000) a=0;
    if(b==1000) b=0;
    if(c==1000) c=0;
    int delt=b*b-4*a*c,a1,a2,c1,c2;
    int x1=(-b+sqrt(delt))/(2*a),x2=(-b-sqrt(delt))/(2*a);
    printf("%d %d\n",x1,x2);
    if(delt<0)
    {
        printf("No Answer！");
        return 0;
    }
    if(delt>=0)
    {
        for(int i=1;i<=a;i++)
        {
            if(a%i!=0) continue;
            a1=i;
            a2=a/i;
            c1=-a1*x1;
            c2=-a2*x2;
            if(c1*c2==c&&a1*c2+a2*c1==b)
            {
                int t;
                if(a1>a2)
                {
                    t=a1;
                    a1=a2;
                    a2=t;
                    t=c1;
                    c1=c2;
                    c2=t;
                }
                if(a1==a2&&c1>c2)
                {
                    t=c1;
                    c1=c2;
                    c2=t;
                }
                break;
            }
        }
        printf("%d %d %d %d",a1,c1,a2,c2);
    }

}
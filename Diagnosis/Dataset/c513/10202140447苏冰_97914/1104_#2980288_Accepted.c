#include <stdio.h>
#include <string.h>
char table[][5]={"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
int a[30];
int main()
{
    char s[30],s1[10],s2[10],s3[10],s4[10];
    int temp=0,flag=0,sign=0;
    while(gets(s))
    {
        flag=0;sign=0;
        int i=0, k=0;
        while(s[i]!=' ')
        {
            s1[k++]=s[i];
            i++;
        }
        s1[k]='\0';
        k=0;i++;
        while(s[i]!=',' && s[i]!='\0')
        {
            s2[k++]=s[i];
            i++;
        }
        s2[k]='\0';
        k=0;
        if(s[i]!='\0')
        {
            i++;
            while(s[i]!=',' && s[i]!='\0')
            {
                s3[k++]=s[i];
                i++;
            }
            s3[k]='\0';
            k=0;
            if(s[i]!='\0')
            {
                i++;
                flag=1;
                while(s[i]!='\0')
                {
                    s4[k++]=s[i];
                    i++;
                }
                s4[k]='\0';
            }
        }
        for(int j=0;j<12;j++)
        {
            if(strcmp(table[j],s1)==0)
            {
                temp=j;
                break;
            }
        }
        int ans=0,j=0,t=0;
        switch(temp)
        {
            case 0:
                if(s3[0]=='-')
                {
                    sign=1;
                    j=1;
                }
                for(int i=j;i<strlen(s3);i++)
                {
                    ans=ans*10+(s3[i]-'0');
                }
                if(sign) ans*=-1;
                a[s2[0]-'A']=ans;
                break;
            case 1:
                printf("%d\n",a[s2[0]-'A']);
                break;
            case 2:
                a[s2[0]-'A']=a[s3[0]-'A'];
                break;
            case 3:
                t=a[s2[0]-'A'];
                a[s2[0]-'A']=a[s3[0]-'A'];
                a[s3[0]-'A']=t;
                break;
            case 4:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']+a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']+=a[s3[0]-'A'];
                }
                break;
            case 5:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']-a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']-=a[s3[0]-'A'];
                }
                break;
            case 6:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']*a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']*=a[s3[0]-'A'];
                }
                break;
            case 7:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']/a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']/=a[s3[0]-'A'];
                }
                break;
            case 8:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']%a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']%=a[s3[0]-'A'];
                }
                break;
            case 9:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']&a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']&=a[s3[0]-'A'];
                }
                break;
            case 10:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']|a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']|=a[s3[0]-'A'];
                }
                break;
            case 11:
                if(flag)
                {
                    a[s2[0]-'A']=a[s3[0]-'A']^a[s4[0]-'A'];
                }
                else
                {
                    a[s2[0]-'A']^=a[s3[0]-'A'];
                }
                break;
        }
    }
    return 0;
}

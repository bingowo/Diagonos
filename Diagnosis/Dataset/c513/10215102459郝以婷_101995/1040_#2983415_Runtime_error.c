#include <stdio.h>
#include <string.h>

int main()
{
    char m[3]={0},f[3]={0},b[3]={0},c[2]={0},if2=1;
    int s[4]={0},len1,len2,i,j,if1=0,len;
    scanf("%s %s",f,m);
    scanf("%s",b);
    len1=strlen(f);
    len2=strlen(m);
    if(b[0]=='?')
    {
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(f[i]==m[j]&&m[j]!='O')
                    s[f[i]-'A']=f[i];
                else if(f[i]==m[j]&&m[j]=='O')
                    s[3]='O';
                else if(f[i]=='O')
                    s[m[j]-'A']=m[j];
                else if(m[j]=='O')
                    s[f[i]-'A']=f[i];
                else
                    s[2]=1;
            }
        }
        if(len1!=2&&len2!=2)
        {
            s[3]='O';
        }
        if(len1+len2==3)
        {
            s[1]='B';
            s[0]='A';
        }
        printf("%s %s",f,m);
        printf(" {");
        for(i=0;i<4;i++)
        {
            if(s[i]==0)
               continue;
            if(if1!=0)
                printf(",");
            if(i!=2)
                printf("%c",s[i]);
            else
                printf("AB");
            if1=1;
        }
        printf("}");
    }
    else
    {
        if(f[0]=='?')
        {
            strcpy(c,m);
            len=len2;
        }
        else
        {
            strcpy(c,f);
            len=len1;
        }
        if(b[0]=='B')
        {
            if(c[0]=='A'&&len==1)
            {
                s[1]='B';
                s[2]=1;
            }
            else if(len==2)
            {
                s[0]='A';
                s[1]='B';
                s[2]=1;
                s[3]='0';
            }
            else if(c[0]=='B')
            {
                s[0]='A';
                s[1]='B';
                s[2]=1;
                s[3]='0';
            }
            else if(c[0]=='O')
            {
                s[1]='B';
                s[2]=1;
            }
        }
        else if(b[0]=='O')
        {
            if(len!=2)
            {
                s[0]='A';
                s[1]='B';
                s[3]='O';
            }
            else
                if2=0;
        }
        else if(b[0]=='A'&&b[1]=='B')
        {
            if(c[0]=='A'&&len==1)
            {
                s[1]='B';
                s[2]=1;
            }
            else if(c[0]=='B')
            {
                s[0]='A';
                s[2]=1;
            }
            else if(len==2)
            {
                s[0]='A';
                s[1]='B';
                s[2]=1;
            }
            else
                if2=0;
        }
        else
        {
            if(c[0]=='B'&&len==1)
            {
                s[0]='A';
                s[2]=1;
            }
            else if(len==2)
            {
                s[0]='A';
                s[1]='B';
                s[2]=1;
                s[3]='0';
            }
            else if(c[0]=='A')
            {
                s[0]='A';
                s[1]='B';
                s[2]=1;
                s[3]='0';
            }
            else if(c[0]=='O')
            {
                s[0]='A';
                s[2]=1;
            }
        }
        if(f[0]=='?')
        {
            if(if2==0)
                printf("imposible");
            else
            {
                printf("{");
                for(i=0;i<4;i++)
                {
                    if(s[i]==0)
                       continue;
                    if(if1)
                        printf(",");
                    if(i!=2)
                        printf("%c",s[i]);
                    else
                        printf("AB");
                    if1=1;
                }
                printf("}");
            }
            printf(" %s %s",m,b);
        }
        else
        {
            printf("%s",f);
            if(if2==0)
                printf(" imposible");
            else
            {
                printf(" {");
                for(i=0;i<4;i++)
                {
                    if(s[i]==0)
                       continue;
                    if(if1)
                        printf(",");
                    if(i!=2)
                        printf("%c",s[i]);
                    else
                        printf("AB");
                    if1=1;
                }
                printf("}");
            }
            printf(" %s",b);
        }
    }
    return 0;
}

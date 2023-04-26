#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,aflag=1,flag=0,bflag=1;
    long long int a=0,b=0,qa,qb;
    char *s=(char*)malloc(sizeof(char)*(1e8+4));
    char *di;
    char *r=(char*)malloc(sizeof(char)*1000);
    memset(r,'\0',strlen(r));
    scanf("%s",s);
    di=strchr(s,'i');
    if(di==NULL)  flag=1;
    else if (strchr(s+1,'+')!=NULL||strchr(s+1,'-')!=NULL) flag =2;
    else flag = -1;
    switch(flag){
        case 1:
        {
            if(s[0]=='-') aflag=-1;
            for(i=(aflag==1?0:1);i<strlen(s);i++)
            {
                a=a*10+(s[i]-'0');
            }
            a=aflag*a;b=0;
            break;
        }
        case -1:
        {
            b=1;
            if(s[0]=='-') 
            {bflag=-1;}
            if(s[1]!='i'&&s[0]!='i')b=0; 
            for(i=(bflag==1?0:1);i<strlen(s)-1;i++)
            {
                b=b*10+(s[i]-'0');
            }
            b=bflag*b;a=0;
            break;
        }
        case 2:
        {
            b=1;
            int f=1;
            // printf("%c",s[0]);
            if(s[0]=='-') aflag=-1;
            for(i=(aflag==-1?1:0);i<strlen(s)-1;i++)
            {
                if (s[i]=='-'||s[i]=='+')
                {
                    // printf("%c",s[i]);
                    f=0;
                    if(s[i]=='-') bflag=-1;
                    if(s[i+1]!='i') b=0;
                    continue;
                }
                if (f==0)
                {
                    b=b*10+(s[i]-'0');
                }
                if(f!=0)
                {
                    a=a*10+(s[i]-'0');
                }
            }
            a=aflag*a;b=bflag*b;
            break;
        }
        
    }
    // printf("%lld %lld",a,b);
    i=0;
    qa=a;
    qb=b;
    while ((b!=0)||(a!=0))
    {
        qa=a;
        qb=b;
        if((qa+qb)%2==0) r[i++]='0';
        else r[i++]='1';
        if((qb==1)&&(qa==0) ) 
        {
            a=1;b=0;
        }
        else
        {
            a=(qb-qa)/2;
            b=(-qb-qa)/2;
        }
       
    }
    for (i=strlen(r)-1;i>=0;i--)
    {
        printf("%c",r[i]);
    }
    free(s);
    free(r);
    system("pause");
    return 0;
}
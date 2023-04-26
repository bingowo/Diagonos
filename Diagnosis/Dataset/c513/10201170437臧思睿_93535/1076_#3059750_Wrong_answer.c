#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a=0,b=0,c=0,i=0,flag=0;
        char s[105];
        scanf("%s",s);
        s[strlen(s)]='\0';
        while(i<strlen(s)&&a>=0&&b>=0&&c>=0)
        {
            switch(s[i])
            {
                case'(':a++;break;
                case'[':b++;break;
                case'{':c++;break;
                case')':a--;break;
                case']':b--;break;
                case'}':c--;break;
            }
            i++;
        }
        if(a!=0 || b!=0 || c!=0)
        {
            flag=1;
            printf("%s\n","No");
        }
        for(i=0;i<strlen(s)-1;i++)
        {
            if(s[i]=='('&&(s[i+1]!=')'&&s[i+1]!='{'))
            {
                flag=1;
                printf("%s\n","No");
                break;
            }
            if(s[i]=='['&&s[i+1]!='(')
            {
                flag=1;
                printf("%s\n","No");
                break;
            }
            if(s[i]=='{'&&s[i+1]!='[')
            {
                flag=1;
                printf("%s\n","No");
                break;
            }
        }
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]==')'&&(s[i-1]!='('&&s[i-1]!='}'))
            {
                flag=1;
                printf("%s\n","No");
                break;
            }
            if(s[i]=='}'&&s[i-1]!=']')
            {
                flag=1;
                printf("%s\n","No");
                break;
            }
            if(s[i]==']'&&s[i-1]!=')')
            {
                flag=1;
                printf("%s\n","No");
                break;
            }
        }

        if(a==0 && b==0 && c==0 && flag==0)
        {
            printf("%s\n","Yes");
        }
    }
    return 0;
}

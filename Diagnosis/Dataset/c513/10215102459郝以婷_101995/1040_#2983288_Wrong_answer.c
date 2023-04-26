#include <stdio.h>
#include <string.h>

int main()
{
    char m[2],f[2],b[2];
    int s[4]={0},len1,len2,i,j,if1=0;
    scanf("%s %s %s",f,m,b);
    len1=strlen(f);
    len2=strlen(m);
    if(b[0]=='?')
    {
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(f[i]==m[j])
                    s[f[i]-'A']=f[i];
                else if(f[i]=='O')
                    s[m[j]-'A']=m[j];
                else if(m[j]=='O')
                    s[f[i]-'A']=f[i];
                else
                    s[2]=1;
            }
        }
        if(len1!=2&&len2!=2)
            s[3]='O';
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

    return 0;
}

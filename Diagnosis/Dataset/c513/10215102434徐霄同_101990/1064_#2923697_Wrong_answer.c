#include <stdio.h>
#include <string.h>
int main()
{
    char s[101],fh[101];
    int i,j,t,l,n,m,p;
    float x,d;
    float num[100];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        j=0;
        n=0;
        m=0;
        p=0;
        while(j<l){
            if(s[j]==' ')
                j++;
            else if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'){
                fh[n]=s[j];
                n++;
                j++;
                p=0;
            }
            else{
                x=0;
                while(j<l&&s[j]!='.'&&s[j]!=' '){
                    x=x*10+s[j]-'0';
                    j++;
                }
                if(s[j]=='.'){
                    j++;
                    d=0.1;
                    while(j<l&&s[j]!=' '){
                        x=x+d*(s[j]-'0');
                        j++;
                        d=d/10;
                    }
                }
                num[m]=x;
                m++;
                p++;
                if(p==2){
                    n--;
                    m--;
                    if(fh[n]=='+')
                        num[m-1]=num[m-1]+num[m];
                    else if(fh[n]=='-')
                        num[m-1]=num[m-1]-num[m];
                    else if(fh[n]=='*')
                        num[m-1]=num[m-1]*num[m];
                    else
                        num[m-1]=num[m-1]/num[m];
                    p=1;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%.6f\n",num[0]);
    }
    return 0;
}
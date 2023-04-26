#include <stdio.h>
#include <string.h>
int main()
{
    char s[101],fh[101];
    int i,j,t,l,n,p;
    float x,d;
    float num[2];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        j=0;
        n=0;
        p=0;
        while(j<l){
            if(s[j]==' ')
                j++;
            else if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'){
                fh[n]=s[j];
                n++;
                j++;
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
                num[p]=x;
                p++;
                if(p==2){
                    n--;
                    if(fh[n]=='+')
                        num[0]=num[0]+num[1];
                    else if(fh[n]=='-')
                        num[0]=num[0]-num[1];
                    else if(fh[n]=='*')
                        num[0]=num[0]*num[1];
                    else
                        num[0]=num[0]/num[1];
                    p=1;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%.6f\n",num[0]);
    }
    return 0;
}

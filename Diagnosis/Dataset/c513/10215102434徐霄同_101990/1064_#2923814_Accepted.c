#include <stdio.h>
#include <string.h>
int main()
{
    char s[101];
    int i,j,t,l,n;
    float x,d;
    float a[100][2];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        j=0;
        n=0;
        while(j<l){
            if(s[j]==' ')
                j++;
            else if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'){
                a[n][0]=s[j];
                a[n][1]=1;
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
                a[n][0]=x;
                a[n][1]=0;
                n++;
            }
            if(a[n-1][1]==0&&a[n-2][1]==0){
                if((char)a[n-3][0]=='+')
                    a[n-3][0]=a[n-2][0]+a[n-1][0];
                else if((char)a[n-3][0]=='-')
                    a[n-3][0]=a[n-2][0]-a[n-1][0];
                else if((char)a[n-3][0]=='*')
                    a[n-3][0]=a[n-2][0]*a[n-1][0];
                else
                    a[n-3][0]=a[n-2][0]/a[n-1][0];
                a[n-3][1]=0;
                n=n-2;
            }
        }
        if(n==3){
            if((char)a[0][0]=='+')
                a[0][0]=a[1][0]+a[2][0];
            else if((char)a[0][0]=='-')
                a[0][0]=a[1][0]-a[2][0];
            else if((char)a[0][0]=='*')
                a[0][0]=a[1][0]*a[2][0];
            else
                a[0][0]=a[1][0]/a[2][0];
        }
        printf("case #%d:\n",i);
        printf("%.6f\n",a[0][0]);
    }
    return 0;
}

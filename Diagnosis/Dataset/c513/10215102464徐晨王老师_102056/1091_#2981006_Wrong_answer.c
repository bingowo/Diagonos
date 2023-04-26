#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    long long int a=0,b=0,c=0,d=0;
    int n;
    char s[20];
    scanf("%s",s);
    if(s[0]=='-')a=s[1]-48;
    else a=s[0]-48;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='i'){
            if(s[i-1]=='-')b=-1;
            else if(s[i-1]=='+')b=1;
            else{
                long long int e=1;
                for(int j=i-1;j>=0;j--){
                    if(s[j]=='+')break;
                    if(s[j]=='-'){b=-b;break;}
                    b=b+(s[j]-48)*e;
                    e=e*10;
                }

            }
        }

    }
    scanf("%d",&n);
    c=a;
    d=b;
    printf("%lld+%lldi%d",c,d,n);
    for(int i=0;i++;i<n){
        long long int e=c;
        c=a*c-b*d;
        d=a*d+b*e;
        printf("%lld+%lldi",c,d);
    }
    if(c!=0&&d>1){printf("%lld+%lldi",c,d);}
    if(c!=0&&d==1){printf("%lld+i",c);}
    if(c!=0&&d<-1){printf("%lld%lldi",c,d);}
    if(c!=0&&d==-1){printf("%lldi",c);}
    if(c==0&&d!=0){printf("%lldi",d);}
    if(c!=0&&d==0){printf("%lld",c);}
    return 0;
}

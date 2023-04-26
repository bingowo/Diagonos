#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s0[8]={'I','V','X','L','C','D','M'};
    int arr0[7]={1,5,10,50,100,500,1000};
    char s[51];
    scanf("%s",s);
    int length=strlen(s);
    int i=0;
    long long int ans=0,n=1;
    while(i<length){
        long long int x=0,y=0;
        if(isalpha(s[i])){
            for (int j=0;j<7;j++){
                if(s[i]==s0[j]) {x=arr0[j];break;}
            }
            if(s[i]=='I'||s[i]=='X'||s[i]=='C'){
                if((i<length-1)&&isalpha(s[i+1])){
                    for (int j=0;j<7;j++){
                        if(s[i+1]==s0[j]) {y=arr0[j];break;}
                    }
                    if((y>x)&&(y/x<=10)){
                        i+=2;
                        ans=ans+(y-x)*n;
                    }
                    else {
                        ans+=(x*n);
                        i++;
                    }
                }
                else if(i==length-1){
                    ans+=(x*n);
                    i++;
                }
                else if(s[i+1]=='('){
                    ans+=(-1)*(x*n);
                    i++;
                }
                else if(!isalpha(s[i+1])){
                    ans+=(x*n);
                    i++;
                }
            }
            else if (s[i+1]=='('){
                    ans+=(-1)*(x*n);
                    i++;
            }
            else if(isalpha(s[i])){
                ans+=(x*n);
                i++;
            }
        }
        else if(isalpha(s[i])){
                ans+=(x*n);
                i++;
            }
        else if(s[i]=='('){
            n*=1000;
            i++;
        }
        else if(s[i]==')'){
            n/=1000;
            i++;
        }
    }
    printf("%lld",ans);
    return 0;
}

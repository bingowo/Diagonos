#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char a[10009];
    char c;
    char s[10009];
    int k=0;
    while((c=getchar())!=EOF){
        s[k++]=c;
    }
    int flag=0;
    k=0;
    for(int i=0;s[i];i++){
        if(s[i]=='/'&&s[i+1]=='/'){
            if(flag==1)a[k++]=s[i];
            else{
                flag=2;
                i++;
            }
        }
        else if(s[i]=='\n'){
            if(flag==2){
                a[k++]=s[i];
                flag=0;
            }
            else if(flag==1||flag==0)a[k++]=s[i];
        }
        else if(s[i]=='\"'&&s[i-1]!='\\'){
            a[k++]=s[i];
            if(flag==1)flag=0;
            else flag=1;
        }
        else if(s[i]=='/'&&s[i+1]=='*'){
            if(flag==1)a[k++]=s[i];
            else{
                flag=3;
                i++;
            }
        }
        else if(s[i]=='*'&&s[i+1]=='/'&&flag==3){
            flag=0;
            i++;
        }
        else if(flag==0||flag==1)a[k++]=s[i];
    }
    a[k]=0;
    printf("%s",a);
    return 0;
}

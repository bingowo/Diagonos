#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int table[130];

char str[100]={0};

int judge(char s[])
{
    int q=0;
    int len=strlen(s),pair=1;
    char c=s[0],m;
    for(int j=1;j<len;j++){

        switch(s[j]){
        case '(':
            if(c!='['){
                return 1;
               }
            else{
                str[q++]='(';
                c=s[j];
                pair++;
            }
            break;
        case '[':
            if(c!='{'){
                return 1;
               }
            else{
                str[q++]='[';
                c=s[j];
                pair++;
            }
            break;
        case '{':
            if(c!='('){
                return 1;
               }
            else{
                str[q++]='{';
                c=s[j];
                pair++;
            }
            break;
        case ')':
            m=strchr(str,'(');
            if(m==NULL){
                return 1;
               }
            else{
                //*m='1';
                c=s[j];
                pair--;
            }
            break;
        case ']':
            m=strchr(str,'[');
            if(m==NULL){
                return 1;
               }
            else{
                //*m='1';
                c=s[j];
                pair--;
            }
            break;
        case '}':

            m=strchr(str,'{');
            if(m==0){
                return 1;
               }
            else{
                //*m='1';
                c=s[j];
                pair--;
            }
            break;

        }
    }
    if(pair!=0)return 1;
    return 0;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[100];
        scanf("%s",s);
        int flag=judge(s);
        if(flag==1)printf("No\n");
        else{
            printf("Yes\n");
        }
    }
    return 0;
}

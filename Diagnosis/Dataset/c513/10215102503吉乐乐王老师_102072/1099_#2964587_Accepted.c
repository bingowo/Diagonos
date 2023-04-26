#include<stdio.h>
#include<string.h>
char *albet[26]={".-","-...","-.-.","-..",".","..-.",
"--.","....","..",".---","-.-",".-..","--","-.","---",
".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
"-.--","--.."};
char *alnum[10]={"-----",".----","..---","...--",
"....-",".....","-....","--...","---..","----."};
void decode(char *s,char *ret);
char findch(char *temp);
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[1001];
        scanf("%s",s);getchar();
        char ret[1001];
        decode(s,ret);
        printf("case #%d:\n%s\n",cas++,ret);
    }
}
char findch(char*temp){
    for(int i=0;i<26;i++){
        if(strcmp(temp,albet[i])==0)return i+'A';
    }
    for(int i=0;i<10;i++){
        if(strcmp(temp,alnum[i])==0)return i+'0';
    }
    return 0;
}
void decode(char*s,char*ret){
    int idx=0;
    char *p=s;
    char temp[1001];char *pt=temp;
    int cnt=0;
    while(*p){
        if(*p=='/'){
            *pt='\0';
            ret[idx++]=findch(temp);
            pt=temp;
            cnt+=1;p++;
            while(*p=='/'){p++;cnt++;}
            switch (cnt)
            {
            case 3:
                ret[idx++]=' ';
                break;
            case 5:
                ret[idx++]='.';
                break;
            default:
                break;
            }
            cnt=0;
        }
        *pt=*p;
        p++;pt++;
    }
    *pt='\0';
    ret[idx++]=findch(temp);
    ret[idx]='\0';
    return;
}
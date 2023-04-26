#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);getchar();
    char *dic[4000];
    for(int i=0;i<n;i++){
        char temp[15];
        gets(temp);
        dic[i]=(char*)malloc(strlen(temp)+1);
        strcpy(dic[i],temp);
    }
    char s[5001];
    gets(s);
    char *ret[4000];int ri=0;
    while(strlen(s)>0){
        int end=strlen(s);int flag=0;
        while(end>0){
            char ss[5001];
            strcpy(ss,s);
            ss[end]='\0';
            for(int i=0;i<n;i++){
                if(strcmp(ss,dic[i])==0){
                    flag=1;break;
                }
            }
            if(flag)break;
            end--;
        }
        if(flag){
            char str[5001];
            strcpy(str,s);
            str[end]='\0';
            ret[ri]=(char*)malloc(strlen(str)+1);
            strcpy(ret[ri],str);ri++;
            if(s[end]!='\0'){
                strcpy(str,s+end);
                strcpy(s,str);}
            else s[0]='\0';
        }
        else{
            ret[ri]=(char*)malloc(2);
            ret[ri][0]=s[0];
            ret[ri][1]='\0';
            ri++;
            if(strlen(s)>1){
                char temp[5001];
                strcpy(temp,s+1);
                strcpy(s,temp);}
            else s[0]='\0';
        }
    }
    for(int i=0;i<ri;i++){
        printf("%s",ret[i]);
        if(i==ri-1)putchar('\n');
        else putchar(' ');
    }
}
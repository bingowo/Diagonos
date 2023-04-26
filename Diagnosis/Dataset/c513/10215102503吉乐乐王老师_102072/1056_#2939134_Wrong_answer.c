#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return strlen(*(char**)a)<strlen(*(char**)b)?1:-1;
}
int main(){
    int n;
    scanf("%d",&n);getchar();
    char **dic=(char**)malloc(sizeof(char*)*4001);
    for(int i=0;i<n;i++){
        dic[i]=(char*)malloc(sizeof(char)*15);
        scanf("%s",dic[i]);
    }
    qsort(dic,n,sizeof(dic[0]),cmp);
    char *s=(char*)malloc(5001);
    scanf("%s",s);
    char **ret=(char**)malloc(sizeof(char*)*5001);
    int ri=0;
    while(strlen(s)>0){
        int end=strlen(s);
        int flag=0;
        char *ss=(char*)malloc(strlen(s)+1);
        strcpy(ss,s);
        if(strlen(ss)>strlen(dic[0])){
            end=strlen(dic[0]);
            ss[end]='0';
        }
        while(end>0){
            int idx=0;
            while(idx<n){
                if(strcmp(ss,dic[idx])==0){
                    ret[ri]=(char*)malloc(strlen(dic[idx])+1);
                    strcpy(ret[ri],dic[idx]);
                    ri++;
                    flag=1;break;
                }
                else idx++;
            }
            if(flag)break;
            end--;
            ss[end]='\0';
        }
        if(flag)s+=end;
        else{
            ret[ri]=(char*)malloc(2);
            ret[ri][0]=s[0];
            ret[ri][1]='\0';
            ri++;
            s=s+1;
        }
    }
    for(int i=0;i<ri;i++){
        printf("%s",ret[i]);
        if(i==ri-1)putchar('\n');
        else putchar(' ');
    }
}
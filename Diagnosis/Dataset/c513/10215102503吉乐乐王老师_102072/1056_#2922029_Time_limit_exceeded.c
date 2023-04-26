#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return strlen((char*)a)<strlen((char*)b)?1:-1;
}
int main(){
    int n;
    scanf("%d",&n);getchar();
    char dic[4001][15];
    for(int i=0;i<n;i++){
        gets(dic[i]);
    }
    qsort(dic,n,sizeof(dic[0]),cmp);
    char *s=(char*)malloc(5001);
    gets(s);
    char ret[5001][15];int ri=0;
    while(strlen(s)>0){
        int end=strlen(s);int flag=0;char *str;
        char *ss=(char*)malloc(strlen(s)+1);
        strcpy(ss,s);
        while(end>0){
            int idx=0;
            while(idx<n){
                if(strcmp(ss,dic[idx])==0){
                    str=(char*)malloc(strlen(dic[idx])+1);
                    strcpy(str,dic[idx]);
                    flag=1;break;
                }
                else idx++;
            }
            if(flag)break;
            end--;
            ss[end]='\0';
        }
        if(flag){
            strcpy(ret[ri],str);ri++;
            s=s+end;
        }
        else{
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
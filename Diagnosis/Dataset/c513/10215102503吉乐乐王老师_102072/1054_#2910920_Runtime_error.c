#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        int m;scanf("%d",&m);getchar();//每行排版长度
        char *s[100];int si=0;
        char temp[100];
        while(scanf("%s",temp)==1){
            s[si]=(char*)malloc(sizeof(temp)+1);
            strcpy(s[si],temp);si++;
            if(getchar()=='\n')break;
        }
        char *ret[100];int ri=0;
        int slen=si;si=0;
        while(slen>0){
            int start=0,end=m;
            ret[ri]=(char *)malloc(m+1);
            strcpy(ret[ri],s[si]);
            start=strlen(s[si]);
            si++;slen--;
            ret[ri][start]=' ';start+=1;
            ret[ri][start]='\0';
            while(end>start&&(end-start)>=strlen(s[si])&&slen>0){
                strcat(ret[ri],s[si]);
                start+=strlen(s[si]);
                if(start<end){
                    ret[ri][start]=' ';
                    start+=1;}
                ret[ri][start]='\0';
                si++;slen--;
            }
            while(start<end){
                ret[ri][start]=' ';start++;
            }
            ret[ri][start]='\0';
            ri++;
        }
        printf("case #%d:\n",cas++);
        for(int i=0;i<ri-1;i++){
            int wcnt=0,scnt=0;
            for(int j=0;j<strlen(ret[i]);j++){
                if(!isspace(ret[i][j])){
                    wcnt++;
                    while(!isspace(ret[i][j])&&j<strlen(ret[i]))j++;
                }
                if(isspace(ret[i][j])&&j<strlen(ret[i]))scnt++;
            }
            int llen=m;char *p=ret[i];
            while(llen){
                while(!isspace(*p)&&llen){
                    putchar(*p);
                    p++;llen--;
                }
                int k;
                for(k=0;llen&&k<scnt/(wcnt-1);k++){
                    putchar(' ');
                    llen--;}
                p++;
                if(wcnt>1){scnt-=scnt/(wcnt-1);
                    wcnt--;}
                else scnt-=k;
            }
            putchar('\n');
        }
        printf("%s\n",ret[ri-1]);
    }
}
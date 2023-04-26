#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void fix(int *state,char c,int tag){
    switch(c){
        case('R'):{state[0]+=tag;break;}
        case('B'):{state[1]+=tag;break;}
        case('Y'):{state[2]+=tag;break;}
        case('G'):{state[3]+=tag;break;}
    }
}
int badnum(char* s,int p,int* ans){
    int bad=0,badpos;
    for(int i=0;i<4;i++){
        if(!isalpha(s[i+p])) {
                bad++;badpos=i+p;
        }
    }
    if(bad==1) {
        int b[4]={0};
        for(int i=0;i<4;i++){
            switch(s[i+p]){
                case('R'):{b[0]++;break;}
                case('B'):{b[1]++;break;}
                case('Y'):{b[2]++;break;}
                case('G'):{b[3]++;break;}
            }
        }
        for(int i=0;i<4;i++){
            if(b[i]==0) {
                switch(i){
                    case(0):{s[badpos]='R';break;}
                    case(1):{s[badpos]='B';break;}
                    case(2):{s[badpos]='Y';break;}
                    case(3):{s[badpos]='G';break;}
                }
                ans[i]++;
            }
        }
    }
    return bad;
}

void left(char* s, int p, int* ans){
    while(p>0){
        char c=s[p+3];
        p--;
        if(s[p]=='!'){
            s[p]=c;
            fix(ans,c,1);
        }
    }
}

void right(char* s, int p, int* ans){
    while(p+4<strlen(s)){
        char c=s[p];
        p++;
        if(s[p+3]=='!'){
            s[p+3]=c;
            fix(ans,c,1);
        }
    }
}
int main(){
   int pro;scanf("%d",&pro);
   for(int index=0;index<pro;index++){
        int ans[4]={0};
        char s[120];scanf("%s",s);
        int p=0;
        for(;p<strlen(s) && badnum(s,p,ans)>1;p++);
        left(s,p,ans);
        right(s,p,ans);
        printf("case #%d:\n",index);
        printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
   }
}

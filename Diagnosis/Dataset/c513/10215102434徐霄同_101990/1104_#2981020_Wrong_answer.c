#include <stdio.h>
#include <string.h>
int main()
{
    char s1[5],s2[20],s3[3],s4[11],s5[3];
    int jc[26];
    int i,x,p;
    while(scanf("%s %s",s1,s2)!=EOF){
        if(strcmp(s1,"OUT")==0){
            printf("%d\n",jc[s2[0]-'A']);
        }
        else{
            p=0;
            for(i=0;i<strlen(s2);i++){
                if(s2[i]==','){
                    s2[i]=' ';
                    p++;
                }
            }
            if(strcmp(s1,"IN")==0){
                sscanf(s2,"%s%d",s3,&x);
                jc[s3[0]-'A']=x;
            }
            else if(strcmp(s1,"MOV")==0){
                sscanf(s2,"%s%s",s3,s4);
                jc[s3[0]-'A']=jc[s4[0]-'A'];
            }
            else if(strcmp(s1,"XCHG")==0){
                sscanf(s2,"%s%s",s3,s4);
                x=jc[s3[0]-'A'];
                jc[s3[0]-'A']=jc[s4[0]-'A'];
                jc[s4[0]-'A']=x;
            }
            else if(strcmp(s1,"ADD")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']+=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']+jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"SUB")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']-=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']-jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"MUL")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']*=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']*jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"DIV")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']/=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']/jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"MOD")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']%=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']%jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"AND")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']&=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']&jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"OR")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']|=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']|jc[s5[0]-'A'];
                }
            }
            else if(strcmp(s1,"XOR")==0){
                if(p==1){
                    sscanf(s2,"%s%s",s3,s4);
                    jc[s3[0]-'A']^=jc[s4[0]-'A'];
                }
                else{
                    sscanf(s2,"%s%s%s",s3,s4,s5);
                    jc[s3[0]-'A']=jc[s4[0]-'A']^jc[s5[0]-'A'];
                }
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
    char s1[4],s2[20],s3[3],s4[11];
    int jc[4]={0,0,0,0};
    int i,x;
    while(scanf("%s %s",s1,s2)!=EOF){
        if(strcmp(s1,"OUT")==0){
            printf("%d\n",jc[s2[0]-'A']);
        }
        else{
            i=0;
            while(s2[i]!=',')
                i++;
            s2[i]=' ';
            if(strcmp(s1,"IN")==0){
                sscanf(s2,"%s%d",s3,&x);
                jc[s3[0]-'A']=x;
            }
            else if(strcmp(s1,"MOV")==0){
                sscanf(s2,"%s%s",s3,s4);
                jc[s3[0]-'A']=jc[s4[0]-'A'];
            }
            else if(strcmp(s1,"ADD")==0){
                sscanf(s2,"%s%s",s3,s4);
                jc[s3[0]-'A']+=jc[s4[0]-'A'];
            }
            else if(strcmp(s1,"SUB")==0){
                sscanf(s2,"%s%s",s3,s4);
                jc[s3[0]-'A']-=jc[s4[0]-'A'];
            }
            else if(strcmp(s1,"MUL")==0){
                sscanf(s2,"%s%s",s3,s4);
                jc[s3[0]-'A']*=jc[s4[0]-'A'];
            }
            else if(strcmp(s1,"DIV")==0){
                sscanf(s2,"%s%s",s3,s4);
                jc[s3[0]-'A']/=jc[s4[0]-'A'];
            }
        }
    }
    return 0;
}

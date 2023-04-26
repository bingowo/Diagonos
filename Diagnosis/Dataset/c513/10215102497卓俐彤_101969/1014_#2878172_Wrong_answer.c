#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxstr 500



int main(){
    int A,B;
    scanf("%d %d",&A,&B);
    int num=0;
    char res[maxstr],r1[maxstr];
    for(int i=B;i>1;i/=3)num++;
    int i=0,i1=0;
    res[i++]='0';
    int a=A;
    while(A){
        r1[i1++]='0'+A%3;
        A/=3;
    }
    r1[i1]='\0';
    for(i1=0;i1<strlen(r1)-1;i1++){
        r1[i1]++;
        if(r1[i1]>='3'){
            r1[i1]-=3;
            r1[i1+1]++;
        }
    }
    for(;i1>=0;i1--)res[i++]=r1[i1];
    res[1]++;
    if(r1[strlen(r1)-1]>='2'){
        res[0]++;
        res[1]-=3;
    }
    res[i]='\0';
    int n=1;
    for(;n<strlen(res);n++){
        if(res[n]=='.')continue;
        if(res[n]=='0')res[n]='2';
        else res[n]--;
    }
    if(!a)printf("0");
    else{
        if(!num){
            if(res[0]-'0')printf("%c",res[0]);
            for(int j=1;j<strlen(res);j++)printf("%c",res[j]);
        }
        else{
            int j;
            if(strlen(res)>num){
                if(res[0]-'0')printf("%c",res[0]);
                else if(strlen(res)==num+1)printf("%c",res[0]);
                unsigned long int last=strlen(res)-1;
                while(res[last]=='0'&&last>strlen(res)-num-1)last--;
                for(j=1;j<strlen(res)-num;j++)printf("%c",res[j]);
                if(last>=strlen(res)-num){
                    printf(".");
                    for(;j<=last;j++)printf("%c",res[j]);
                }
            }else{
                printf("0.");
                for(int k=0;k<num-strlen(res);k++)printf("0");
                for(j=0;j<strlen(res);j++)printf("%c",res[j]);
            }
        }
    }
    printf("\n");
    return 0;
}

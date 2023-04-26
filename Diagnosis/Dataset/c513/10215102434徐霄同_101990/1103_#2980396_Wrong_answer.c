#include <stdio.h>
#include <string.h>
int f(char s[])
{
    int i,l,n;
    n=0;
    l=strlen(s);
    for(i=0;i<l;i++)
        n=n*10+s[i]-'0';
    return n;
}
int main()
{
    char s1[4],s2[20],s3[3],s4[11];
    char sjc[4][3]={"AX","BX","CX","DX"};
    int jc[4]={0,0,0,0};
    int i,j,l,x;
    while(scanf("%s %s",s1,s2)!=EOF){
        if(strcmp(s1,"OUT")==0){
            for(i=0;i<4;i++)
                if(strcmp(s2,sjc[i])==0)
                    printf("%d\n",jc[i]);
        }
        else{
            l=strlen(s2);
            memset(s3,0,sizeof(s3));
            memset(s4,0,sizeof(s4));
            i=0;
            while(s2[i]!=','){
                s3[i]=s2[i];
                i++;
            }
            i++;
            j=0;
            while(i<l){
                s4[j]=s2[i];
                i++;
                j++;
            }
            i=0;
            while(strcmp(sjc[i],s3)!=0)
                i++;
            j=0;
            while(j<4&&strcmp(sjc[j],s4)!=0)
                j++;
            if(strcmp(s1,"IN")==0){
                x=f(s4);
                jc[i]=x;
            }
            else if(strcmp(s1,"MOV")==0)
                jc[i]=jc[j];
            else if(strcmp(s1,"ADD")==0)
                jc[i]=jc[i]+jc[j];
            else if(strcmp(s1,"SUB")==0)
                jc[i]=jc[i]-jc[j];
            else if(strcmp(s1,"MUL")==0)
                jc[i]=jc[i]*jc[j];
            else if(strcmp(s1,"DIV")==0)
                jc[i]=jc[i]/jc[j];
        }
    }
    return 0;
}
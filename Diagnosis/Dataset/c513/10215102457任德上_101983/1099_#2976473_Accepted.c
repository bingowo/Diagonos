#include<stdio.h>
#include<malloc.h>
#include<string.h>
void transform(char *s,char *s1,char **p){
    if(*s==0){*s1=0;return;}
    if(*s=='/'&&*(s+1)=='/'&&*(s+2)=='/'&&*(s+3)=='/'&&*(s+4)=='/'){
        *s1='.';
        transform(s+5,s1+1,p);
        return;
    }
    if(*s=='/'&&*(s+1)=='/'&&*(s+2)=='/'){
        *s1=' ';
        transform(s+3,s1+1,p);
        return;
    }
    if(*s=='/'){transform(s+1,s1,p);return;}
    char x[6];
    int k=0;
    while(*s!='/'&&*s!=0){
        x[k++]=*s;
        s++;
    }
    x[k]=0;
    for(int i=48;i<58;i++){
        if(strcmp(x,p[i])==0){
            *s1=(char)i;
            transform(s,s1+1,p);
            return;
        }
    }
    for(int i=65;i<91;i++){
        if(strcmp(x,p[i])==0){
            *s1=(char)i;
            transform(s,s1+1,p);
            return;
        }
    }


}
int main(){
    int t;
    scanf("%d",&t);
    char *p[128];
    for(int i=48;i<58;i++)p[i]=(char*)malloc(6);
    for(int i=65;i<91;i++)p[i]=(char*)malloc(6);
    p['0']="-----",p['1']=".----",p['2']="..---",p['3']="...--",p['4']="....-",\
    p['5']=".....",p['6']="-....",p['7']="--...",p['8']="---..",p['9']="----.",\
    p['A']=".-",p['B']="-...",p['C']="-.-.",p['D']="-..",p['E']=".",\
    p['F']="..-.",p['G']="--.",p['H']="....",p['I']="..",p['J']=".---",\
    p['K']="-.-",p['L']=".-..",p['M']="--",p['N']="-.",p['O']="---",\
    p['P']=".--.",p['Q']="--.-",p['R']=".-.",p['S']="...",p['T']="-",\
    p['U']="..-",p['V']="...-",p['W']=".--",p['X']="-..-",p['Y']="-.--",\
    p['Z']="--..";
    for(int i=0;i<t;i++){
        char s[1001]={0},s1[1001]={0};
        scanf("%s",s);
        transform(s,s1,p);
        printf("case #%d:\n%s\n",i,s1);
    }
    return 0;
}
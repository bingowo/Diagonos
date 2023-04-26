#include<stdio.h>
#include<string.h>

char res[42][42]={};

void init(){
    for (int i=0; i<=40; i++){
        for (int j=0; j<=40; j++){
            res[i][j]='.';
        }   
    }
    for (int i=0; i<=40; i++){
        res[i][20]='|';
        res[20][i]='-';
    }
    res[20][20]='+';
    res[20][40]='>';
    res[0][20]='^';
    return;
}

void process(char s[], int cal[]){
    int slen=strlen(s), temp=0, fuhao=1;
    for (int i=5; i<slen; i++){
        if ('0'<=s[i] && s[i]<='9') {
            temp*=10; 
            temp+=s[i]-'0';
        }
        else if (s[i]=='x'){
            if (i+1<slen){
                if (s[i+1]=='^'){
                    cal[s[i+2]-'0']=temp*fuhao;
                    temp=0;
                    i+=2;
                }
                else {
                    cal[1]=temp*fuhao;
                    temp=0;   
                    i++;
                }
            }
            else {
                cal[1]=temp*fuhao;
                temp=0;   
            }
        }
        else {
            if (s[i]=='+') fuhao=1;
            else if (s[i]=='-') fuhao=-1;
        }
    }
    if (temp!=0) cal[0]=temp;
    return;
}
int f(int x, int cal[]){
    return cal[0]+cal[1]*x+cal[2]*x*x+cal[3]*x*x*x;
}
int main(){
    char s[30]={};
    while(scanf("%s", s)!=EOF){
        init();
        int cal[4]={0};
        process(s,cal);
        for (int i=-20; i<=20; i++){
            int temp = f(i, cal);
            if (-20<=temp && temp<=20) res[20-temp][i+20]='*';
        }
        for (int i=0; i<=40; i++) {
            for (int j=0; j<=40; j++){
                printf("%c", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
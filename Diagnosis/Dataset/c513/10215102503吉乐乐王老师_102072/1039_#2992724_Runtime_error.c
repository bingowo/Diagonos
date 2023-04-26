#include<stdio.h>
#include<string.h>
typedef struct 
{
    char var[10];
    int data[100];
    int nof;
}node;
int main(){
    int n;
    scanf("%d",&n);getchar();
    node arr[10];
    strcpy(arr[0].var,"none");
    for(int i=0;i<100;i++)arr[0].data[i]=0;
    int idx=1;
    while(n--){
        char s[151];
        gets(s);
        char nonech;
        char var[10]="none";int pi=0;
        int tmp[151]={0};int cnt=0;
        int out[151]={0};int oi=0;
        for(int i=strlen(s)-1;i>=0;i--){
            if(s[i]>='0'&&s[i]<='9')tmp[cnt++]=s[i]-'0';
            else if(s[i]==' ')continue;
            else if(s[i]>='a'&&s[i]<='z'){
                pi=0;
                while(s[i]>='a'&&s[i]<='z'&&i>=0){var[pi++]=s[i--];}
                var[pi]='\0';
            }
            else{
                switch (s[i])
                {
                case '=':
                    i-=2;//跳过空格
                    pi=0;
                    while(s[i]>='a'&&s[i]<='z'&&i>=0)var[pi++]=s[i--];
                    var[pi]='\0';
                    pi=0;
                    for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
                    if(pi==idx){strcpy(arr[idx].var,var);idx++;}
                    for(int qi=0;qi<cnt;qi++){arr[pi].data[qi]=tmp[qi];}
                    arr[pi].nof=cnt;
                    cnt=0;
                    break;
                case '+':
                    i-=2;
                    if(s[i]==')'){i++;nonech='+';break;}
                    int add=tmp[0];
                    pi=0;
                    while(s[i]>='a'&&s[i]<='z'&&i>=0)var[pi++]=s[i--];
                    var[pi]='\0';
                    pi=0;
                    for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
                    if(pi==idx){strcpy(arr[idx].var,var);idx++;}
                    for(int qi=0;qi<arr[pi].nof;qi++)out[qi]+=arr[pi].data[qi]+add;
                    oi=arr[pi].nof;
                    cnt=0;
                    break;
                case '-':
                    i-=2;
                    if(s[i]==')'){i++;nonech='-';break;}
                    int minus=tmp[0];
                    pi=0;
                    while(s[i]>='a'&&s[i]<='z'&&i>=0)var[pi++]=s[i--];
                    var[pi]='\0';
                    pi=0;
                    for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
                    if(pi==idx){strcpy(arr[idx].var,var);idx++;}
                    for(int qi=0;qi<arr[pi].nof;qi++)out[qi]+=arr[pi].data[qi]-minus;
                    oi=arr[pi].nof;
                    cnt=0;
                    break;
                case '*':
                    i-=2;
                    if(s[i]==')'){i++;nonech='*';break;}
                    int mult=tmp[0];
                    pi=0;
                    while(s[i]>='a'&&s[i]<='z'&&i>=0)var[pi++]=s[i--];
                    var[pi]='\0';
                    pi=0;
                    for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
                    if(pi==idx){strcpy(arr[idx].var,var);idx++;}
                    for(int qi=0;qi<arr[pi].nof;qi++)out[qi]+=arr[pi].data[qi]*mult;
                    oi=arr[pi].nof;
                    cnt=0;
                    break;
                case '/':
                    i-=2;
                    char ch=s[i];
                    pi=0;
                    for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
                    int ret=0;
                    switch (ch)
                    {
                    case '+':
                        for(int qi=arr[pi].nof-1;qi>=0;qi--){
                            ret=arr[pi].data[qi]+ret;
                        }
                        break;
                    case '-':
                        for(int qi=arr[pi].nof-1;qi>=0;qi--){
                            ret=arr[pi].data[qi]-ret;
                        }
                        break;
                    case '*':
                        for(int qi=arr[pi].nof-1;qi>=0;qi--){
                            ret=arr[pi].data[qi]*ret;
                        }
                        break;
                    default:
                        break;
                    }
                    arr[pi].data[0]=ret;
                    arr[pi].nof=1;
                    out[0]=ret;
                    oi=1;
                    break;
                case ')':
                    for(int qi=0;qi<cnt;qi++){arr[0].data[qi]=tmp[qi];}
                    arr[0].nof=cnt;
                    cnt=0;
                    break;
                case '(':
                    pi=0;
                    for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
                    cnt=0;
                    for(int qi=0;qi<arr[pi].nof;qi++){
                        tmp[cnt++]=arr[pi].data[qi];
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if(oi==0){
            pi=0;
            for(;pi<idx;pi++)if(strcmp(var,arr[pi].var)==0)break;
            for(int i=arr[pi].nof-1;i>=0;i--){
                printf("%d ",arr[pi].data[i]);
            }
        }
        else{for(int i=oi-1;i>=0;i--){
            printf("%d ",out[i]);
            }
        }
        printf("\n");
    }
}
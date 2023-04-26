#include<stdio.h>
#include<string.h>

int main(){
    int reg[30]={0};
    char s[10]={0}, b[60]={0};
    while(scanf("%s", s)!=EOF){
        scanf("%s", b);
        int blen=strlen(b);
        switch(s[0]){
            case 'I':{//in
                int num=0, fuhao=1;
                for (int i=3;i<strlen(b);i++){
                    if (b[i]=='-'){fuhao=-1;continue;}
                    num*=10;
                    num+=b[i]-'0';
                }
                reg[b[0]-'A']=num*fuhao;
                break;                
            }
            case 'M':
                if (s[2]=='V') reg[b[0]-'A']=reg[b[3]-'A'];//mov
                else if (s[2]=='L') {//mul
                    if (blen==5) reg[b[0]-'A']*=reg[b[3]-'A'];
                    else reg[b[0]-'A']=reg[b[3]-'A']*reg[b[6]-'A'];
                } 
                else {//mod
                    if (blen==5) reg[b[0]-'A']%=reg[b[3]-'A'];
                    else reg[b[0]-'A']=reg[b[3]-'A']%reg[b[6]-'A'];
                }
                break;
            case 'A':
                if (s[1]=='D') {//add
                    if (blen==5) reg[b[0]-'A']+=reg[b[3]-'A'];
                    else reg[b[0]-'A']=reg[b[3]-'A']+reg[b[6]-'A'];
                }
                else {//and
                    if (blen==5) reg[b[0]-'A']&=reg[b[3]-'A'];
                    else reg[b[0]-'A']=reg[b[3]-'A']&reg[b[6]-'A'];
                }
                break;
            case 'S'://sub
                if (blen==5) reg[b[0]-'A']-=reg[b[3]-'A'];
                else reg[b[0]-'A']=reg[b[3]-'A']-reg[b[6]-'A'];
                break;
            case 'D'://div
                if (blen==5) reg[b[0]-'A']/=reg[b[3]-'A'];
                else reg[b[0]-'A']=reg[b[3]-'A']/reg[b[6]-'A'];
                break;
            case 'O':
                if (s[1]=='U') printf("%d\n", reg[b[0]-'A']);//out
                else if (s[1]=='R') {//or
                    if (blen==5) reg[b[0]-'A']|=reg[b[3]-'A'];
                    else reg[b[0]-'A']=reg[b[3]-'A']|reg[b[6]-'A'];
                }
                break;
            case 'X':
                if (s[1]=='O'){//xor
                    if (blen==5) reg[b[0]-'A']^=reg[b[3]-'A'];
                    else reg[b[0]-'A']=reg[b[3]-'A']^reg[b[6]-'A'];
                }
                else {//xchg
                    int temp=reg[b[0]-'A'];
                    reg[b[0]-'A']=reg[b[3]-'A'];
                    reg[b[3]-'A']=temp;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
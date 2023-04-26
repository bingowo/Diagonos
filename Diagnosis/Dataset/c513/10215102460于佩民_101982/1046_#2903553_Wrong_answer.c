#include <stdio.h>
#include <string.h>

int main(){
    int num,now=0,i,sum=0;
    scanf("%d\n",&num);
    char s[101];
    while(now<num){
        gets(s);
        if(s[1]==' '&&s[2]!='\0'){
            if(s[0]=='a') break;
            else if(s[0]=='A') break;
            else sum++;
        }
        if(s[2]==' '&&s[3]!='\0'){
            if(s[1]=='n'&&s[0]=='a')break;
            else if(s[1]=='n'&&s[0]=='A')break;
            else if(s[1]=='N'&&s[0]=='a')break;
            else if(s[1]=='N'&&s[0]=='A')break;
            else if(s[1]=='f'&&s[0]=='o')break;
            else if(s[1]=='F'&&s[0]=='o')break;
            else if(s[1]=='f'&&s[0]=='O')break;
            else if(s[1]=='F'&&s[0]=='O')break;
            else sum++;
        }
        if(s[3]==' '&&s[4]!='\0'){
            if(s[2]=='a'&&s[1]==' ')break;
            else if(s[2]=='A'&&s[1]==' ')break;
            else if(s[2]=='e'&&s[1]=='h'&&s[0]=='t')break;
            else if(s[2]=='e'&&s[1]=='h'&&s[0]=='T')break;
            else if(s[2]=='e'&&s[1]=='H'&&s[0]=='T')break;
            else if(s[2]=='e'&&s[1]=='H'&&s[0]=='t')break;
            else if(s[2]=='E'&&s[1]=='h'&&s[0]=='t')break;
            else if(s[2]=='E'&&s[1]=='h'&&s[0]=='T')break;
            else if(s[2]=='E'&&s[1]=='H'&&s[0]=='t')break;
            else if(s[2]=='E'&&s[1]=='H'&&s[0]=='T')break;
            else if(s[2]=='r'&&s[1]=='o'&&s[0]=='f')break;
            else if(s[2]=='r'&&s[1]=='o'&&s[0]=='F')break;
            else if(s[2]=='r'&&s[1]=='O'&&s[0]=='F')break;
            else if(s[2]=='r'&&s[1]=='O'&&s[0]=='f')break;
            else if(s[2]=='R'&&s[1]=='o'&&s[0]=='f')break;
            else if(s[2]=='R'&&s[1]=='o'&&s[0]=='F')break;
            else if(s[2]=='R'&&s[1]=='O'&&s[0]=='f')break;
            else if(s[2]=='R'&&s[1]=='O'&&s[0]=='F')break;
            else if(s[2]=='d'&&s[1]=='n'&&s[0]=='a')break;
            else if(s[2]=='d'&&s[1]=='n'&&s[0]=='A')break;
            else if(s[2]=='d'&&s[1]=='N'&&s[0]=='A')break;
            else if(s[2]=='d'&&s[1]=='N'&&s[0]=='a')break;
            else if(s[2]=='D'&&s[1]=='n'&&s[0]=='A')break;
            else if(s[2]=='D'&&s[1]=='n'&&s[0]=='A')break;
            else if(s[2]=='D'&&s[1]=='N'&&s[0]=='a')break;
            else if(s[2]=='D'&&s[1]=='N'&&s[0]=='A')break;
            else sum++;
        }
        if(strlen(s)>=4){
        for(i=4;i<strlen(s);i++){
            if(s[i]==' '&&s[i+1]!='\0'){
                if(s[i-1]=='a'&&s[i-2]==' ')continue;
                else if(s[i-1]=='A'&&s[i-2]==' ')continue;
                else if(s[i-1]=='n'&&s[i-2]=='a'&&s[i-3]==' ')continue;
                else if(s[i-1]=='n'&&s[i-2]=='A'&&s[i-3]==' ')continue;
                else if(s[i-1]=='N'&&s[i-2]=='a'&&s[i-3]==' ')continue;
                else if(s[i-1]=='N'&&s[i-2]=='A'&&s[i-3]==' ')continue;
                else if(s[i-1]=='e'&&s[i-2]=='h'&&s[i-3]=='t'&&s[i-4]==' ')continue;
                else if(s[i-1]=='e'&&s[i-2]=='h'&&s[i-3]=='T'&&s[i-4]==' ')continue;
                else if(s[i-1]=='e'&&s[i-2]=='H'&&s[i-3]=='T'&&s[i-4]==' ')continue;
                else if(s[i-1]=='e'&&s[i-2]=='H'&&s[i-3]=='t'&&s[i-4]==' ')continue;
                else if(s[i-1]=='E'&&s[i-2]=='h'&&s[i-3]=='t'&&s[i-4]==' ')continue;
                else if(s[i-1]=='E'&&s[i-2]=='h'&&s[i-3]=='T'&&s[i-4]==' ')continue;
                else if(s[i-1]=='E'&&s[i-2]=='H'&&s[i-3]=='t'&&s[i-4]==' ')continue;
                else if(s[i-1]=='E'&&s[i-2]=='H'&&s[i-3]=='T'&&s[i-4]==' ')continue;
                else if(s[i-1]=='f'&&s[i-2]=='o'&&s[i-3]==' ')continue;
                else if(s[i-1]=='F'&&s[i-2]=='o'&&s[i-3]==' ')continue;
                else if(s[i-1]=='f'&&s[i-2]=='O'&&s[i-3]==' ')continue;
                else if(s[i-1]=='F'&&s[i-2]=='O'&&s[i-3]==' ')continue;
                else if(s[i-1]=='r'&&s[i-2]=='o'&&s[i-3]=='f'&&s[i-4]==' ')continue;
                else if(s[i-1]=='r'&&s[i-2]=='o'&&s[i-3]=='F'&&s[i-4]==' ')continue;
                else if(s[i-1]=='r'&&s[i-2]=='O'&&s[i-3]=='F'&&s[i-4]==' ')continue;
                else if(s[i-1]=='r'&&s[i-2]=='O'&&s[i-3]=='f'&&s[i-4]==' ')continue;
                else if(s[i-1]=='R'&&s[i-2]=='o'&&s[i-3]=='f'&&s[i-4]==' ')continue;
                else if(s[i-1]=='R'&&s[i-2]=='o'&&s[i-3]=='F'&&s[i-4]==' ')continue;
                else if(s[i-1]=='R'&&s[i-2]=='O'&&s[i-3]=='f'&&s[i-4]==' ')continue;
                else if(s[i-1]=='R'&&s[i-2]=='O'&&s[i-3]=='F'&&s[i-4]==' ')continue;
                else if(s[i-1]=='d'&&s[i-2]=='n'&&s[i-3]=='a'&&s[i-4]==' ')continue;
                else if(s[i-1]=='d'&&s[i-2]=='n'&&s[i-3]=='A'&&s[i-4]==' ')continue;
                else if(s[i-1]=='d'&&s[i-2]=='N'&&s[i-3]=='A'&&s[i-4]==' ')continue;
                else if(s[i-1]=='d'&&s[i-2]=='N'&&s[i-3]=='a'&&s[i-4]==' ')continue;
                else if(s[i-1]=='D'&&s[i-2]=='n'&&s[i-3]=='A'&&s[i-4]==' ')continue;
                else if(s[i-1]=='D'&&s[i-2]=='n'&&s[i-3]=='A'&&s[i-4]==' ')continue;
                else if(s[i-1]=='D'&&s[i-2]=='N'&&s[i-3]=='a'&&s[i-4]==' ')continue;
                else if(s[i-1]=='D'&&s[i-2]=='N'&&s[i-3]=='A'&&s[i-4]==' ')continue;
                else sum++;
            }
            else if(s[i+1]=='\0') sum++;
        }
        }
        printf("case #");
        printf("%d:\n",now);
        printf("%d\n",sum);
        now++;
        for(i=0;i<101;i++){
            s[i]='\0';}
        sum=0;
    }
    return 0;
}
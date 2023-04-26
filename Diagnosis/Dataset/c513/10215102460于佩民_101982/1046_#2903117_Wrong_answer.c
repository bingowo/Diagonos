#include <stdio.h>
#include <string.h>

int main(){
    int num,now=0,i,sum=0;
    scanf("%d\n",&num);
    char s[101];
    while(now<num){
        gets(s);
        for(i=0;i<strlen(s);i++){
            if(s[i]==' '&&s[i+1]!='\0'){
                if(s[i-1]=='a');
                else if(s[i-1]=='A');
                else if(s[i-1]=='n'&&s[i-2]=='a');
                else if(s[i-1]=='n'&&s[i-2]=='A');
                else if(s[i-1]=='N'&&s[i-2]=='a');
                else if(s[i-1]=='N'&&s[i-2]=='A');
                else if(s[i-1]=='e'&&s[i-2]=='h'&&s[i-3]=='t');
                else if(s[i-1]=='e'&&s[i-2]=='h'&&s[i-3]=='T');
                else if(s[i-1]=='e'&&s[i-2]=='H'&&s[i-3]=='T');
                else if(s[i-1]=='e'&&s[i-2]=='H'&&s[i-3]=='t');
                else if(s[i-1]=='E'&&s[i-2]=='h'&&s[i-3]=='t');
                else if(s[i-1]=='E'&&s[i-2]=='h'&&s[i-3]=='T');
                else if(s[i-1]=='E'&&s[i-2]=='H'&&s[i-3]=='t');
                else if(s[i-1]=='E'&&s[i-2]=='H'&&s[i-3]=='T');
                else if(s[i-1]=='f'&&s[i-2]=='o');
                else if(s[i-1]=='F'&&s[i-2]=='o');
                else if(s[i-1]=='f'&&s[i-2]=='O');
                else if(s[i-1]=='F'&&s[i-2]=='O');
                else if(s[i-1]=='r'&&s[i-2]=='o'&&s[i-3]=='f');
                else if(s[i-1]=='r'&&s[i-2]=='o'&&s[i-3]=='F');
                else if(s[i-1]=='r'&&s[i-2]=='O'&&s[i-3]=='F');
                else if(s[i-1]=='r'&&s[i-2]=='O'&&s[i-3]=='f');
                else if(s[i-1]=='R'&&s[i-2]=='o'&&s[i-3]=='f');
                else if(s[i-1]=='R'&&s[i-2]=='o'&&s[i-3]=='F');
                else if(s[i-1]=='R'&&s[i-2]=='O'&&s[i-3]=='f');
                else if(s[i-1]=='R'&&s[i-2]=='O'&&s[i-3]=='F');
                else if(s[i-1]=='d'&&s[i-2]=='n'&&s[i-3]=='a');
                else if(s[i-1]=='d'&&s[i-2]=='n'&&s[i-3]=='A');
                else if(s[i-1]=='d'&&s[i-2]=='N'&&s[i-3]=='A');
                else if(s[i-1]=='d'&&s[i-2]=='N'&&s[i-3]=='a');
                else if(s[i-1]=='D'&&s[i-2]=='n'&&s[i-3]=='A');
                else if(s[i-1]=='D'&&s[i-2]=='n'&&s[i-3]=='A');
                else if(s[i-1]=='D'&&s[i-2]=='N'&&s[i-3]=='a');
                else if(s[i-1]=='D'&&s[i-2]=='N'&&s[i-3]=='A');
                else sum++;
            }
            else if(s[i+1]=='\0') sum++;
        }
        printf("case #");
        printf("%d:\n",now);
        printf("%d\n",sum);
        now++;
        sum=0;
    }
    return 0;
}
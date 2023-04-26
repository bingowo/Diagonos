#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123456];
int s[123456];

int main(){
    scanf("%s",st);
    while (strlen(st)!=1){
        char temp[1234];
        int i=0;
        for (int j=0;j<strlen(st);j++){
            if (st[j]=='(' && st[j+1]==')'){
                temp[i]='1';
                s[i]=1;
                i++;
                j++;
            }
            else if (st[j]=='1' && st[j+1]=='1'){
                s[i]=s[j]+s[j+1];
                temp[i]='1';
                i++;
                j++;
            }
            else if (st[j]=='1' && j-1>=0 && j+1<strlen(st) && st[j+1]==')' && st[j-1]=='('){
                s[i-1]=s[j]*2;
                temp[i-1]='1';
                j++;
            }
            else {
                temp[i]=st[j];
                if (st[j]=='1') s[i]=s[j];
                i++;
            }
        }
        temp[i]='\0';
        strcpy(st,temp);
    }
    printf("%d\n",s[0]);
    return 0;
}

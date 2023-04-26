#include <stdio.h>
#include <string.h>

int num = 0;

void mygetss(char s[][15]) {
    int i = 0;
    char a;
    while ((a = getchar()) != EOF && i < 100) {
        if (a != 32 && a != '\n') {
            if (a >= 'A' && a <= 'Z') {
                s[num][i++] = a + 32;
            } else {
                s[num][i++] = a;
            }
        } else if (a == 32) {
            s[num][i] = '\0';
            num++;
            i = 0;
        } else {
            s[num][i] = '\0';
            num++;
            return;
        }
    }
}

void mygets(char *s)
{
    int i=0;
    char a;
    while((a= getchar())!=EOF && i<2001)
    {
        s[i++]=a;
        if(a=='\n')
            break;
    }
    s[--i]='\0';
}

int main() {
    int T;
    char s[100][15];
    scanf("%d", &T);
    mygets(s[0]);
    for (int j = 0; j < T; j++) {
        mygetss(s);
        int count=0;
        for(int i=0;i<num;i++){
            if(s[i][0]=='t' && s[i][1]=='h' && s[i][2]=='e' && s[i][3]=='\0')
                count++;
            else if(s[i][0]=='f' && s[i][1]=='o' && s[i][2]=='r' && s[i][3]=='\0')
                count++;
            else if(s[i][0]=='a' && s[i][1]=='n' && s[i][2]=='d' && s[i][3]=='\0')
                count++;
            else if(s[i][0]=='o' && s[i][1]=='f'  && s[i][2]=='\0')
                count++;
            else if(s[i][0]=='a' && s[i][1]=='n'  && s[i][2]=='\0')
                count++;
            else if(s[i][0]=='a'  && s[i][1]=='\0')
                count++;
            else
                continue;
        }
        printf("case #%d:\n",j);
        printf("%d\n",num-count);
        num=0;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[1100];memset(s,0,1100*sizeof(char));
    scanf("%s",s);
    char res[1100];memset(res,0,1100*sizeof(char));
    int slen = strlen(s);
    res[0] = toupper(s[0]);
    for(int i = 1;i<slen;i++){
        char tmp[1100];memset(tmp,0,1100*sizeof(char));
        tmp[0] = toupper(s[i]);
        //printf("tmp = %s, res[0] = %c, ",tmp,res[0]);
        if(tmp[0]<res[0]){
            //printf("< ");
            strcat(res,tmp);
        }
        else{
            //printf("> ");
            strcat(tmp,res);
            strcpy(res,tmp);
        }
        //rintf("tmp = %s, res = %s\n",tmp,res);
    }
    printf("%s",res);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000][1000];
char backup[1000][1000];

int main()
{
    memset(s,0,1000*1000*sizeof(char));
    memset(backup,0,1000*1000*sizeof(char));
    int cnt = 0;
    while(gets(s[cnt])!=NULL){
        strcpy(backup[cnt],s[cnt]);
        cnt++;
    }


    //"0"
    for(int i = 0;i<cnt;i++){
        int len = strlen(backup[i]);
        int first = 0,end = 0;
        for(int j = 0;j<len;j++){
            if(backup[i][j]=='"'){
                first = j;
                break;
            }
        }
        for(int j = len-1;j>=0;j--){
            if(backup[i][j]=='"'){
                end = j;
                break;
            }
        }

        for(int j = first+1;j<end;j++){
            backup[i][j] = '0';
        }

        first = 0,end = 0;
        for(int j = 0;j<len;j++){
            if(backup[i][j]=='\''){
                first = j;
                break;
            }
        }
        for(int j = len-1;j>=0;j--){
            if(backup[i][j]=='\''){
                end = j;
                break;
            }
        }

        for(int j = first+1;j<end;j++){
            backup[i][j] = '0';
        }
    }

    for(int i = 0;i<cnt;i++){
        int len = strlen(backup[i]);
        if(strstr(backup[i],"//")==NULL){
            continue;
        }
        else{
            int start = strstr(backup[i],"//") - backup[i];
            s[i][start] = 0;
            //printf("%d, stt = %d\n",i,start);
        }
    }

    int row = 0,column = 0;
    while(row<cnt){
        int start[2] = {0,0}, end[2] = {0,0};
        if(strstr(backup[row],"/*")!=NULL){
            start[0] = row;start[1] = strstr(backup[row],"/*") - backup[row];
            while(strstr(backup[row],"*/")==NULL){
                row++;
            }
            end[0] = row;end[1] = strstr(backup[row],"*/") - backup[row];
            s[start[0]][start[1]] = 0;
            for(int j = start[0]+1;j<end[0];j++){
                s[j][0] = 0;
            }
            for(int k = 0;k<end[1];k++){
                s[end[0]][k] = ' ';
            }
        }
        row++;
    }

    //printf("backup:\n");
    //for(int i = 0;i<cnt;i++){
    //    if(i == cnt-1){
    //        printf("%s",backup[i]);
    //        break;
    //    }
    //    printf("%s\n",backup[i]);

    //}

    //printf("\ns:\n");
    for(int i = 0;i<cnt;i++){
        if(i == cnt-1){
            printf("%s",s[i]);
            break;
        }
        printf("%s\n",s[i]);

    }
    return 0;
}

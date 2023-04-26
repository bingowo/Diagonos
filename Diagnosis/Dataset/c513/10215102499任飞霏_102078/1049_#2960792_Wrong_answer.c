#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[501][50]={0};

void select(char *a)
{
    int len=strlen(a),start=0,s=0,i,j;
    for(i=0;i<len;i++){
        if(a[i]>='a'&&a[i]<='z')continue;
        else if(start<i){
            for(j=start;j<i;j++) {
                word[s][j-start]=a[j];
            }
            s++;
            start=i+1;
        }
        else{
            start=i+1;
        }
    }
    
    char tmp[501]={0};
    for(i=0;i<s;i++){
        for(j=i+1;j<s;j++){
            if(strcmp(word[i],word[j])>0){
                strcpy(tmp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],tmp);
            }

        }
    }
    strcpy(tmp,word[0]);
    printf("%s",word[0]);

    for(i=1;i<s;i++){
        if(strcmp(tmp,word[i])==0){
            continue;
        }
        else{
            strcpy(tmp,word[i]);
            printf(" %s",word[i]);
        }

    }
    printf("\n");
}


int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        for(int h=0;h<501;h++)
			for(int j=0;j<50;j++)
				word[h][j]='\0';

        char sentence[501];
        gets(sentence);
        printf("case #%d:\n",i);
        select(sentence);
    }
    return 0;
}

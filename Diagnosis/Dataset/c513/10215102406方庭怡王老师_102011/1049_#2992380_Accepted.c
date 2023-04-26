#include<stdio.h>
#include<string.h>
#include<math.h>
#define INF 501

char word[INF][50];
int s=0;

void select(char a[]) {
	s=0;

    int i,j,len,start;

    len=strlen(a);
    start=0;
    for(i=0; i<len; i++) {
        if(a[i]<='z'&&a[i]>='a') {
			continue;
		}
		else if(start<i)
		{
			for(j=start; j<i; j++) {
                word[s][j-start]=a[j];
            }
            s++;
            start=i+1;
		}
		else
			start=i+1;
    }

	if(start<len)
	{
		for(j=start; j<i; j++) {
			word[s][j-start]=a[j];
        }
        s++;
        start=i+1;
	}
    char tmp[INF];
    for(i=0; i<s; i++) {
        for(j=i+1; j<s; j++) {
            if(strcmp(word[i],word[j])>0) {
                strcpy(tmp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],tmp);
            }
        }
    }
    strcpy(tmp,word[0]);
    printf("%s",word[0]);

	for(i=1; i<s; i++) {
        if(strcmp(tmp,word[i])==0) {
            continue;
        } else {
			strcpy(tmp,word[i]);
            printf(" %s",word[i]);
        }
    }
    printf("\n");
}

int main() {
    int i,j,t;
    char sentence[INF];

    scanf("%d",&t);getchar();
    for(i=0; i<t; i++) {

		for(int h=0;h<501;h++)//清空
			for(j=0;j<50;j++)
				word[h][j]='\0';

			gets(sentence);
			printf("case #%d:\n",i);
			select(sentence);
    }
    return 0;
}

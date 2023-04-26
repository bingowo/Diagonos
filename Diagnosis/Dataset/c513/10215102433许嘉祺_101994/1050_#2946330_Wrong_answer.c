#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    int t;
    scanf("%d",&t);
    char s1[100];
    char s2[100];
    char s[100];

    for (int i=0;i<t;i++){
        printf("case #%d:\n",i);
        scanf("%s%s%s",s1,s2,s);
        if (strstr(s,s1)==NULL||strstr(s,s2)==NULL) printf("0\n");
        else {
            int first=strstr(s,s1)+strlen(s1)-s;
            int fina;
            for (int j=strlen(s)-strlen(s1);j>=0;j--){
                char s3[100];
                s3[0]=0;
                strncat(s3,s+j,strlen(s2));
                s3[strlen(s2)]=0;
                if (strcmp(s3,s2)==0) {fina=j;break;}
            }
            printf("%d\n",fina-first);
        }
    }



    return 0;
}
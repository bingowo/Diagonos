#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    char s1[501],s2[501];
    while (scanf("%s%s",s1,s2)!=EOF){
        if (strlen(s1)<strlen(s2)||strcmp(s1,s2)<0)
        {
            char s3[501];
            printf("-");
            strcpy(s3,s1);
            strcpy(s1,s2);
            strcpy(s2,s3);
        }
        for (int i=strlen(s1)-1;i>=0;i--){

            int len=-strlen(s1)+i+strlen(s2);
            if (len>=0)

            s1[i]=s1[i]-s2[-strlen(s1)+i+strlen(s2)]+'0';
            if (s1[i]<'0') {
                s1[i]+=10;
                s1[i-1]-=1;
            }

        }
        int i=0;
        while (s1[i]=='0') i++;
        if (i!=strlen(s1))
        printf("%s\n",s1+i);
        else printf("0\n");
    }

    return 0;
}
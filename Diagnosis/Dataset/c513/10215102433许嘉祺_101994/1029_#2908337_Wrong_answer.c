#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//int cmp(const void*a,const void*b){
//    char*p1=*(char(*)[201])a,*p2=*(char(*)[201])b;
//    return
//}

int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    char s[201];
    int a[255];
    for (int i=0; i<t; i++)
    {
        memset(a,0,sizeof(a));
        gets(s);
        for (int j=0; j<strlen(s); j++)
            if (s[j]>='A'&&s[j]<='Z') a[s[j]]++;
        printf("case #%d:\n",i);
        int n=0;
        for (int j=0; j<strlen(s); j++)
            if (s[j]<='A'||s[j]>='Z')
                printf("%c",s[j]);
            else{
                for (int k='A'; k<='Z'; k++) if (a[k]>0)
                    {
                        printf("%c",k);
                        a[k]--;
                        break;
                    }}
        printf("\n");
    }

    return 0;
}

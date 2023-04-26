#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b)
{
    char *aa=(char*)a;
    char* bb=(char*)b;
    return strcmp(aa,bb);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char s[501][501];
        char c;
        int count=0,cnt=0;
        c=getchar();
        while(c!='\n'){
            if('a'<=c&&c<='z'){
                s[count][cnt++]=c;
                c=getchar();
            }
            if(c==','||c==' '||c=='.'||c=='?'||c=='!'){
                s[count][cnt]='\0';
                cnt=0;count++;
                c=getchar();
                }
            while(c==','||c==' '||c=='.'||c=='?'||c=='!'){c=getchar();}
        }
        s[count][cnt]='\0';
        qsort(s,count,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s ",s[0]);
        for(int i=1;i<count;i++){
            if(strcmp(s[i],s[i-1])!=0)printf("%s ",s[i]);
        }
        printf("\n");
    }
    return 0;
}

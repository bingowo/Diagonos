#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strnumcmp(const void *a,const void *b)
{
    int flag1 = 0;
    int flag2 = 0;
    char *c=(char*)a;
    char *d=(char*)b;
    //printf("%s %s\n",c,d);
    int len1 =strlen(c);
    int len2 =strlen(d);
    //printf("%d %d\n",len1,len2);
    int i,j;
    int m,n;
    int k;
    for (i=0;i<len1;i++){
        if ((c[i]-'0'>=0) && (c[i]-'0'<=9)){
            flag1 = 1;
            break;
        }
    }
    for (j=0;j<len2;j++){
        if ((d[j]-'0'>=0) && (d[j]-'0'<=9)){
            flag2 = 1;
            break;
        }
    }
    if ((flag1==0) && (flag2==0)){
        return strcmp(c,d);
    }
    else if ((flag1==1) && (flag2 ==0)){
        return 1;
    }
    else if ((flag1==0) && (flag2 ==1)){
        return -1;
    }
    else
    {
        char e[31];
        for (k=0;c[i]!='\0';k++){
            e[k]=c[i];
            i++;
        }
        e[k]='\0';
        m=atoi(e);
        for (k=0;d[j]!='\0';k++){
            e[k]=d[j];
            j++;
        }
        e[k]='\0';
        n=atoi(e);

        return m-n;
    }
}

int main()
{
    char a[100][31];
    int i=0;
    while (scanf("%s",&a[i])!=EOF){
        i++;
    }
    qsort(a,i,sizeof(a[0]),strnumcmp);
    int j=0;
    for (j=0;j<i;j++){
        printf("%s ",a[j]);
    }
    return 0;
}

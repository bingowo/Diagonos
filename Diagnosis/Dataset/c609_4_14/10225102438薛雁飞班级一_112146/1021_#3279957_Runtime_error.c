#include <stdio.h>
#include <stdlib.h>
int p[26];
int cmp(const void* p1,const void* p2)
{
    char *a,*b;
    a=(char*)p1;b=(char*)p2;
    int k=0;
    while(a[k]&&b[k]){
        if(a[k]>='a')a[k]=a[k]-32;
        if(b[k]>='a')b[k]=b[k]-32;
        if(p[a[k]-'A']>p[b[k]-'A'])return 1;
        else if(p[a[k]-'A']<p[b[k]-'A'])return -1;
        else k++;
    }
    if(a[k]==0)return -1;
    else return 1;
}
int main()
{
    char alpha[26];
    while(scanf("%s",alpha)!=EOF){
        for(int i=0;i<26;i++){
            p[alpha[i]-'A']=i;
        }
        char a[100][21];
        int count=0,k=0;
        char c;
        do{
            c=getchar();
            if(c!=' '&&c!='\n'){
                a[count][k]=c;
                k++;
            }
            else if(c==' '){
                a[count][k]='\0';
                count++;
                k=0;
            }
        }while(c!='\n');
        qsort(a,count,sizeof(a[0]),cmp);
        for(int i=0;i<count;i++){
            printf("%s ",a[i]);
        }
        printf('\n');
    }
    return 0;
}

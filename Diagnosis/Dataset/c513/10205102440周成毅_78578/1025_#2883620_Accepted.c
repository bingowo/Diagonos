#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct String{
    char s[21];
    char trans[21];
    int length;
} string;

void Encrypt(char* keych,char *key)
{
    keych[0]=key[0];
    int i,j=0,k=0,flag;
    for(i=0;key[i]!='\0';i++)
    {
        flag=1;
        for(k=0;k<j+1;k++)
        {
            if(key[i]==keych[k])
                flag=0;
        }
        if(flag)
        {
            j=j+1;
            keych[j]=key[i];
        }
    }
    keych[j+1]='\0';
}

int cmp(const void *a, const void *b){
    string *a1=(string*)a;
    string *b1=(string*)b;
    if(a1->length!=b1->length)
        return b1->length-a1->length;
    else
        return strcmp(a1->s,b1->s);
}

void myprint(string list[],int num){
    for(int i=0;i<num;i++)
        printf("%s\n",list[i].s);
}

string list[101];

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",list[j].s);
            Encrypt(list[j].trans,list[j].s);
            list[j].length=strlen(list[j].trans);
        }
        qsort(list,n,sizeof (string),cmp);
        printf("case #%d:\n",i);
        myprint(list,n);
    }
    return 0;
}

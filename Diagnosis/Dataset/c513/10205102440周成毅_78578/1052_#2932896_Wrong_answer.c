#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

void sub(int *a, int num, int *b){
    for(int i=0;i<26;i++)
        a[i]-=num*b[i];
}

int main() {
    int list[10][26]={0};
    char s[21];
    int count[26]={0};
    int order[10]={25,23,6,18,21,20,22,19,9,14};
    int number[10]={0,6,8,7,5,4,2,3,9,1};
    int head=0,code[20];
    list[0][25]=1,list[0]['e'-'a']=1,list[0]['r'-'a']=1,list[0]['o'-'a']=1;
    list[1]['o'-'a']=1,list[1]['n'-'a']=1,list[1]['e'-'a']=1;
    list[2]['t'-'a']=1,list[2]['o'-'a']=1,list[2]['w'-'a']=1;
    list[3]['t'-'a']=1,list[3]['h'-'a']=1,list[3]['r'-'a']=1,list[3]['e'-'a']=2;
    list[4]['f'-'a']=1,list[4]['o'-'a']=1,list[4]['u'-'a']=1,list[4]['r'-'a']=1;
    list[5]['f'-'a']=1,list[5]['i'-'a']=1,list[5]['v'-'a']=1,list[5]['e'-'a']=1;
    list[6]['s'-'a']=1,list[6]['i'-'a']=1,list[6]['x'-'a']=1;
    list[7]['s'-'a']=1,list[7]['e'-'a']=2,list[7]['v'-'a']=1,list[7]['n'-'a']=1;
    list[8]['e'-'a']=1,list[8]['i'-'a']=1,list[8]['g'-'a']=1,list[8]['h'-'a']=1,list[8]['t'-'a']=1;
    list[9]['n'-'a']=2,list[9]['i'-'a']=1,list[9]['e'-'a']=1;
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        for(int j=0;s[j];j++)
            count[s[j]-'A']++;
        for(int j=0;j<10;j++){
            if(count[order[j]]){
                for(int m=0;m<count[order[j]];m++)
                    code[head++]=number[j];
                sub(count,count[order[j]],list[number[j]]);
            }
        }
        qsort(code,head,sizeof (int),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<head;j++)
            printf("%d",code[j]);
        printf("\n");
        head=0;
    }
    printf("Hello, World!\n");
    return 0;
}

#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct file{
    char s[300];
    long long int date;
    char name[70];
    int size;
};
void trans(char *s,struct file *a){
    strcpy(a->s,s);
    char Day[100],*s1,Size[20];
    int k=0;
    s1=s;
    for(int i=0,p=0;i<16;i++){
        if(isalnum(*s1))Day[p++]=*s1;
        s1++;
    }
    Day[p]=0;
    a->date=atoll(Day);
    while(!isalnum(*s1))s1++;
    while(isalnum(*s1)){
        Size[k++]=*s1;
        s1++;
    }
    Size[k]=0;
    a->size=atoi(Size);
    s1++;
    k=0;
    while(*s1){
        a->name[k++]=*s1;
        s1++;
    }
    a->name[k]=0;
}
int cmp1(const void *a,const void *b){
    struct file *m,*n;
    m=(struct file*)a;
    n=(struct file*)b;
    if(strcmp(m->name,n->name)>0)return 1;
    return -1;
}
int cmp2(const void *a,const void *b){
    struct file *m,*n;
    m=(struct file*)a;
    n=(struct file*)b;
    if(m->size>n->size)return 1;
    if(m->size==n->size){
        if(strcmp(m->name,n->name)>0)return 1;
    }
    return -1;
}
int cmp3(const void *a,const void *b){
    struct file *m,*n;
    m=(struct file*)a;
    n=(struct file*)b;
    if(m->date>n->date)return 1;
    if(m->date==n->date){
        if(strcmp(m->name,n->name)>0)return 1;
    }
    return -1;
}

int main(){
    int n,m;
    struct file *a,*b;
    scanf("%d",&n);
    char c=getchar();
    while(n!=0){
        a=(struct file*)malloc(n*sizeof(struct file));
        b=a,m=n;
        while(m-->0){
            char s[500];
            gets(s);
            trans(s,b++);
        }
        char list[10];
        scanf("LIST /%s",list);
        if(!strcmp(list,"NAME")){
            qsort(a,n,sizeof(struct file),cmp1);
        }
        else if(!strcmp(list,"SIZE")){
            qsort(a,n,sizeof(struct file),cmp2);
        }
        else{
            qsort(a,n,sizeof(struct file),cmp3);
        }
        for(int i=0;i<n;i++)printf("%s\n",(a+i)->s);
        printf("\n");
        scanf("%d",&n);
        c=getchar();
        free(a);
    }
    return 0;
}
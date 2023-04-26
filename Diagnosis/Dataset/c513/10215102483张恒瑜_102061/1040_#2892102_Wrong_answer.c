#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define O 0
#define B 1
#define A 2
#define AB 3

int initialize(char in[])
{
    if(strcmp(in,"A")==0) return A;
    else if(strcmp(in,"B")==0) return B;
    else if(strcmp(in,"O")==0) return O;
    else if(strcmp(in,"AB")==0) return AB;
    else if(strcmp(in,"?")==0) return -1;
}

int answer[4]={-1,-1,-1,-1};

int solve0(int a,int b,int flag)
{
    if(a==b) return a;
    else
    {
        if(flag=='+') return a+b;
        if(flag=='-') return b-a;
    }
}

void solve(int a0,int b0,int flag)
{
    int a[2]={0},b[2]={0};
    if(a0==A) a[0]=A;
    else if(a0==B) a[0]=B;
    else if(a0==AB) {a[0]=A;a[1]=B;}
    if(b0==A) b[0]=A;
    else if(b0==B) b[0]=B;
    else if(b0==AB) {b[0]=A;b[1]=B;}
    answer[0]=solve0(a[0],b[0],flag);
    answer[1]=solve0(a[0],b[1],flag);
    answer[2]=solve0(a[1],b[0],flag);
    answer[3]=solve0(a[1],b[1],flag);
}

int cmp(const void* a,const void *b)
{
    return *(int*)b-*(int*)a;
}

void pr()
{
    int i,flag[4]={0};
    char out[5]={'\0'};
    for(i=0;i<4;i++)
    {
        if(flag[answer[i]]==0)
        {
            switch (answer[i])
            {
                case O:printf("O");break;
                case B:printf("B");break;
                case A:printf("A");break;
                case AB:printf("AB");break;
                default:break;
            }
            flag[answer[i]]=1;
            int j;
            for(j=i;j<4;j++)
            {
                if(flag[answer[j]]==0) break;
            }
            if(j!=4) printf(",");
        }
    }
    printf("}");
}

int main()
{
    char f[10]={'\0'},m[10]={'\0'},c[10]={'\0'};
    scanf("%s %s %s",f,m,c);
    int father=initialize(f),mother=initialize(m),child=initialize(c);

    if(child==-1) solve(father,mother,'+');
    if(father==-1) solve(mother,child,'-');
    if(mother==-1) solve(father,child,'-');

    qsort(answer,4,sizeof(answer[0]),cmp);

    if(child==-1)
    {
        printf("%s %s {",f,m);
        pr();
    }

    return 0;
}
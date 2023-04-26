#include<stdio.h>
#include<string.h>
#include<math.h>
int comp1(const void *a,const void *b)
{
    int a1=*(int *)a,b1=*(int *)b;
    return a1-b1;
}
int comp2(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    char c;
    c=getchar();
    int s[101],m=0;
    char a;
    do{
        scanf("%d",&s[m++]);
    }while(a=getchar()==' ');
    if(c=='A')qsort(s,m,sizeof(int),comp1);//升序
    else qsort(s,m,sizeof(int),comp2);
    int n=0;
    for(int step=0;step<m-1;step++){
        if(s[step]!=s[step+1])printf("%d ",s[step]);
    }
    printf("%d",s[m-1]);
    return 0;
}

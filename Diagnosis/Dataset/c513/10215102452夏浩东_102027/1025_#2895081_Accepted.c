#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnp(const void *a,const void *b)
{
    char *A=(char*)a;
    char *B=(char*)b;
    if(*A>*B) return 1;
    else return -1;
}

int cmp(const void *a,const void *b)
{
    char *A=*(char**)a;
    char *B=*(char**)b;
    char C[30];
    char D[30];
	strcpy(C,A);
	strcpy(D,B);
    int num1=0,num2=0;
    for(int i=0;A[i]!='\0';i++)
    {
        num1++;
    }
    for(int i=0;B[i]!='\0';i++)
    {
        num2++;
    }
    qsort(C,num1,sizeof(char),cnp);
    qsort(D,num2,sizeof(char),cnp);
    int res1=1,res2=1;
    for(int i=1;i<num1;i++) if(C[i]!=C[i-1]) res1++;
    for(int i=1;i<num2;i++) if(D[i]!=D[i-1]) res2++;
    if(res1!=res2) return res2-res1;
    else
    {
        int res=-1,flag=0;
        if(num1<num2)
        {
            for(int j=0;j<num1;j++)
            {
                if(A[j]<B[j])
                {   
                    flag=1;
                    break;
                }
                else if(A[j]>B[j]) 
                {
                    flag=1;
                    res=1;
                    break;
                }
            }
            if(flag==0) res=-1;
        }
        else
        {
            for(int j=0;j<num2;j++)
            {
                if(A[j]<B[j])
                {   
                    flag=1;
                    break;
                }
                else if(A[j]>B[j]) 
                {
                    flag=1;
                    res=1;
                    break;
                }
            }
            if(flag==0) res=1;
        }
        return res;
    }
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        char *s[100];
        for(int k=0;k<num;k++)
        {
        	char *p = (char*)malloc(30*sizeof(char));
        	s[k]=(char*)malloc(30*sizeof(char));
            scanf("%s",p);
            strcpy(s[k],p);
            free(p);
        }
        qsort(s,num,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<num;j++)
        {
            printf("%s\n",s[j]);
        }
        for(int k=0;k<num;k++)
        {
        	free(s[k]);
    	}
    }
    return 0;
}
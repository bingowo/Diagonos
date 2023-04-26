#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp1(const void* a,const void* b)
{return strcmp(*((char**)a),*((char**)b));}

int cmp2(const void* a,const void* b)
{return strcmp((char*)a,(char*)b);}


void  strnumcmp(char *A[],char*B[],char*C[],int len)
{int u,j,p=0,k=0;
for(u=0;u<=len-1;u++)
{for(j=0;j<=29;j++)
   {if(A[u][j]<=57&&A[u][j]>=48){B[p]=A[u];p++;break;}
    else if (A[u][j]!=0&&j==29){C[k]=A[u];k++;}
   }
qsort(C,k,sizeof(C[0]),cmp1);

}


}


int main ()
{char A[1000][30],B[1000][30],C[1000][30];
int i=0;
while(scanf("%s",A[i])!=-1){i++;}
strnumcmp(A,B,C,i);


return 0;
}

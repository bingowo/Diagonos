#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    int *s1=*(int**)a;
    int *s2=*(int**)b;
    int i=0;
    //s1[i]!=-1&&s2[i]!=-1
    //return 1;
    while(s1[i]!=-1&&s2[i]!=-1)
    {   int l = s1[i];
        int r = s2[i];
        if(l<r){return 1;}
        else if(l>r){return -1;}

        i++;
    }
    //if((*(s1+i))==-1)return 1;
    //else return -1;
    return 1;

}
//int t[1000][57];
int main()
{
    int n,i,cas,x,k,j,l;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cas);
        k=0;
        int **t = (int**)malloc(cas*sizeof(int*));
        for(j=0;j<cas;j++){

            int tmp[50];
            int cnt=0;
            while(1)
          {
                scanf("%d",&tmp[cnt]);
                if(tmp[cnt]==-1)break;
                else cnt++;
          }
          t[j] = (int*) malloc((cnt+1)*sizeof(int));
          for(k = 0 ;k<=cnt ; k++){
             t[j][k] = tmp[k];
          }

        }

        qsort(t,cas,sizeof(t[0]),cmp);
        for(j=0;j<cas;j++){
            for(x=0;t[j][x]!=-1;x++){
                if(!x) printf("%d",t[j][x]);
                else printf(" %d",t[j][x]);
            }
            printf("\n");
        }

    }
    return 0;
}

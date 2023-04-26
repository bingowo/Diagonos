#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int *pa,*pb;
    pa=*(int(*)[4])a;
    pb=*(int(*)[4])b;
    if(pa[1]>pb[1]) return -1;
    else if(pa[1]<pb[1]) return 1;
    else if(pa[2]>pb[2]) return -1;
    else if(pa[2]<pb[2]) return 1;
    else if(pa[3]>pb[3]) return 1;
    else if(pa[3]<pb[3]) return -1;
    else return pa[0]-pb[0];
    return 0;
}

int main()
{
    int n,m;
    while((scanf("%d %d",&n,&m))!=EOF)
    {
            int arr[10][4];
            for(int i=0;i<n;i++)
            {
                arr[i][0]=i+1;;
                arr[i][1]=arr[i][2]=arr[i][3]=0;
            }
            for(int i=0;i<m;i++)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                if(c==1) arr[a-1][1]+=3,arr[a-1][2]+=1,arr[b-1][1]-=1,arr[b-1][3]+=1;
                else if(c==-1) arr[b-1][1]+=3,arr[b-1][2]+=1,arr[a-1][1]-=1,arr[a-1][3]+=1;
                else
                    arr[a-1][1]+=1,arr[b-1][1]+=1;

            }
            qsort(arr,n,sizeof(arr[0]),cmp);
            for(int i=0;i<n;i++)
                 printf("%d%c",arr[i][0],i!=n-1?' ':'\n');
    }
    return 0;
}

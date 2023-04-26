#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int zh;
    int jf;
    int w;
    int f;
}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE *)a;
    NODE s2=*(NODE *)b;
   if(s2.jf!=s1.jf)
        return s2.jf-s1.jf;
   else
   {
        if(s1.w!=s2.w)
            return s2.w-s1.w;
        else
        {
            if(s1.f!=s2.f)
                return s1.f-s2.f;
            else
                return s1.zh-s2.zh;
        }
   }

}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&m,&n);
        if(m==0&&n==0)
            break;
        NODE ans[100];
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            ans[i].zh=i+1;
            ans[i].jf=0;
            ans[i].w=0;
            ans[i].f=0;
        }
        /*for(int i=0;i<m;i++)
            printf("%d ",ans[i].zh);
        printf("\n\n");*/
       // printf("\n");
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                ans[a-1].jf+=3;
                ans[b-1].jf-=1;
                ans[a-1].w+=1;
                ans[b-1].f+=1;
            }
            else if(c==-1)
            {
                ans[a-1].jf-=1;
                ans[b-1].jf+=3;
                ans[a-1].f+=1;
                ans[b-1].w+=1;
            }
            else{
                ans[a-1].jf+=1;
                ans[b-1].jf+=1;
            }
        }
        qsort(ans,m,sizeof(ans[0]),cmp);
        for(int i=0;i<m;i++)
            printf("%d ",ans[i].zh);
        printf("\n");
    }
    return 0;
}

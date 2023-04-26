#include <stdio.h>
#include <stdlib.h>

typedef struct Cylinder
{
    long long R;
    long long H;
    long long Sbtm;
    long long Sside;
    long long Sttl;
}cylinder;



int cmpSside(const void *a,const void *b)
{
    cylinder A = *(cylinder*)a,B = *(cylinder*)b;
    return B.Sside>A.Sside;
}

int cmpR(const void *a,const void *b)
{
    cylinder A = *(cylinder*)a,B = *(cylinder*)b;
    return A.R>B.R;
}


int cmpSttl(const void *a,const void *b)
{
    cylinder A = *(cylinder*)a,B = *(cylinder*)b;
    return A.Sttl>B.Sttl;
}

int cmp1(const void *a,const void *b)
{
    cylinder A = *(cylinder*)a,B = *(cylinder*)b;
    if(A.Sttl!=B.Sttl){return A.Sttl<B.Sttl;}
    else
    {
        if(A.R!=B.R){return A.R<B.R;}
    }
}

int main()
{
    int n = 0,m = 0;
    scanf("%d%d",&n,&m);
    cylinder cy[n];memset(cy,0,n*sizeof(cylinder));
    for(int i = 0;i<n;i++)
    {
        scanf("%lld%lld",&cy[i].R,&cy[i].H);
        cy[i].Sbtm = cy[i].R*cy[i].R;
        cy[i].Sside = 2*cy[i].R*cy[i].H;
        cy[i].Sttl = cy[i].Sbtm+cy[i].Sside;
    }
    //for(int j = 0;j<n;j++)
    //{
    //    printf("cy[%d]:R = %d,H = %d,Sbtm = %d,Sside = %d,Sttl = %d\n"
    //        ,j,cy[j].R,cy[j].H,cy[j].Sbtm,cy[j].Sside,cy[j].Sttl);
    //}
    qsort(cy,n,sizeof(cy[0]),cmpR);


    //for(int j = 0;j<n;j++)
    //{
    //printf("cy[%d]:R = %lld,H = %lld,Sbtm = %lld,Sside = %lld,Sttl = %lld\n"
    //        ,j,cy[j].R,cy[j].H,cy[j].Sbtm,cy[j].Sside,cy[j].Sttl);
    //}

    cylinder cyTemp[n-1];memset(cyTemp,0,(n-1)*sizeof(cylinder));
    for(int k = 0;k<n-1;k++){cyTemp[k] = cy[k+1];}

    qsort(cyTemp,n-1,sizeof(cyTemp[0]),cmpSside);
    //for(int j = 0;j<n-1;j++)
    //{
    //    printf("cyTemp[%d]:R = %lld,H = %lld,Sbtm = %lld,Sside = %lld,Sttl = %lld\n"
    //        ,j,cyTemp[j].R,cyTemp[j].H,cyTemp[j].Sbtm,cyTemp[j].Sside,cyTemp[j].Sttl);
    //}

    long long ans = cy[0].Sttl;
    for(int k = 0;k<m-1;k++)
    {
        ans+=cyTemp[k].Sside;
    }
    printf("%lld",ans);

    //cylinder cyAns[m];memset(cyAns,0,m*sizeof(cylinder));
    //cyAns[0] = cy[0];
    //qsort(cyTemp,n,sizeof(cyTemp[0]),cmp2);
    //long long ans = cyAns[0].Sttl;
    //for(int j = 0;j<n-1;j++)
    //{
    //    printf("cyTemp[%d]:R = %d,H = %d,Sbtm = %d,Sside = %d,Sttl = %d\n"
    //        ,j,cyTemp[j].R,cyTemp[j].H,cyTemp[j].Sbtm,cyTemp[j].Sside,cyTemp[j].Sttl);
    //}
    //for(int j = 1;j<m;j++)
    //{
    //    cyAns[j] = cyTemp[j-1];
    //}
    //qsort(cyAns,m,sizeof(cyAns[0]),cmp3);
    //long long Ans = cyAns[0].Sttl;
    //for(int j = 1;j<m;j++)
    //{
    //    Ans+=cyAns[j].Sside;
    //    //printf("cyAns[%d]:R = %d,H = %d,Sbtm = %d,Sside = %d,Sttl = %d\n"
    //    //   ,j,cyAns[j].R,cyAns[j].H,cyAns[j].Sbtm,cyAns[j].Sside,cyAns[j].Sttl);
    //}
    //printf("%lld",Ans);
    //for(int j = 0;j<n;j++)
    //{
    //    printf("cy[%d]:R = %d,H = %d,Sbtm = %d,Sside = %d,Sttl = %d\n"
    //        ,j,cy[j].R,cy[j].H,cy[j].Sbtm,cy[j].Sside,cy[j].Sttl);
    //}

    return 0;
}

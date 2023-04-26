int cheng(group a[],int nofa,group b[],int nofb,group re[])
{
    int i,j,k=0;
    for(i=0;i<nofa;i++)
    {
        for(j=0;j<nofb;j++)
        {
            re[k].mi=a[i].mi+b[j].mi;
            re[k].xishu=a[i].xishu*b[j].xishu;
            k++;
        }
    }
    return k;

}

int chongpai(group a[],int k,group b[])
{
    qsort(a,k,sizeof(group),cmp);
    int i,j;
    for(i=0,j=0;i<k-1;i++)
    {
        if(a[i].mi!=a[i+1].mi)
        {
            b[j].mi=a[i].mi;
            b[j].xishu=a[i].xishu;
            j++;
        }
        else
        {
            a[i+1].xishu+=a[i].xishu;
        }
    }
    b[j].mi=a[i].mi;
    b[j].xishu=a[i].xishu;
    j++;
    return j;

}
int main()
{
    int i,j;
    char fir[120],sec[120];
    group one[60],two[60],res[200],ans[60];
    memset(fir,0,sizeof(char)*120);
    memset(sec,0,sizeof(char)*120);

    while(1)
    {
        if(scanf("%s%s",fir,sec)==EOF) break;

        memset(one,0,sizeof(group)*60);
        memset(two,0,sizeof(group)*60);
        memset(res,0,sizeof(group)*200);
        memset(ans,0,sizeof(group)*60);
        
        int nof1,nof2,nofr,nofans,n0=0;
        nof1=clip(fir,one);
        /*for(i=0;i<nof1;i++)
        {
            printf("test test: one的第%d项=%d x (%d)\n",i,one[i].xishu,one[i].mi);
        }*/
        nof2=clip(sec,two);
        /*for(i=0;i<nof2;i++)
        {
            printf("test test: two的第%d项=%d x (%d)\n",i,two[i].xishu,two[i].mi);
        }*/
        nofr=cheng(one,nof1,two,nof2,res);
        nofans=chongpai(res,nofr,ans);

        for(i=0;i<nofans-1;i++)
        {
            if(ans[i].xishu!=0) {printf("%d ",ans[i].xishu);n0++;}
        }
        if(ans[i].xishu!=0) {printf("%d\n",ans[i].xishu);n0++;}
        if(n0==0) printf("%d\n",n0);
        memset(fir,0,sizeof(char)*120);
        memset(sec,0,sizeof(char)*120);
        
    }
    return 0;
}
int ws(int x)
{
    int a,i=0;
    do{
        a=x/10;
        i++;
    }while(a!=0);
    return i;
}
int cmp(const void* p1,const void* p2)
{
    int a,b;
    a=*(int*)p1;
    b=*(int*)p2;
    if(ws(a)>ws(b)) return -1;
    else if(ws(a)<ws(b)) return 1;
    else{
        if(a<b)return -1;
        else return 1;
    }
}
int main()
{
    int a[100000],i=0;
    while(scanf("%d",&a[i])!=EOF)i++;
    qsort(a,i,sizeof(int),cmp);
    for(int k=0;k<i;k++)printf("%d ",a[k]);
    return 0;
}

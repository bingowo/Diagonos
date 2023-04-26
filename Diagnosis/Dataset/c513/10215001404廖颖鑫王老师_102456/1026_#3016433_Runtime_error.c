int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return *y-*x;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a),cmp);
    int index=0;
    for(i=0;i<n;i+=2)
    {
        index+=a[i]-a[i+1];
    }
    printf("%d",index);
    return 0;
}

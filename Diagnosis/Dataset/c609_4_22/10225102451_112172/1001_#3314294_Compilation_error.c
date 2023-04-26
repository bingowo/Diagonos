#ifndef ISET_H_INCLUDED
#define ISET_H_INCLUDED
class iSet
{
        int *p;
        int set_size;
        int nums{0};
    public:
        iSet(int);
        class construction_error{};
        int capacity() const;
        iSet set_union(iSet);
        iSet intersection(iSet);
        iSet difference(iSet);
        iSet sym_dif(iSet);
        iSet& insert(int);
        iSet& erase(int);
        bool isSub(iSet) const;
        bool contains(int);
        iSet& print()  const;
        int num_size() const;
        bool empty() const;
        bool full() const;
        iSet& clear();
        iSet& init(int n,int *np);
        class init_error{};

};
iSet::iSet(int x)
{
    if(x<1)
        throw iSet::construction_error();
    p=new int[x];
    set_size=x;
}
int iSet::capacity() const
{
    return set_size;
}
int iSet::num_size() const
{
    return nums;
}
iSet& int(int n,int *np)
{
    if (n>set_size)
        throw init_error();
}
#endif // ISET_H_INCLUDED
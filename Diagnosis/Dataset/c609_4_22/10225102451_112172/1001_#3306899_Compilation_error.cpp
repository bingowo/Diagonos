#ifndef PAPERLESS_H_INCLUDED
#define PAPERLESS_H_INCLUDED
#include<vector>
#include<map>
#include<string>
#include<stack>
class paperless
{
    vector<map<string,stack<string>>> ams{10};
public:
    void submit(string,int,string);
    void discard(string,int);
    int count(int);
};
void paperless::submit(string id,int assignNo,string code)
{
    //if(ams[assignNo].find(id)!=ams[assignNo].end())

    if(assignNo>ams.size())
        ams.resize(assignNo);
    ams[assignNo][id].push(code);
}
void paperless::discard(string id,int assignNo)
{
    if(ams[assignNo].find(id)==ams[assignNo].end())
        throw 1;
    if(ams[assignNo][id].empty())
        throw 1;
    ams[assignNo][id].pop();
    if(ams[assignNo][id].empty())
    ams[assignNo].erase(id);

}
int paperless::count(int assignNo)
{
    return ams[assignNo].size();
}
#endif // PAPERLESS_H_INCLUDED
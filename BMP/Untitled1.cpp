#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct node
{
    int s_code;
    string s_name;
    node *next;
};
class AdjList
{
private:
    int s_code;
    string s_name;
    node *start;
public:
    AdjList():s_code(-1),start(NULL){}
    void createNode(int c)
    {
        cin>>s_name;
        s_code=c;
    }
    string station()
    {
        return s_name;
    }
    void addStation(int SCode,AdjList *ptr)
    {
        if(start)
        {
            node *t=start;
            while(t->next)
                t=t->next;
            node *n;
            n=new node;
            n->next=NULL;
            n->s_code=SCode;
            n->s_name=ptr->s_name;
            t->next=n;
        }
        else
        {
            node *n;
            n=new node;
            n->next=NULL;
            n->s_code=SCode;
            n->s_name=ptr->s_name;
            start=n;
        }
    }
    int StCode(string str)
    {
        if(s_name==str)
            return 1;
        else
            return -1;
    }
    void deletePerticular(int code)
    {
        if(start)
        {
            node *t=start;
            if(start->s_code==code)
            {
                start=start->next;
                delete t;
            }
            else
            {
                while(t->next->s_code==code)
                {
                    node *temp=t->next->next;
                    delete t->next;
                    t->next=temp;
                }
            }
        }
    }
    int countNode()
    {
        int count=0;
        node *t=start;
        while(t)
        {
            count++;
            t=t->next;
        }
        return count;
    }
    int adjNode(int k)
    {
        node *t=start;
        for(int i=1;i<=k;i++)
        {
                t=t->next;
        }
        return t->s_code;
    }
};
class MetroMap
{
    private:
        int n_count;
        AdjList *adj;
        int stationCode(string);
        //string stationName(int);
    public:
        MetroMap():n_count(0),adj(NULL){}
        void createMap(int);
        void addRoute(int,int);
        void Delete(int,int);
        //void findRoute(string,string);
        void findRoute(string);
        int countN(string);
};
void MetroMap::createMap(int n)
{
    n_count=n;
    adj=new AdjList[n];
    cout<<"Enter 53 Station Name"<<endl;
    for(int i=0;i<n;i++)
    {
        (adj+i)->createNode(i);
    }
}
int MetroMap::countN(string str)
{
    return (adj+stationCode(str))->countNode();
}
void MetroMap::addRoute(int S_from,int S_to)
{
    if(S_from==S_to)
    cout<<"source and destination cannot be same"<<endl;
    else
    {
        if(S_from<n_count && S_from>=0)
        {
            if(S_to<n_count && S_to>=0)
            {
                (adj+S_from)->addStation(S_to,adj+S_to);
                (adj+S_to)->addStation(S_from,adj+S_from);
            }
        }
        else
            cout<<"Invalid station code"<<endl<<"Enter station code between 0(including) and "<<n_count<<"(Excluding)"<<endl;
    }
}
int MetroMap::stationCode(string src)
{
    for(int i=0;i<n_count;i++)
    if((adj+i)->StCode(src)==1)
        return i;
    return -1;
}
void MetroMap::findRoute(string src)
{
        //DFS
        /*int count=0;
            for(int i=0;i<53;i++)
            {
                if((adj+i)->countNode()>1)
                   count++;
            }
            int rec[count];
            int y=0;
            for(int i=0;i<53;i++)
            {
                if((adj+i)->countNode()>1)
                   {
                       rec[y]=i;
                       y++;
                   }
            }*/
        bool arr[53]={false};
        stack <int>q;
        int n=stationCode(src);
        q.push(n);
        arr[n]=true;
        while(!q.empty())
        {
            int t=q.top();
            q.pop();
            cout<<(adj+t)->station()<<" ";
            if((adj+t)->countNode()==1)
                {
                    cout<<"(FinalDestination)"<<endl;
                    /*for(int z=0;z<count;z++)
                        if(arr[rec[z]]==true)
                    {

                    }*/
                }
            for(int i=0;i<(adj+t)->countNode();i++)
            {
                if(arr[(adj+t)->adjNode(i)]==false)
                {
                    q.push((adj+t)->adjNode(i));
                    arr[(adj+t)->adjNode(i)]=true;
                }
            }
        }
}
void MetroMap::Delete(int s,int j)
{
    (adj+s)->deletePerticular(j);
}
/*void MetroMap::findRoute(string src,string dst)
{

}*/
int main()
{
    MetroMap BMP;
    BMP.createMap(53);
    BMP.addRoute(0,1);
    BMP.addRoute(1,2);
    BMP.addRoute(2,3);
    BMP.addRoute(3,4);
    BMP.addRoute(6,7);
    BMP.addRoute(7,8);
    BMP.addRoute(9,10);
    BMP.addRoute(10,11);
    BMP.addRoute(11,43);
    BMP.addRoute(12,43);
    BMP.addRoute(12,13);
    BMP.addRoute(13,14);
    BMP.addRoute(14,15);
    BMP.addRoute(15,16);
    BMP.addRoute(16,17);
    BMP.addRoute(17,18);
    BMP.addRoute(18,19);
    BMP.addRoute(19,20);
    BMP.addRoute(20,21);
    BMP.addRoute(22,23);
    BMP.addRoute(24,25);
    BMP.addRoute(25,26);
    BMP.addRoute(26,27);
    BMP.addRoute(27,28);
    BMP.addRoute(28,29);
    BMP.addRoute(29,30);
    BMP.addRoute(30,31);
    BMP.addRoute(31,32);
    BMP.addRoute(32,33);
    BMP.addRoute(33,34);
    BMP.addRoute(34,35);
    BMP.addRoute(36,37);
    BMP.addRoute(37,38);
    BMP.addRoute(38,39);
    BMP.addRoute(39,40);
    BMP.addRoute(40,41);
    BMP.addRoute(41,42);
    BMP.addRoute(42,43);
    BMP.addRoute(43,44);
    BMP.addRoute(44,45);
    BMP.addRoute(45,46);
    BMP.addRoute(46,47);
    BMP.addRoute(47,48);
    BMP.addRoute(48,49);
    BMP.addRoute(49,50);
    BMP.addRoute(50,51);
    BMP.addRoute(51,52);
    BMP.addRoute(21,52);
    BMP.addRoute(23,13);
    BMP.addRoute(13,24);
    BMP.addRoute(4,42);
    BMP.addRoute(42,6);
    BMP.addRoute(5,42);
    BMP.Delete(42,5);
    cout<<BMP.countN("Raushanpura")<<endl;
    BMP.findRoute("Raushanpura");
    return 0;
}

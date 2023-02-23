#include<bits/stdc++.h>
using namespace std;
// struct pq{
//     int item;
//     int priority;
// };
vector<pair<int,int>>pq(10001);
int sze=0;

void shuffle()
{
    for(int i=0;i<sze;i++)
    {
        for(int j=i+1;j<sze;j++)
        {
            if(pq[i].first>pq[j].first)
            {
                pair<int,int>temp=pq[j];
                pq[j]=pq[i];
                pq[i]=temp;
            }

        }
    }
}

void insert(int value,int priority)
{
    if(sze==1000)
    {
        cout<<("Queue is full!!!");
        return;
    }
    pq[sze].first=priority;
    pq[sze].second=value;
    shuffle();
    sze++;
}



void dlt(int value)
{
    if(sze==0)
    {
        cout<<("Queue is empty!!!");
        return;
    }
    bool flag=false;
    for(int i=0;i<sze;i++)
    {
        if(pq[i].first==value)
        {
            flag=true;
            for(int j=i;j<sze;j++)
            {
                pq[j-1]=pq[j];
            }
        }
    }
    if(flag)
    sze--;
    else
    cout<<("Element not found");
}

int top()
{
    if(sze==0)
    {
        cout<<"Queue is empty!!!";
        return -1;
    }
    return pq[0].second;
}

int check_pq(int value)
{
    if(sze==0)
    {
        cout<<"Queue is empty!!!";
        return -1;
    }
    bool flag = false;
    for(int i=0;i<sze;i++)
    {
        if(pq[i].second==value)
        {
            flag=true;
            return pq[i].first;
        }
    }
    // if(!flag)
    return -1;
}

void display()
{
    for(int i=0;i<sze;i++)
    cout<<pq[i].second<<" ";
    cout<<"\n";
}

int  main()
{
    insert(50,2);
    insert(100,3);
    insert(30,3);
    display();
    int res=top();
    cout<<res<<endl;
    dlt(20);
    check_pq(66);
    return 0;
}
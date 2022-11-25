#include<bits/stdc++.h>
using namespace std;
struct trip
{
    char id;
    int start;
    int duration;
    int finish;
};
typedef struct trip Trip;

bool compare(Trip a,Trip b)
{
    return a.finish<b.finish;
}

int main()
{
    int m_money,n_numOfReq,x_breakTime;
    cin>>m_money>>x_breakTime>>n_numOfReq;
    Trip trips[n_numOfReq];
    for(int i=0; i<n_numOfReq; i++)
    {
        cin>>trips[i].id;
        cin>>trips[i].start;
        cin>>trips[i].duration;
        trips[i].finish=trips[i].start+trips[i].duration;
    }
    sort(trips,trips+n_numOfReq,compare);
    int total_selectedTrips=0;
    char selected_trips[n_numOfReq];
    int current =0;
    int next;
    selected_trips[total_selectedTrips]=trips[current].id;
    total_selectedTrips++;
    for(next=1; next<n_numOfReq; next++)
    {
        if(trips[current].finish+x_breakTime <= trips[next].start)
        {
            current=next;
            selected_trips[total_selectedTrips]=trips[current].id;
            total_selectedTrips++;
        }
    }
    cout<<"Profit: "<<total_selectedTrips<<" X "<< m_money<<" = "<<total_selectedTrips*m_money<<endl;
    cout<<"Chosen Tasks: "<<endl;
    for (int i=0; i<total_selectedTrips; i++)
    {
        cout<<selected_trips[i]<<endl;
    }
}

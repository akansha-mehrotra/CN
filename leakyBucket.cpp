#include <iostream>
using namespace std;
int main() {
    int capacity=0,packet=0,bsize=0,rate=0;
    char ans='y';
    cout<<"enter the bucket size : ";
    cin>>capacity;
    cout<<"enter the leaking rate : ";
    cin>>rate;
    while(ans=='y')
    {
        cout<<"\nenter the packet size : ";
        cin>>packet;
        if((bsize+packet) > capacity)
        {
            cout<<"\n buffer full at the moment ";
        }
        else if((bsize+packet) <= capacity)
        {
            bsize+=packet;
        }
        bsize-=rate;
        cout<<"remaining bucket capacity is "<<bsize;
        cout<<"\ndo you wish to keep adding packets? y/n : ";
        cin>>ans;
    }
    return 0;
}

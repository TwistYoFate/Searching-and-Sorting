/*

    Author:Deepanshu Yadav
    Handle: FireFrost/acevenom

*/
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>

#define ll long long
#define l(i,l,r) for(int i=l;i<r;i++)
#define d(i,r,l) for(int i=r;i>l;i--)
#define arr(k,m,data_type) data_type *k=new data_type[m]
#define tcloop int t;cin>>t;while(t--)
#define pa(arr,size)  for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
using namespace std;

arr(x,100001,ll);


int main(){

    set<ll> s;
     l(i,5,100001){
        l(j,5,100001){
            s.insert(2*(i+j));
            s.insert(-2*(i+j));
        }
     }

    tcloop{
        ll n,k=0;
        cin>>n;
        arr(a,n,ll);
        l(i,0,n){
            cin>>a[i];
        }

        l(i,0,n){
            if( s.find(a[i])!=s.end() )
                k++;
        }

        if(k&1)
            cout<<"Siroj"<<endl;
        else
            cout<<"Ghayeeth"<<endl;
    }
return 0;
}

/*

    Author:Deepanshu Yadav
    Handle: FireFrost/acevenom

*/
#include <iostream>
#include <vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<cstdlib>

#define ll long long
#define l(i,l,r) for(int i=l;i<r;i++)
#define dl(i,r,l) for(int i=r;i>l;i--)
#define arr(name,size) ll *name=new ll[size]
#define tcloop int t;cin>>t;while(t--)
#define pa(arr,size)  for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
ll gcd(ll a, ll b){return (b!=0? gcd(b,a%b): a);}

using namespace std;

void max_ss(ll a[],ll *dp,ll *dp2, ll n){
    ll global_max=a[0];
    dp[0]=a[0];
    dp2[0]=a[0];
    dp[1]=max(a[1],a[0]+a[1]);
    global_max=min(global_max, dp[1]);
    dp2[1]=global_max;
    l(i,2,n){
        dp[i]=max(a[i],dp[i-1]+a[i]);
        global_max=max(global_max,dp[i]);
        dp2[i]=global_max;
    }
}

void rev_max_ss(ll a[],ll *dp,ll *dp2, ll n){
    ll global_max=a[n-1];
    dp[n-1]=a[n-1];
    dp2[n-1]=a[n-1];
    dp[n-2]=max(a[n-2],a[n-1]+a[n-2]);
    global_max=max(dp[n-2],global_max);
    dp2[n-2]=global_max;
    l(i,3,n+1){
        dp[n-i]=max(a[n-i],dp[n-i+1]+a[n-i]);
        global_max=max(dp[n-i],global_max);
        dp2[n-i]=global_max;
    }
}

void min_ss(ll a[],ll *dp,ll *dp2, ll n){
    ll global_min=a[0];
    dp[0]=a[0];
    dp2[0]=a[0];
    dp[1]=min(a[1],a[0]+a[1]);
    global_min=min(global_min, dp[1]);
    dp2[1]=global_min;
    l(i,2,n){
        dp[i]=min(a[i],dp[i-1]+a[i]);
        global_min=min(global_min,dp[i]);
        dp2[i]=global_min;
    }
}

void rev_min_ss(ll a[],ll *dp,ll *dp2,ll n){
    ll global_min=a[n-1];
    dp[n-1]=a[n-1];
    dp2[n-1]=a[n-1];
    dp[n-2]=min(a[n-2],a[n-1]+a[n-2]);
    global_min=min(dp[n-2],global_min);
    dp2[n-2]=global_min;
    l(i,3,n+1){
        dp[n-i]=min(a[n-i],dp[n-i+1]+a[n-i]);
        global_min=min(global_min,dp[n-i]);
        dp2[n-i]=global_min;
    }
}


int main(){
    tcloop{
       ll n;
       cin>>n;
       arr(d,n);
       l(i,0,n)
        cin>>d[i];

        arr(max_inc,n);
        arr(rev_max_inc,n);
        arr(min_inc,n);
        arr(rev_min_inc,n);

        arr(max_exc,n);
        arr(rev_max_exc,n);
        arr(min_exc,n);
        arr(rev_min_exc,n);

        l(i,0,n){
            max_inc[i]=0;
            rev_max_inc[i]=0;
            min_inc[i]=0;
            rev_min_inc[i]=0;

            max_exc[i]=0;
            rev_max_exc[i]=0;
            min_exc[i]=0;
            rev_min_exc[i]=0;
        }

        max_ss(d,max_inc,max_exc,n);
        rev_max_ss(d,rev_max_inc,rev_max_exc,n);
        min_ss(d,min_inc,min_exc,n);
        rev_min_ss(d,rev_min_inc,rev_min_exc,n);

       // max_exc[0]=max_inc[0];
        //rev_max_exc[n-1]=rev_max_inc[n-1];
       // min_exc[0]=min_inc[0];
        //rev_min_exc[n-1]=rev_min_inc[n-1];
        l(i,1,n){
            max_exc[i]=max(max_inc[i-1],max_inc[i]);
            min_exc[i]=min(min_inc[i-1],min_inc[i]);
        }
        dl(i,n-2,n){
            rev_max_exc[i]=max(rev_max_inc[i+1],rev_max_inc[i]);
            rev_min_exc[i]=min(rev_min_inc[i+1],rev_min_inc[i]);
        }

        arr(result,n-1);

        l(i,0,n-1){
            result[i]=max( abs(max_exc[i]-rev_min_exc[i+1]) , abs(min_exc[i]-rev_max_exc[i+1]));
        }

        cout<<*max_element(result,result+n-1)<<endl;

    }
    return 0;
}


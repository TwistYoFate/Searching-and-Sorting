#include<iostream>
using namespace std;

void _merge(int* a,int l,int m,int r){

    int n1=m-l+1;
    int n2=r-m;

    int lar[n1]={},rar[n2]={};

    for(int i=0;i<n1;i++)
        lar[i]=a[l+i];
    for(int i=0;i<n2;i++)
        rar[i]=a[m+1+i];

      int i=0;
     int j=0;
     int k=l;
     while(i<n1&&j<n2){
            if(lar[i]<rar[j]){
                a[k]=lar[i];
                i++;
                k++;
            }
            else{
                a[k]=rar[j];
                j++;
                k++;
            }
     }

        while(j!=n2){
            a[k]=rar[j];
                j++;
                k++;
        }

        while(i!=n1){
            a[k]=lar[i];
                i++;
                k++;
        }
}

void msort(int *a,int l,int r){
    if(r>l){
        int m=(l+r)/2;
        msort(a,l,m);
        msort(a,m+1,r);
        _merge(a,l,m,r);
    }
}

void parray(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
}

int main(){
    int arr[10]={12,43,22,7655,123,654,13,61,48,43};
    cout<<"Original array:\n";
    parray(arr,10);
    msort(arr,0,9);
    cout<<"\n\nAfter sorting:\n";
    parray(arr,10);
return 0;
}

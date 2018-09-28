#include<iostream>
using namespace std;


//utilities
void sawp(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void parray(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
    cout<<"\n";
}

//qsort

int _partition(int* a, int low, int high){

        //fix pivot
        int pivot=*(a+high);
        //initialize i for smaller values than pivot
        int i=low-1;

        //main loop
        for(int j=low;j<=high;j++){
            if(*(a+j)<=pivot){
                i++;
                sawp((a+i),(a+j));
            }
        }

            return(i);
}

void qsort(int* a,int low, int high){
    if(low<high){
        int pivot=_partition(a,low,high);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,high);
    }
}

int main(){
   int arr[10]={12,43,22,7655,123,654,13,61,48,43};
    cout<<"Original array:\n";
    parray(arr,10);
    qsort(arr,0,9);
    cout<<"\n\nAfter sorting:\n";
    parray(arr,10);

return 0;
}

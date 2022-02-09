#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;
const int N = 1e5+10;
int a[N];

void merge(int l, int r, int mid){
    int sizeOfLeftArray = mid-l+1;
    int leftArray[sizeOfLeftArray+1];
    int sizeOfRightArray = r-mid;
    int rightArray[sizeOfRightArray+1];
    
    for(int i=0; i<sizeOfLeftArray;i++){
        leftArray[i]=a[i+l];
    }
    for(int i=0; i<sizeOfRightArray;i++){
        rightArray[i]=a[i+mid+1];
    }
    leftArray[sizeOfLeftArray]=INT_MAX;
    rightArray[sizeOfRightArray]=INT_MAX;
    
    int leftIndex=0;
    int rightIndex=0;
    for(int i=l; i<=r;i++){
        if(leftArray[leftIndex]<=rightArray[rightIndex]){
            a[i]=leftArray[leftIndex];
            leftIndex++;
        }else{
            a[i]=rightArray[rightIndex];
            rightIndex++;
        }
    }
}

void mergeSort(int l, int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,r,mid);
}

int main()
{
    int n;
    std::cin>>n;
    
    for(int i=0; i<n; i++){
        std::cin>>a[i];
    }
    mergeSort(0,n-1);
    cout<<"\n The sorted array"<<endl;
    for(int i=0; i<n; i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}

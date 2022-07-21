#include<iostream>
using namespace std;
void insert (int arr[] , int i)
{
    int temp = arr[i];
    while(i>1 && temp>arr[i/2])
    {
       arr[i]=arr[i/2];
       i=i/2;
    }
    arr[i]=temp;

}
void createHeap(int arr[])
{
    for(int i=2;i<8;i++)
    {
        insert(arr,i);
    }
}

 void Delete(int arr[],int n)  //heap sort code
 {
     int x=arr[1];
     arr[1]=arr[n];
     int  i=1; int j=2*i;
     while(j<n-1)
     {
        if(arr[j+1]>arr[j])
        {
            j++;
        }
        if(arr[i]<arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
            j=2*j;
        }

     }
     arr[n]=x;
 }

 void heapify()
 {
     int a[]={5,10 ,30 ,20 ,35,40 ,15};
     for(int i=7/2-1;i>=0;i--)
     {
         int j=2*i+1;
         while(j<7-1)
         {
         if(a[j+1]>a[j])
         {
             j=j+1;
         }
         if(a[i]<a[j])
         {
             swap(a[i],a[j]);
             i=j;
             j=2*i+1;
         }
         else break;
         }
     }

     for(int i=0;i<7;i++)
     cout<<a[i]<<"  " ;
 }
int main()
{
    //int  arr[8];
    // arr[0]=0;
    // arr[1]=2;
    // for(int i=2;i<8;i++)cin>>arr[i];
    // //createHeap(arr);
    // //for(int i=1;i<8;i++)cout<<arr[i]<<" ";
    // //cout<<endl<<"After delete ";
    // int nm=8;
    // for(int i=1;i<nm;i++)
    // {
    //    Delete(arr,nm-i);
    // }
 
    //for(int i=1;i<8;i++)cout<<arr[i]<<" ";
    heapify();
    
}
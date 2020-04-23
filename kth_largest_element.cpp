//
//  kth_largest_element.cpp
//
//  Created by omlenka on 23/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
    int *heap;
    int heapsize;
public:
    MaxHeap(vector<int> &v)
    {
        heapsize = int(v.size());
        heap = &v[0];
    }
    
    int left(int i)
    {
        int l = 2*i+1;
        if(l >= heapsize)
            return -1;
        return l;
    }
    
    int right(int i)
    {
        int r = 2*i+2;
        if(r >= heapsize)
            return -1;
        return r;
    }
    int parent(int i)
    {
        if(i >= 1)
            return (i-1)/2;
        else
            return -1;
    }
    void printHeap()
    {
        for(int i = 0;i<heapsize;i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    void Heapify(int i);
    int getMax(){return heap[0];}
    void deleteMax();
};

void MaxHeap::Heapify(int i)
{
    if(i < 0)
        return;
    
    int greater = i;
    if(left(i) != -1 && heap[left(i)] > heap[i])
        greater = left(i);
    if(right(i) != -1 && heap[right(i)] > heap[greater])
        greater = right(i);
    
    if(heap[greater] > heap[i])
    {
        swap(heap[greater], heap[i]);
    }
    Heapify(i-1);
}

void MaxHeap::deleteMax()
{
    swap(heap[0], heap[heapsize-1]);
    heapsize--;
    if(parent(heapsize-1) != -1)
        Heapify(parent(heapsize-1));
}

int findKthLargest(vector<int>& nums, int k)
{
    MaxHeap *H = new MaxHeap(nums);
    H->Heapify(H->parent(int(nums.size()-1)));
    H->printHeap();
    k--;
    while(k--)
    {
        H->deleteMax();
        H->printHeap();
    }
    
    return H->getMax();
}

int main()
{
//    vector<int> v = {3,2,3,1,2,4,5,5,6};
    vector<int> v = {3,2,1,5,6,4};
    cout << findKthLargest(v, 2);
    return 0;
}

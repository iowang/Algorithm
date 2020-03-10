/*
    堆排序，要涉及到建堆，删除元素，插入元素，排序
    以大根堆为例子，左孩子是2i,右孩子是2i+1,下标从1开始
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=100;
int heap[maxn],n;
// 向下调整元素，low是要调整元素的下标，high一般是最后一个元素的下标
void downAdjust(int low,int high){
    int i=low,j=2*i;//这是先看左孩子是否大于自己
    while(j<=high){
        if((j+1<=high) && (heap[j+1]>heap[j])){
            //如果右孩子的值比左孩子的值大，并且存在的话就把右孩子赋值给j
            j=j+1;
        }
        // 如果自己比自己的孩子小，就需要交换这两个值，i和j同时也应该改变
        if(heap[i]<heap[j]){
            swap(heap[i],heap[j]);
            i=j;//始终保持i为要调整的节点
            j=2*i;
        }else{
            break;
        }
    }
}

// 建堆
void createHeap(){
    for(int i=n/2;i>=1;--i){
        downAdjust(i,n);
    }
}
// 删除对顶元素，用堆的最后一个元素覆盖堆顶元素，然后向下调整
void deleteTop(){
    heap[1]=heap[n--];
    downAdjust(1,n);
}
// 插入就需要向上调整元素，不断与自己父亲元素比较
void upAdjust(int low,int high){
    int i=high,j=i/2;
    while(j>=low){
        if(heap[i]>heap[j]){
            swap(heap[i],heap[j]);
            i=j;
            j=i/2;
        }else{
            break;
        }
    }
}
void insert(int x){
    heap[++n]=x;
    upAdjust(1,n);
}
// 堆排序，从小到大顺序，建好堆之后可以保证对顶元素最大，就把堆顶元素和最后没排好序元素交换
// 再让堆顶元素向下调整就可以得到有序的数组了
void heapSort(){
    createHeap();
    for(int i=n;i>=1;--i){
        swap(heap[1],heap[i]);
        downAdjust(1,i-1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>heap[i];
    }
    heapSort();
    for(int i=1;i<=n;i++){
        if(i-1) cout<<" ";
        cout<<heap[i];
    }
    cout<<endl;
    return 0;
}
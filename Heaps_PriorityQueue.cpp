#include<iostream>
using namespace std;

class Heap {

    public:

    int arr[101];
    int size ;

    Heap(){
        arr[0] = -1;
        size =0;
    }

    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[index], arr[parent]);
            }else{
                return;
            }
        }

    }

    void deleteNode (){
        // cout<<"Swap the root node with deleting Node "<<endl;

        // Swap Node before deleting
        arr[1] = arr[size];
        size--;

        int i =1;

        while(i < size){
            int leftchild = 2*i;
            int Rightchild = 2*i + 1;

            if(leftchild < size && arr[leftchild] > arr[i]){
                swap(arr[i], arr[leftchild]);
                i = leftchild;

            }else if(Rightchild < size && arr[Rightchild] > arr[i]){
                swap(arr[i], arr[Rightchild]);
                i = Rightchild;

            }else{
                return;
            }
        }
    }

    void print(){
        // cout<<arr[0]<<" ";
        for(int i =1; i<= size; i++){
            cout<<arr[i]<<" ";
        }
    }

};

int main(){

    Heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(52);

    h.print();
    cout<<endl;
    h.deleteNode();
    h.print();

    return 0;
}

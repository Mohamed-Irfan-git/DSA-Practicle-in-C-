#include <stdio.h>

int main(){

    int arr[] = {10,2,5,3,9,8,15};

    int n = sizeof(arr)/sizeof(arr[0]);
    

    // this is ver intitutive method
    // for(int i =1;i < n;i++){
        
    //     for(int j=i;j>0;j--){
    //         if(arr[j] < arr[j-1]){
    //             int temp = arr[j];
    //             arr[j] = arr[j-1];
    //             arr[j-1] = temp;
    //         }

    //     }

    // }

    //this is very standard method
    for(int i =1;i < n;i++){
        int key = arr[i];
        int j = i-1;
        
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;

    }



    for (int i = 0; i <n; i++){
        printf("%d ",arr[i]);
    }
}
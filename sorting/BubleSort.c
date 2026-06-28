#include <stdio.h>

int main(){
    int arr[] = {10,2,5,3,9,8,15};

    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n-1; i++){
        int state = 0;

        for(int j =0;j<n-i;j++){

            if(arr[j+1] < arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                int state = 1;
            }

        }
        if(state){
            break;
        }
        
    }
    for (int i = 0; i <n; i++){
        printf("%d ",arr[i]);
    }
    
     
}
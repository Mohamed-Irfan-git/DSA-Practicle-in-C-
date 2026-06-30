#include <stdio.h>

int main(){
    int arr[] = {10,2,5,3,9,8,15};

    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++){
        int mini = i;

        for(int j =i;j<n;j++){
            if(arr[mini] > arr[j]){
                mini = j;
            }

        }
        if(mini != i){
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
        
    }
    for (int i = 0; i <n; i++){
        printf("%d ",arr[i]);
    }
    char str [50];
    fgets(str,sizeof(str),stdin);
    
     
}
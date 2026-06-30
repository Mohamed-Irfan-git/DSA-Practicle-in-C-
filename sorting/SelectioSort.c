#include <stdio.h>

int main(){
    int arr[] = {10 ,15 ,9 ,8 ,7 ,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<n;i++){
        int mini = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }

        if(mini != i){
            int temp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = temp;
        }

    }

    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }


    return 0;
}
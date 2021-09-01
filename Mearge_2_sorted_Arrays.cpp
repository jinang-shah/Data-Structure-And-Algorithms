void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

void merge(int arr1[], int arr2[], int n, int m) {
    int i=0,j=0;
    
    while(i<n && j<m){
        if(arr1[i]<=arr2[j])
            i++;
        else{
            swap(&arr1[i],&arr2[j]);
            
            
            
            int temp=j;
            while(arr2[temp]>arr2[temp+1]   &&  temp<m-1){
                swap(&arr2[temp],&arr2[temp+1]);
                temp++;
            }
            i++;
        }     
    }
}
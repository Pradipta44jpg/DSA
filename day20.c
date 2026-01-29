void merge(int* a, int nums1Size, int m, int* b, int nums2Size, int n) {
    int index=m+n-1;
    int i=m-1;
    int j=n-1;
    while(j>=0 && i>=0){
        if(a[i]>b[j]){
            a[index]=a[i];
            index--;
            i--;
        }
        else{
            a[index]=b[j];
            index--;
            j--;
        }

    }
    while(j>=0){
        a[index]=b[j];
        index--;
        j--;
    }
}
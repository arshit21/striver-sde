class Solution {
    public:
    long long int merge(long long int arr[], long long int l, long long int m, long long int r)
    {   
        long long int i, j, k;
        long long int lengthleft = m-l+1;
        long long int lengthright = r-m;
        long long int count = 0;
        
        long long int arrLeft[lengthleft], arrRight[lengthright];
        
        for(long long int a = 0; a < lengthleft; a++){
            arrLeft[a] = arr[l+a];
        }
        for(long long int a = 0; a < lengthright; a++){
            arrRight[a] = arr[m+1+a];
        }
        
        i = 0;
        j = 0;
        k = l;
        
        while(i < lengthleft && j < lengthright){
            if(arrLeft[i] <= arrRight[j]){
                arr[k] = arrLeft[i];
                i++;
                k++;
            }
            else{
                arr[k] = arrRight[j];
                j++;
                k++;
                count = count + lengthleft - i;
            }
        }
        
        while(i < lengthleft){
            arr[k] = arrLeft[i];
            i++;
            k++;
        }
        while(j < lengthright){
            arr[k] = arrRight[j];
            j++;
            k++;
        }
        return count;
    }
    public:
    long long int mergeSort(long long int arr[], long long int l, long long int r)
    {   
        long long int count = 0;
        if(l < r){
            long long int m = (l+r)/2;
            count += mergeSort(arr, l, m);
            count += mergeSort(arr, m+1, r);
            count += merge(arr, l, m, r);
        }
        return count;
    }
  public:
    long long int inversionCount(long long int arr[], int n) {
        return mergeSort(arr, 0, n-1);
    }
};
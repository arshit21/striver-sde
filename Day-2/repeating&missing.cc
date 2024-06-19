class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        int a = 0;
        int b = 0;
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] == arr[i+1]){
                b = arr[i];
            }
            else if(arr[i+1] != arr[i] + 1){
                a = arr[i]+1;
            }
        }
        if(a == 0){
            if(arr[0] != 1){
                a = 1;
            } 
            else{
                a = arr.size();
            }
        }
        
        vector<int> vec{b, a};
        return vec;
    }
};
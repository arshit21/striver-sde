class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> Row1 = {1};
        vector<int> Row2 = {1, 1};

        vector<vector<int>> Pascal;
        Pascal.push_back(Row1);
        if(numRows == 1){
            return Pascal;
        }
        Pascal.push_back(Row2);
        if(numRows == 2){
            return Pascal;
        }
        
        for(int i = 2; i < numRows; i++) {
            int rowSize = i+1;
            vector<int> nextRow;
            nextRow.push_back(1);

            for(int j = 1; j < rowSize-1; j++){
                int ele;
                ele = Pascal[i-1][j-1] + Pascal[i-1][j];
                nextRow.push_back(ele);
            }

            nextRow.push_back(1);

            Pascal.push_back(nextRow);
            
        }

        return Pascal;
    }
};
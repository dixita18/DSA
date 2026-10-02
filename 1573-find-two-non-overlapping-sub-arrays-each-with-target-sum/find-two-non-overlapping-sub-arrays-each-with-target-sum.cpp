class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i =0;
        int j =0;
        int n= arr.size();

        int currSum=0;
        int bestminlen=INT_MAX;
       int result= INT_MAX;

        vector<int>bLt(n,INT_MAX);

        while(j<n){
            currSum+=arr[j];

            while(i<j&&currSum>target){
                currSum-=arr[i];
                i++;
            }
            if(currSum==target){
                int len = j-i+1;

            

            if(i>0&&bLt[i-1]!=INT_MAX){
              result=min(result,len+bLt[i-1]);
            }
            bestminlen=min(bestminlen,len);
            }
           bLt[j]=bestminlen;
           j++;
        }
        return result==INT_MAX?-1:result;
    }
};
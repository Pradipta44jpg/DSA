int minimumCost(int* nums, int numsSize) {
    int cost=0;
     int ans = INT_MAX;
    for(int i=1;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            cost=nums[0]+nums[i]+nums[j];
            if(cost<ans) 
            ans=cost;
        }
    
    }
    return ans;
   
}
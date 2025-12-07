class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> um;
        for(int i : nums) um[i]++;
        vector<int> ans;
        for( auto pair : um)
        {
            if(pair.second > nums.size()/3) ans.push_back(pair.first);
        }
        return ans;
        
    }
};
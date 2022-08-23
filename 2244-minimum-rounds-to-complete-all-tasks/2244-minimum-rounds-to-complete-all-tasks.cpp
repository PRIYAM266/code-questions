class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
	
	// First calculate frequency of each element.
	
    for(int i=0;i<tasks.size();++i){
        mp[tasks[i]]++;
    }
	// If any element frequency is 1 then return -1 otherwise calculate minimum rounds required to complete all    the tasks.
	
    int ans=0;
    for(auto &x: mp){
        if(x.second==1){
            return -1;
            break;
        }
        else{
        
            int div=x.second/3;
            int mod=x.second%3;
			
            if(mod==0){
                ans+=div;
            }
			
		
			
            else if(mod==2){
                ans+=(div+1);
            }
			
			
            else{
                ans+=((div-1)+2);
            }

        }
    }
    return ans;
    }
};
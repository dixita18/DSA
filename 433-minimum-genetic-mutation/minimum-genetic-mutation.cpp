class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<string>q;
        q.push(startGene);

        int mutations=0;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                string curr =q.front();
                q.pop();

                if(curr==endGene){
                    return mutations;
                }
                for (int i = 0; i < curr.size(); i++) {
                    char original = curr[i];
                for(char ch :string("ACGT")){
                    curr[i]=ch;

                    if(st.count(curr)){
                        q.push(curr);
                        st.erase(curr);
                    }
                }
                curr[i]=original;
            }
            }
            mutations++;
        
        }
        return -1;
    }
};
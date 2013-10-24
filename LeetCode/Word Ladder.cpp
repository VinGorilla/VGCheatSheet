// Word Ladder 

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        int ret = 0;
        if(start == end) return ret+2;
        
        queue<string> q;
        q.push(start);
        
        unordered_set<string> visited;
        visited.insert(start);
        
        int l1 = 1, l2 = 0;
        
        while(!q.empty()) {
            string f = q.front();
            q.pop();
            --l1;
            
            for(int i = 0; i < start.size(); ++i) {
                for(int j = 0; j < 26; ++j) {
                    string t = f;
                    t[i] = j + 'a';
                    if(t == end) return ret + 2;
                    if(dict.find(t) != dict.end() && visited.find(t) == visited.end()) {
                        q.push(t);
                        visited.insert(t);
                        ++l2;
                    }
                }
            }
            
            if(l1 == 0) {
                l1 = l2;
                l2 = 0;
                ++ret;
            }
        }
        
        return 0;
    }
};
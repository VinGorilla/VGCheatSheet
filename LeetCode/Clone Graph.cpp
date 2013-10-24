// Clone Graph

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        UndirectedGraphNode *cloneNode = new UndirectedGraphNode(node->label);
        
        queue<UndirectedGraphNode *> q;
        q.push(node);
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        map[node] = cloneNode;
        
        UndirectedGraphNode *cur = NULL;
        
        while(!q.empty()) {
            UndirectedGraphNode *&f = q.front();
            cur = map[f];
            
            vector<UndirectedGraphNode *>::iterator it = f->neighbors.begin();
            while(it != f->neighbors.end()) {
                if(!map[*it]) {
                    UndirectedGraphNode *newNode = new UndirectedGraphNode((*it)->label);
                    map[*it] = newNode;
                    q.push(*it);
                }
                cur->neighbors.push_back(map[*it]);
                it++;
            }
            
            q.pop();
        }
        
        return cloneNode;
    }
};
#include<stdc++/bits.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbours;
    Node() {
        val = 0;
        neighbours = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbours = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbours) {
        val = _val;
        neighbours = _neighbours;
    }
};

/*
I will make an adjecency list
1 -> {2,4}
2 -> {1,3}
3 -> {2,4}
4 -> {1,3}

traverse the adjecency list and create the nodes 

*/
class Solution {
public:
	//creating clones in DFS manner
	 unordered_map<Node*,Node*> hMap; //old,new
		Node* clone(Node* node){
			if(hMap.find(node)!= hMap.end()){
				return hMap.at(node);
			}
			Node *copy = new Node(node->val);
			hMap[node] = copy;
			vector<Node*> neigh;
			
			for(auto x:node->neighbors){
				neigh.push_back(clone(x));
			}
			copy->neighbors = neigh;
			return copy;
		}
    Node* cloneGraph(Node* node) {
    	if(node == NULL) return NULL;
    	if(node-> neighbors.size() == 0){
	    	Node* newClone = new Node(node->val);
	    	return newClone;
    	}
			return clone(node);
    }
};

int main(){

	return 0;
}

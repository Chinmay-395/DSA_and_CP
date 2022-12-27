/*given a pair of task we need to figure whether they can be performed
NOTE: check with the interviewer whether all the pairs are unique
//for which we need to figure out the cyclic dependency
//[1,2],[4,3],[2,4],[4,1]

 [1,2]
 if 2 is performed that means 1 is performed before; hmap<1>
 
 [4,3] 
 if 3 is performed that means 4 is performed before; hmap<1,4>
 
 [2,4]
 if 4 is perfomed that means 2 is performed before; hmap<1,4,2>
 
 [4,1]
 if 1 is performed that means 1 is performed before;
 but 1 is already present in hmap therefore there is 
 a cyclic dependency
 
 [2,1],[1,0]
 if 1 is performed that means 2 is performed before; hmap<2>
 
 [1,0]
 if 0 is performed that means 1 is performed before; hmap<2,1>
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq){
    if(prereq.size()==0)return true;
    unordered_map<int,int> hMap;
  	hMap.insert(make_pair(prereq[0][1],prereq[0][0]));
    for(int i=1; i<prereq.size(); i++){
    	if(hMap.find(prereq[i][1]) != hMap.end()){
    		return false;
    	}
    	hMap.insert(make_pair(prereq[i][1],prereq[i][0]));
    	
    }
    return true;
        
    }
};

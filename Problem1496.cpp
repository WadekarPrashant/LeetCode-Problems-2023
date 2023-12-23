class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>> visited;
        pair<set<vector<int>>::iterator, bool> res;
        int i = 0, j = 0;
        
        visited.insert({0, 0});
        
        for(char c : path){
            switch(c){
                case 'N':
                    res = visited.insert({--i, j});
                    if(!res.second) return true;
                    break;
                case 'S':
                    res = visited.insert({++i, j});
                    if(!res.second) return true;
                    break;
                case 'W':
                    res = visited.insert({i, --j});
                    if(!res.second) return true;
                    break;
                case 'E':
                    res = visited.insert({i, ++j});
                    if(!res.second) return true;
                    break;
            }
        }
        
        return false;
    }
};

class Robot {
public:
    int w, h, x, y, dir;
    int cycle;
    
    vector<string> dirs = {"East", "North", "West", "South"};
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= cycle;
        
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3;
            return;
        }
        
        while (num--) {
            int nx = x + moves[dir].first;
            int ny = y + moves[dir].second;
            
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
                dir = (dir + 1) % 4;
                nx = x + moves[dir].first;
                ny = y + moves[dir].second;
            }
            
            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};
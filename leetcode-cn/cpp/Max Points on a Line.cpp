/*
Q-URL: https://leetcode-cn.com/problems/max-points-on-a-line/
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
class Solution {
private:
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }
    
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        
        map<pair<int,int>, int> mps;
        for(int i = 0; i < points.size(); ++i)
        {
            int cnt = 0, samepoints = 0;
            for(int j = i + 1; j < points.size(); ++j)
            {
                auto dx = points[i].x - points[j].x, dy = points[i].y - points[j].y;
                if(!dx && !dy) ++samepoints;
                else
                {
                    auto d = gcd(dx, dy);
                    cnt = max(cnt, ++mps[{dx/d, dy/d}]);
                }
            }
            res = max(res, samepoints + cnt + 1);
            mps.clear();
        }
	    return res;
    }
};

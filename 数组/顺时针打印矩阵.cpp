/**
 * 以螺旋顺序输出矩阵元素（顺时针）
/*
确定某一层矩形对角点坐标，(begin,begin)、(rowend,colend)
扫描顺序如下：
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return {};
        int col = matrix[0].size();
        if(col == 0) return {};
        vector<int> res;
        int left = 0, right = col-1, top = 0, bottom = row-1;
        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            if(top > bottom) {
                break;
            }
            for(int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if(right < left) break;
            for(int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(top > bottom) break;
            for(int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
            left++;
        }
        return res;
    }
};


//给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        if(n < 1) return res;
        int left = 0;
        int bottom = n-1;
        int right = n-1;
        int top = 0;
        int val = 1;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) res[top][i] = val++;
            top++;
            if(top > bottom) break;
            for(int i = top; i <= bottom; i++) res[i][right] = val++;
            right--;
            if(left > right) break;
            for(int i = right; i >= left; i--) res[bottom][i] = val++;
            bottom--;
            if(top > bottom) break;
            for(int i = bottom; i >= top; i--) res[i][left] = val++;
            left++;
        }
        return res;
    }
};
/**
 * 问题：在有序矩阵中查找某数（每行增序，且行首元素大于前一行的行尾元素，蛇形有序）
  方法：将二维数组看成一维数组用二分查找即可
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        if(col == 0) return false;
        int left = 0;
        int bottom = row-1;
        while(bottom >= 0 && left < col) {
            if(matrix[bottom][left] > target) {
                bottom--;
            }else if(matrix[bottom][left] < target) {
                left++;
            }else return true;
        }
        return false;
    }
};

//240
/**
 * 问题：有序矩阵中查找
 */
 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        if(col == 0) return false;
        int left = 0;
        int bottom = row-1;
        while(bottom >= 0 && left < col) {
            if(matrix[bottom][left] > target) {
                bottom--;
            }else if(matrix[bottom][left] < target) {
                left++;
            }else return true;
        }
        return false;
    }
};
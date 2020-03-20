//给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
/**
 * 将矩阵中为0的元素其整行整列均置为0，要求in-place解决
 * 方法：第一次扫描，用首行首列存储状态，第二次扫描，根据这些状态把相应的位置置为0
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool fr = false;
        bool fc = false; //用于表示首行是否存在0元素的标识
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                    if(i == 0) fr = true;
                    if(j == 0) fc = true;
                }
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(fr) {
            for(int j = 0; j <col; j++) matrix[0][j] = 0;
        }
        if(fc) {
            for(int i = 0; i < row; i++) matrix[i][0] = 0;
        }
    }
};
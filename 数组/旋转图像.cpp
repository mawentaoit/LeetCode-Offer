/**
 * 问题：旋转图像(要求：原地顺时针的旋转90)
 * 顺时针旋转方法：先上下翻转，再沿对角线翻转
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        reverse(matrix.begin(), matrix.end()); //stl函数，对每列reverse
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i+1; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
/**
 * 逆时针旋转：先左右翻转，再沿对角线翻转
 */
void anti_rotate(vector<vector<int>>& matrix) {
    for(auto vi : matrix) reverse(vi.begin(), vi.end()); //对每行reverse,故要遍历matrix
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = i+1; j < matrix[i].size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
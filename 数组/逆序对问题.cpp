/**
 * 题目描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
 * 思路：暴力法：遍历数组，比较元素与所有后面元素是否构成逆序对O(n^2)
 */
class Solution{
private: 
    long result; //结果变量
public:
    int InversePairs(vector<int> data) {
        result = 0; //初始化
        if(data.empty()) return 0;
        mergeSort(data, 0, data.size() - 1); //按从大到小归并排序并统计逆序对个数
        return result%1000000007; //取模输出，防止输出太大
    }
private:
    void mergeSort(vector<int>& a, int begin, int end) {
        if(begin >= end) return; //递归的出口
        int mid = (begin + end)/2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid+1, end);
        merge(a, begin, mid, end);
    }
    void merge(vector<int>& a, int begin, int mid, int end) {
        int temp[end-begin+1] = {0};
        int i = begin, j = mid+1, k = 0; //左子树，右子树，临时数组起始索引
   while(i <= mid && j <= end) //注意范围
        {
            if(a[i] > a[j])
            {
                temp[k++] = a[i++]; //这里从大到小排序，方便判断逆序对
                //合并的是有序子数组（从大到小），故a[i]>a[j]时，也有a[i]>a[j]~a[end],均可构成逆序对（a[i]在左边，a[j]在右边）
                result += end - j + 1;
            }
            else
                temp[k++] = a[j++];
        }
        while(i <= mid) temp[k++] = a[i++]; //复制剩余元素
        while(j <= end) temp[k++] = a[j++];
       
        for(int i = begin, k = 0; i<=end && k<temp.size(); i++,k++)//复制临时数组元素到原数组
        {
            a[i] = temp[k];
        }    
    }
};
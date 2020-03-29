/**
 * 输入n个整数，找出其中最小的k个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1，2，3，4
 */
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k <= 0 || k > input.size()) return vector<int>(); //处理非法输入
        nth_element(input.begin(), input.begin()+k-1, input.end());
        vector<int> result(input.begin(), input.begin()+k); //构造结果向量
        return result;
    }
};
/**
 * 掌握
 * 方法一：基于parition(快排中有用到，stl中也有，但是还是自己实现较好)
 * 多次partition直到枢纽位置为k即可
 */
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k <= 0 || k > input.size()) return vector<int>(); //处理异常输入
        int left = 0, right = input.size() - 1;
        int pivot_pos;
        while(left <= right) //类似二分查找法
        {
            pivot_pos = partition(input, left, right);
            if(pivot_pos < k-1) 
                left = pivot_pos+1;
            else if(pivot_pos > k-1)
                right = pivot_pos-1;
            else break; //此题要求的是返回最小的前k个数，如果仅返回最小的第k个数，直接在这里return a[pivot_pos]即可
        }
        vector<int> result(input.begin(), input.begin()+k); //构造结果向量
        return result;
    }
private:
    int partition(vector<int>& a, int left, int right) {
        //随机初始化枢轴
        int pivotpos = rand()%(right - left + 1) + left; //产生[left, right]之间的数
        swap(a[pivotpos], a[left]);
        int pivot = left; //枢轴位置
        while(left < right) {
            while(left < right && a[right] >= a[pivot]) right--; 
            while(left < right && a[left] <= a[pivot]) left++;
            swap(a[left], a[right]);
        }
        swap(a[left], a[right]); //将枢纽移动到位
        return left;
    }
};
/**
 * 掌握:
 * 方法二：使用堆或者红黑树(平衡二叉搜索树)
 * 用容器存储k个数，遍历输入向量过程中不断更新容器内的数(如果当前数小于容器中的最大值，则插入该数，删除原节点最大数)
 */
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k <= 0 || k > input.size()) return vector<int>();
        //仿函数中greater<T>模板，从大到小排序
        multiset<int, greater<int>> leastNums;
        for(int ai : input) {
            if(leastNumbs.size() < k) leastNums.insert(ai);
            else {
                //第一个数为最大数
                multiset<int, greater<int>>::iterator greatest_it = leastNums.begin();
                if(ai < *greatest_it) {
                    leastNums.erase(greatest_it); //删除原最大值
                    leastNums.insert(ai);//插入新元素(logk复杂度)
                }
            }
        }
        return vector<int>(leastNums.begin(), leastNums.end()); //返回结果向量(前k个最小的数)
    }
};
//扩展：第k个最大的数
//暴力法：直接sort,O(nlogn)
/**
 * 方法一：基于partition函数
 * 多次partition知道枢纽位置为k即可
 * 缺点：会改变输入数组的元素位置
 */
class Solution{
public: 
    int findKthLargest(vector<int>& a, int k) {
        if(a.empty() || k <= 0 || k > a.size()) return 0; //处理异常输入
        int left = 0, right = a.size() - 1;
        int pivot_pos;
        while(left <= right) //类似二分查找法
        {
            pivot_pos = partition(a, left, right);
            if(pivot_pos < k-1) 
                left = pivot_pos + 1;
            else if(pivot_pos > k-1) 
                right = pivot_pos - 1;
            else return a[pivot_pos];
        }
    }
private:
    int partition(vector<int>& a, int left, int right) {
        srand(time(nullptr));
        int pivotpos = rand()
    }
};
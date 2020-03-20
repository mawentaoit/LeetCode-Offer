/**
 * 问题：某个数出现一次，其他数出现两次，找出这个数
 * 法1：异或，一个数异或同一个数两次，还是那个数
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for(int i = 0; i < len; i++) {
            res = res^nums[i];
        }
        return res;
    }
};
//法2；哈希
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(++mp[nums[i]] == 2) mp.erase(nums[i]);
        }
        return mp.begin()->first; //返回单数的key
    }
};

/**
 * 扩展：某个数出现一次，其他数出现三次，找出这个数(要求O(n), O(1))(具有一般性，某个数出现一次，其他数出现5，7均可用这种方法)
 * 方法：用一个32位大小的数组存储所有数各个比特位的和(不进行进位)
 * 如果每位的和对3取余就能得到那个只出现一次的数在该位上的数字
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0;i < 32;++i){
            int sum = 0;
            for(int j = 0;j < nums.size();++j){
                sum += (nums[j] >> i) & 1;
            }
            res ^= (sum % 3) << i;
        }
        return res;
    }
};
/**
 * 问题：有两个数出现一次，其他数出现两次，找出这个数(要求O(n),O(1))
 * 方法：
 * 1.所有数异或，相同数异或得0，所以最后结果相当于对这两个数异或，由于不相同，必有某一比特位为1
 * 2.按此位是否为1将数组分为两个子数组，则这两个数被分到不同的子数组里，这样将问题转换为一个数组中只有一个数出现一次，其他数出现两次的问题
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_value = 0;
        for(int num:nums) xor_value ^= num; //得到所有的数异或值
        int bit_mask = ~(xor_value - 1) & xor_value;
        vector<int> res = {0,0};
        for(int num:nums) { //分成两个子数组分别进行异或
            if((num&bit_mask) == 0) //注意：
            {
                res[0] ^= num;
            }
            else res[1] ^= num;
        }
        return res;
    }
};
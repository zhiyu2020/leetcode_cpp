/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
 public:
     int climbStairs(int n) {
        // BF 超时了
        int temp(0), a(1), b(2);
        if (n == 1) return a;
        else if (n == 2) return b;
        //else return climbStairs(n - 1) + climbStairs(n - 2); BF 暴力算法
        else {
            // temp = a + b;
            // a = b;
            // b = temp;
            // return a + b; 报错的
            // for iteration
            for(int i = 3; i < n; i++) { // 死在 i <= n = 上面了 哎
                temp = a + b;
                a = b;
                b = temp;
            }
            return a + b;
        }
        
    }


};
// @lc code=end

/*
int climbStairs(int n) {
    int a = 1, b = 1;
    while (n--)
        a = (b += a) - a;
    return a;
}
*/
/*
def climbStairs(self, n):
    a = b = 1
    for _ in range(n):
        a, b = b, a + b
    return a
*/
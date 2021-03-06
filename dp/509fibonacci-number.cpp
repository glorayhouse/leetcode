// 509. 斐波那契数
// 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 给定 N，计算 F(N)。

// 示例 1：

// 输入：2
// 输出：1
// 解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
// 示例 2：

// 输入：3
// 输出：2
// 解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
// 示例 3：

// 输入：4
// 输出：3
// 解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
//  

// 提示：

// 0 ≤ N ≤ 30

// 解法一：递归，时间复杂度：子问题个数乘以解决一个子问题需要的时间。
// 首先计算子问题个数，即递归树中节点的总数。显然二叉树节点总数为指数级别，所以子问题个数为 O(2^n)。
// 然后计算解决一个子问题的时间，在本算法中，没有循环，只有 f(n - 1) + f(n - 2) 一个加法操作，时间为 O(1)。
// 所以，这个算法的时间复杂度为二者相乘，即 O(2^n)，指数级别。
class Solution1 {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1 || N == 2) return 1;
        return fib(N-1) + fib(N-2);
    }
};

// 解法二：时间复杂度O(n)，子问题就是 f(1), f(2), f(3) ... f(n)，子问题个数为 O(n)，没有什么循环，时间为 O(1)。
// 所以，本算法的时间复杂度是 O(n)。比起暴力算法，是降维打击。
// 思路：每次算出某个子问题的答案后别急着返回，先记到「备忘录」里再返回；
// 每次遇到一个子问题先去「备忘录」里查一查，
// 如果发现之前已经解决过这个问题了，直接把答案拿出来用，不要再耗时去计算了。
// 一般使用一个数组充当这个「备忘录」，当然你也可以使用哈希表（字典），思想都是一样的。
// 
class Solution {
public:
    int fib(int N) {
        if (N < 1) return 0;
        std::vector<int> book(N + 1, 0);
        return helper(book, N);
    }

    int helper(vector<int> &book, int n) {
        if (n == 1 || n == 2) return 1;
        if (book[n] != 0) return book[n];
        book[n] = helper(book, n - 1) + helper(book, n - 2);
        return book[n];
    }
};

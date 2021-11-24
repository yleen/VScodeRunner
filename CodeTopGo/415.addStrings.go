/*
 * @lc app=leetcode.cn id=415 lang=golang
 *
 * [415] 字符串相加
 */

// @lc code=start
func addStrings(num1 string, num2 string) string {
	len1 := len(num1) - 1
	len2 := len(num2) - 1
	add := 0
	sum := ""
	for len1 >= 0 || len2 >= 0 || add != 0 {
		add1 := 0
		add2 := 0
		if len1 >= 0{
			add1 = int(num1[len1] - '0')
			len1--
		}
		if len2 >= 0{
			add2 = int(num2[len2] - '0')
			len2--
		}
		add = add1 + add2 + add
		curSum := strconv.Itoa(add % 10)
		// sum += curSum 之前写成这种形式 这样还需要反转 实际上字符串直接往前加就行了 不用这么麻烦
		sum = curSum + sum
		add = add / 10
	}
	return sum
}
// func Reverse(s string) string {
//     a := []rune(s)
//     for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
//         a[i], a[j] = a[j], a[i]
//     }
//     return string(a)
// }

// @lc code=end


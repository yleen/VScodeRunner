/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 */

// @lc code=start
func isValid(s string) bool {
	if len(s) % 2 != 0{
		return false
	}
	bracketMap := map[byte]byte{
		')':'(',
		']':'[',
		'}':'{',
	}
	// bracketMap[')'] = '('
	// bracketMap[']'] = '['
	// bracketMap['}'] = '{'
	strStack := []byte{}
	for i := 0; i < len(s); i++{
		if val, ok := bracketMap[s[i]]; ok{
			if len(strStack) > 0 && strStack[len(strStack) - 1] == val{
				strStack = strStack[:len(strStack) - 1]
			}else{
				return false
			}
		}else{
			strStack = append(strStack, s[i])
		}
	}
	return len(strStack) == 0
}

// @lc code=end


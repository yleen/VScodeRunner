/*
 * @lc app=leetcode.cn id=200 lang=golang
 *
 * [200] 岛屿数量
 */

// @lc code=start
func numIslands(grid [][]byte) int {
	rows := len(grid)
	columns := len(grid[0])
	count := 0
	for x := 0; x < rows; x++{
		for y := 0; y < columns; y++{
			if grid[x][y] == '1'{
				bfs(grid, x, y)
				count++
			}
		}
	}
	return count
}

func dfs(grid [][]byte, x, y int) {
	grid[x][y] = '0'
	rows := len(grid)
	columns := len(grid[0])
	if x - 1 >= 0 && grid[x - 1][y] == '1'{
		dfs(grid, x - 1, y)
	}
	if y - 1 >= 0 && grid[x][y - 1] == '1'{
		dfs(grid, x, y - 1)
	}
	if x + 1 < rows && grid[x + 1][y] == '1'{
		dfs(grid, x + 1, y)
	}
	if y + 1 < columns && grid[x][y + 1] == '1'{
		dfs(grid, x, y + 1)
	}
}

func bfs(grid [][]byte, x, y int){
    queue := make([]int, 0)
    queue = append(queue, x, y)
	rows := len(grid)
	columns := len(grid[0])
	grid[x][y] = '0'
    for len(queue) != 0{
        x, y = queue[0], queue[1]
        queue = queue[2:]
		if x - 1 >= 0  && grid[x - 1][y] == '1' {
			grid[x - 1][y] = '0'
			queue = append(queue, x - 1, y)
		}
		if y - 1 >= 0 && grid[x][y - 1] == '1'{
			grid[x][y - 1] = '0'
			queue = append(queue, x, y - 1)
		}
		if x + 1 < rows && grid[x + 1][y] == '1'{
			grid[x + 1][y] = '0'
			queue = append(queue, x + 1, y)
		}
		if y + 1 < columns && grid[x][y + 1] == '1'{
			grid[x][y + 1] = '0'
			queue = append(queue, x, y + 1)
		}
    }
}

//TODO 并查集
// @lc code=end


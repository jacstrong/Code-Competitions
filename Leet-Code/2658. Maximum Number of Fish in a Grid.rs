// First attempt at learning rust

impl Solution {
    fn dfs(grid: &[Vec<i32>], visited: &mut [Vec<bool>], r: usize, c: usize) -> usize {
        if grid[r][c] == 0 {
            visited[r][c] = true;
            return 0
        }

        if visited[r][c] { return 0 }

        visited[r][c] = true;

        let mut count: usize = 0;

        count += grid[r][c] as usize;

        if r > 0 {
            count += Self::dfs(grid, visited, r - 1, c);
        }
        if r < grid.len() - 1 {
            count += Self::dfs(grid, visited, r + 1, c);
        }
        if c > 0 {
            count += Self::dfs(grid, visited, r, c - 1);
        }
        if c < grid[0].len() - 1 {
            count += Self::dfs(grid, visited, r, c + 1);
        }

        return count;
    }

    pub fn find_max_fish(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut visited = vec![vec![false; cols]; rows];

        let mut maxFish = 0;

        for r in (0..grid.len()) {
            for c in (0..grid[0].len()) {
                if !visited[r][c] {
                    let numFish = Self::dfs(&grid, &mut visited, r, c);
                    if numFish > maxFish {
                        maxFish = numFish
                    }
                }
            }
        }

        return maxFish as i32
    }
}

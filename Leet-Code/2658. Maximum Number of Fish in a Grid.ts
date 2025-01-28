function findMaxFish(grid: number[][]): number {
    let visited = Array(grid.length)
        .fill(null)
        .map(() => Array(grid[0].length).fill(false));
    let maxFish = 0

    const dfs = (r: number, c: number): number => {
        if (grid[r][c] === 0) {
            visited[r][c] = true
            return 0
        }
        if (visited[r][c]) return 0
        visited[r][c] = true

        let count = 0

        count += grid[r][c]

        // up
        if (r > 0) {
            count += dfs(r - 1, c)
        }
        // down
        if (r < grid.length - 1) {
            count += dfs(r + 1, c)
        }
        // left
        if (c > 0) {
            count += dfs(r, c - 1)
        }
        // right
        if (c < grid[0].length - 1) {
            count += dfs(r, c + 1)
        }

        return count
    }

    for (let r = 0; r < grid.length; r++) {
        for (let c = 0; c < grid[r].length; c++) {
            if (!visited[r][c]) {
                const numFish = dfs(r, c)
                if (numFish > maxFish) {
                    maxFish = numFish
                }
            }
        }
    }


    return maxFish
};



import collections


def min_cost(grid):

    rows, cols = len(grid), len(grid[0])
    dp = [[float("inf")] * cols for _ in range(rows)]
    # Starting point.
    dp[0][0] = 0
                 # Right, Left, Down, Up
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]     
    arrow_cost = {
        (0, 1): 0,
        (0, -1): 1, 
        (1, 0): 1, 
        (-1, 0): 1
    }

    queue = collections.deque([(0, 0)])

    while queue:
        x, y = queue.popleft()
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols:
                new_cost = dp[x][y] + arrow_cost[(dx, dy)]
                if new_cost < dp[nx][ny]:
                    dp[nx][ny] = new_cost
                    queue.append((nx, ny))

    return dp[rows - 1][cols - 1]

if __name__ == "__main__":
    # Test case.
    grid = [
        [1, 1, 1, 1],
        [2, 2, 2, 2],
        [1, 1, 1, 1],
        [2, 2, 2, 2]
    ]
    # Expected cost: 3
    cost = min_cost(grid)
    
    print("Case #%d: %d" % (0, cost))


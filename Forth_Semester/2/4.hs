firstPosition :: [Int] -> Int -> Int
firstPosition [] _ = 0
firstPosition (x : xs) y | x /= y = 1 + firstPosition xs y
                         | x == y = 0

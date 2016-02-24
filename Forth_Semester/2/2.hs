degreeList :: Int -> [Int]
degreeList n = [2 ^ x | x <- [1..n]]

numberOfEven1 :: [Int] -> Int
numberOfEven1 list = foldr (\x y -> mod (x + 1) 2 + y) 0 list

numberOfEven2 :: [Int] -> Int
numberOfEven2 list = foldr (+) 0 (map (\x -> mod (x + 1) 2) list)

numberOfEven3 :: [Int] -> Int
numberOfEven3 list = length (filter (\x -> mod x 2 /= 1) list)

-- If length is not allowed
numberOfEven4 :: [Int] -> Int
numberOfEven4 list = foldr (\_ y -> 1 + y) 0 (filter (\x -> mod x 2 /= 1) list)

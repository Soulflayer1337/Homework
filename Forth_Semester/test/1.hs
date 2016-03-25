listOfPrimes :: [Int]
listOfPrimes = let
    helpFunction x list | check x list = helpFunction (x + 1) list
                        | otherwise = [x] ++ helpFunction (x + 1) (list ++ [x])
    check x list = or (map (\y -> (mod x y) == 0) list)
    in helpFunction 2 []
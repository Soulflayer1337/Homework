decompose' :: Int -> Int -> [[Int]]
decompose' 0 _ = [[]]
decompose' n mAdd = [x : y | x <- [1..mAdd], 
                             y <- (decompose' (n - x) (min x (n - x)))]

decompose :: Int -> IO ()
decompose n = let
        listToStr [x] = show x
        listToStr (x : xs) = show x ++ (" + " ++ listToStr xs) 
    in mapM_ (putStrLn.listToStr) (reverse $ decompose' n n)

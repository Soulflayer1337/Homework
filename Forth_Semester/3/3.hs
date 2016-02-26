findMaxCouple :: (Num a, Ord a) => [a] -> Integer
findMaxCouple l@(_:xs) = fst (head (filter (\e -> snd e == (max)) (zip [1..] sums))) where
                         sums = zipWith (+) l xs
                         max = maximum sums
                         
findPosInList :: (Eq a) => [a] -> a -> Int
findPosInList list element = foldr (setEq element) (-1) (zip [0,1..] list) where
    setEq element (index, value) oldIndex | value == element = index
                                          | otherwise        = oldIndex
                                          
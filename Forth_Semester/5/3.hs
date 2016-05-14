import Control.Monad

localMax :: Ord a => [a] -> Maybe a
localMax l1@(_ : l2@(_ : rem)) = foldl (mplus) Nothing $ zipWith3 check l1 l2 rem where
    check x y z | x < y && y > z = Just y
                | otherwise      = Nothing
localMax _ = Nothing

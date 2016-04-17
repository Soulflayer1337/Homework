data Tree a = Nil
            | Leaf a
            | Branch (Tree a) a (Tree a)
            
instance Foldable Tree where
    foldr func val Nil = val
    foldr func val (Leaf a) = func a val
    foldr func val (Branch leftTree value rightTree) = 
        foldr func (func value (foldr func val rightTree)) leftTree

treeVisit :: (Tree Int) -> [Int]
treeVisit = foldr helpFunc [] where
    helpFunc value list | value < 0 = value : list
                        | otherwise = list

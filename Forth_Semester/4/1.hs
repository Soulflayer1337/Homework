data Tree a = Nil 
            | Leaf a
            | Branch (Tree a) a (Tree a)
            
instance Foldable Tree where
    foldr func val Nil = val
    foldr func val (Leaf a) = func a val
    foldr func val (Branch leftTree value rightTree) = 
        foldr func (func value (foldr func val rightTree)) leftTree

treeSearch :: (a -> Bool) -> Tree a -> Maybe a
treeSearch cond tree = let 
    func x y | cond x    = Just x
             | otherwise = y
    in foldr func Nothing tree

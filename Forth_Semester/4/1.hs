data Tree a = Nil 
            | Leaf a
            | Branch (Tree a) a (Tree a)
            
instance Foldable Tree where
    foldr func val Nil = val
    foldr func val (Leaf a) = func a val
    foldr func val (Branch leftTree value rightTree) = 
        foldr func (func value (foldr func val rightTree)) leftTree

treeSearch :: (a -> Bool) -> Tree a -> Maybe a
treeSearch _ Nil = Nothing
treeSearch cond (Leaf val) = if (cond val)
                             then Just val
                             else Nothing
treeSearch cond (Branch leftTree val rightTree) = let 
                leftResult      = treeSearch cond leftTree
                rightResult     = treeSearch cond rightTree
                currentResult   = treeSearch cond (Leaf val)
                compare (Just a) _  = Just a
                compare _ (Just a)  = Just a
                compare _ _         = Nothing
                in compare (compare leftResult currentResult) rightResult


data Tree a = Nil
             | Leaf a
             | Branch (Tree a) a (Tree a)

helpHeight :: (Int -> Int -> Int) -> Tree a -> Int
helpHeight _ Nil = 0
helpHeight _ (Leaf _) = 1
helpHeight func (Branch l m r) = func (helpHeight func l) (helpHeight func r) + 1

getHeight :: (Ord a) => Tree a -> Int
getHeight tr = helpHeight max tr

getMinHeight :: (Ord a) => Tree a -> Int
getMinHeight tr = helpHeight min tr

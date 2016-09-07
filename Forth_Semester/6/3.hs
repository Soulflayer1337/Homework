data Tree a = Nil
            | Node (Tree a) a (Tree a)
    deriving Show

addElement :: (Ord a) => a -> Tree a -> Tree a
addElement value Nil = Node Nil value Nil
addElement value tree@(Node left val right)
    | value == val = tree
    | value < val  = Node (addElement value left) val right
    | otherwise    = Node left val (addElement value right)

removeElement :: (Ord a) => a -> Tree a -> Tree a
removeElement _ Nil =  Nil
removeElement value tree@(Node left val right)
    | value < val = Node (removeElement value left) val right
    | value > val = Node left val (removeElement value right)
    | otherwise   = let
        removeNode (Node Nil _ Nil)    = Nil
        removeNode (Node Nil _ right)  = right
        removeNode (Node left _ Nil)   = left
        removeNode (Node left _ right) = Node left (mostLeft right) (removeLeft right)
        mostLeft (Node Nil val _) = val
        mostLeft (Node left _ _)  = mostLeft left
        removeLeft tree = removeElement (mostLeft tree) tree
    in removeNode tree

searchElement :: (Ord a) => a -> Tree a -> Bool
searchElement _ Nil = False
searchElement value (Node left val right)
    | value == val = True
    | value < val  = searchElement value left
    | otherwise    = searchElement value right

treeHeight :: Tree a -> Int
treeHeight Nil = 0
treeHeight (Node left _ right) = 1 + max (treeHeight left) (treeHeight right)

treeSize :: Tree a -> Int
treeSize Nil = 0
treeSize (Node left _ right) = 1 + treeSize left + treeSize right

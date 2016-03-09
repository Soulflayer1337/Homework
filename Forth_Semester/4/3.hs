checkDifference :: Eq a => [a] -> Bool
checkDifference [] = True
checkDifference (x : xs) = notElem x xs && checkDifference xs

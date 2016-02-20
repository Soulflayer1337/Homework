supportReverse :: [a] -> [a] -> [a]
supportReverse l [] = l
supportReverse y (x : xs) = supportReverse (x : y) xs

reverse' :: [a] -> [a]
reverse' = supportReverse []
fl :: [Integer]
fl = [x + y | x <- l10, y <- [1, 7, 9]] where
     l10 = 0 : (map ((*) 10) fl)
     
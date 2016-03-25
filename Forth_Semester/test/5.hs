data Printed = 
    Book {
        name :: String,
        author :: String,
        cost :: Int
    } |
    Magazine {
        name :: String,
        year :: Int,
        number :: Int,
        cost :: Int
    }

totalCost :: [Printed] -> Int
totalCost [] = 0
totalCost (x : xs) = cost x + totalCost xs

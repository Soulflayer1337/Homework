-- Three approaches for palindrom problem
-- The easiest way to solve the problem. Linear.
isPalindrom1 :: String -> Bool
isPalindrom1 str = str == (reverse str)

-- A bit faster than first approach. Still linear
isPalindrom2 :: String -> Bool
isPalindrom2 str = take n str == take n (reverse str) where
                   n = div (length str) 2

-- Should be much slower than other solutions because of using init and last functions.
isPalindrom3 :: String -> Bool
isPalindrom3 [] = True
isPalindrom3 [_] = True
isPalindrom3 (fs:str1) = fs == (last str1) && isPalindrom3 (init str1)

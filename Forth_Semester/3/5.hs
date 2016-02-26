bracketCounter :: String -> Int -> Bool
bracketCounter [] num = num == 0
bracketCounter (x : xs) num | num < 0     = False
                            | x == '('    = bracketCounter xs (num + 1)
                            | x == ')'    = bracketCounter xs (num - 1)
                            | otherwise   = bracketCounter xs num

isCorrect :: String -> Bool
isCorrect str = bracketCounter str 0

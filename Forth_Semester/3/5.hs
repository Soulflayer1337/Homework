-- Old version
-- It works properly for string with only '(' and ')' brackets
bracketCounter :: String -> Int -> Bool
bracketCounter [] num = num == 0
bracketCounter (x : xs) num | num < 0     = False
                            | x == '('    = bracketCounter xs (num + 1)
                            | x == ')'    = bracketCounter xs (num - 1)
                            | otherwise   = bracketCounter xs num

isCorrect :: String -> Bool
isCorrect str = bracketCounter str 0

-- New version.
-- It works for string containing three different types of brackets
isCorrect2 :: String -> Bool
isCorrect2 str = helpIsCorrect str [] where
    helpIsCorrect :: String -> String -> Bool
    helpIsCorrect []           stack = null stack
    helpIsCorrect (c : str) stack | isOpen(c)   = helpIsCorrect str (c : stack)
                                  | isClosed(c) = not (null stack) &&
                                    (isCorresponding (head stack) c) &&
                                    (helpIsCorrect str (tail stack))
                                  | otherwise = helpIsCorrect str stack
    isOpen symb   = or [symb == '(', symb == '[', symb == '{']
    isClosed symb = or [symb == ')', symb == ']', symb == '}']
    isCorresponding '(' ')' = True
    isCorresponding '[' ']' = True
    isCorresponding '{' '}' = True
    isCorresponding  _   _  = False

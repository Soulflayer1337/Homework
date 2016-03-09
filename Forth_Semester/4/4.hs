module Main where

main :: IO ()
main = dialogueLoop []

dialogueLoop :: [Int] -> IO ()
dialogueLoop list = do
    putStrLn "Type one of the following: "
    putStrLn "  0 - exit"
    putStrLn "  1 - add value to sorted list"
    putStrLn "  2 - remove value from list"
    putStrLn "  3 - print list"
    command <- getChar
    getLine
    case command of
        '0' -> return ()
        '1' -> do putStrLn "Enter value to add: "
                  value <- readInt
                  dialogueLoop (addValue list value)
        '2' -> do putStrLn "Enter value to remove: "
                  value <- readInt
                  dialogueLoop (removeValue list value)
        '3' -> do print list
                  dialogueLoop list
        otherwise -> dialogueLoop list

readInt :: IO Int
readInt = readLn

addValue :: [Int] -> Int -> [Int]
addValue [] value = [value]
addValue l@(x : xs) value | x < value = x : (addValue xs value)
                          | otherwise = value : l

removeValue :: [Int] -> Int -> [Int]
removeValue [] _ = []
removeValue l@(x : xs) value | x < value  = x : (removeValue xs value)
                             | x == value = removeValue xs value
                             | x > value  = l

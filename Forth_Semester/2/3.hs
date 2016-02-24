sumOfDigits :: Int -> Int
sumOfDigits n | n == 0 = 0
              | n > 0  = sumOfDigits (div n 10) + mod n 10

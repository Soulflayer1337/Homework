class DiffObject a where
    diff :: a -> a

data Monomial = Monomial {
            factor :: Double,
            degree :: Int
        }
instance Show Monomial where
    show (Monomial 0 _) = "0"
    show (Monomial f 0) = show f
    show (Monomial 1 1) = "x"
    show (Monomial 1 d) = "x^" ++ show d
    show (Monomial (-1) d) = '-' : show (Monomial 1 d)
    show (Monomial f d) = show f ++ " * " ++ show (Monomial 1 d)
instance Eq Monomial where
    (==) (Monomial 0 _) (Monomial 0 _) = True
    (==) (Monomial 0 _) _ = False
    (==) _ (Monomial 0 _) = False
    (==) (Monomial f1 d1) (Monomial f2 d2) = d1 == d2
instance Ord Monomial where
    (<=) (Monomial 0 _) _ = True
    (<=) _ (Monomial 0 _) = False
    (<=) (Monomial f1 d1) (Monomial f2 d2) | d2 == d1 = f1 <= f2
                                           | otherwise = d1 <= d2
instance DiffObject Monomial where
    diff (Monomial 0 _) = (Monomial 0 0)
    diff (Monomial _ 0) = (Monomial 0 0)
    diff (Monomial fac deg) = Monomial ((fac /) $ fromIntegral deg) (deg - 1)

data Polynomial = Polynomial [Monomial]
instance DiffObject Polynomial where
    diff (Polynomial pol) =  Polynomial (qsort [x | x <- (map diff pol), x /= (Monomial 0 0)]) where
        qsort [] = []
        qsort [x] = [x]
        qsort (x : xs) = qsort [y | y <- xs, y > x] ++ x : qsort [y | y <- xs, y < x]
instance Show Polynomial where
    show (Polynomial []) = "0"
    show (Polynomial [mon]) = show mon
    show (Polynomial (mon1 : mon2 : rest)) = let
                res mon rest | factor mon < 0 = " - " ++ show (Polynomial (mon{factor = -factor mon} : rest))
                             | otherwise      = " + " ++ show (Polynomial (mon : rest))
            in show mon1 ++ res mon2 rest

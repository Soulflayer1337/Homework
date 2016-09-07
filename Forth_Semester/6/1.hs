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
    (<=) (Monomial f1 d1) (Monomial f2 d2) | d2 == d1 = True
                                           | otherwise = d1 <= d2
instance Num Monomial where
    (+) (Monomial a b) (Monomial c d) | b == d    = Monomial (a + c) d
                                      | otherwise = error "Different degrees"
    (*) (Monomial a b) (Monomial c d) = Monomial (a * c) (b + d)
    abs (Monomial a b) = Monomial (abs a) b
    negate (Monomial a b) = Monomial (negate a) b
    signum (Monomial a b) = Monomial (signum a) 0
    fromInteger a = Monomial (fromInteger a :: Double) 0

data Polynomial = Polynomial [Monomial]
simplify :: Polynomial -> Polynomial
simplify (Polynomial mon) = let
            qsort [] = []
            qsort [x] = [x]
            qsort (x : xs) = qsort [y | y <- xs, y > x] ++ x : qsort [y | y <- xs, y <= x]
            simplify' [] = []
            simplify' ((Monomial 0 _) : rest) = simplify' rest
            simplify' (mon1 : []) = [mon1]
            simplify' (mon1 : r@(mon2 : rest)) | mon1 == mon2 = simplify' ((mon1 + mon2) : rest)
                                               | otherwise    = mon1 : (simplify' r)
        in Polynomial (simplify' $ qsort mon)

instance Show Polynomial where
    show (Polynomial []) = "0"
    show (Polynomial [mon]) = show mon
    show (Polynomial (mon1 : mon2 : rest)) = let
                res mon rest | factor mon < 0 = " - " ++ show (Polynomial (mon{factor = -factor mon} : rest))
                             | otherwise      = " + " ++ show (Polynomial (mon : rest))
            in show mon1 ++ res mon2 rest
instance Num Polynomial where
    (+) (Polynomial mon1) (Polynomial mon2) = simplify $ Polynomial (mon1 ++ mon2)
    (*) (Polynomial mon1) (Polynomial mon2) = simplify $ Polynomial ( 
                                                mon1 >>= 
                                                \x -> mon2 >>= 
                                                \y -> return $ x * y)
    fromInteger a = Polynomial [fromInteger a :: Monomial]
    negate (Polynomial mon) = Polynomial (map negate mon)
    abs (Polynomial mon) = Polynomial (map abs mon)
    signum (Polynomial mon) = error "No signum"

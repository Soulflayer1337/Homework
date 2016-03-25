strangeFunction :: (Floating a) => [a] -> a
strangeFunction list = let
    helpFunction elemSum cosMult [] = elemSum / cosMult
    helpFunction elemSum cosMult (x : sx) = 
        helpFunction (elemSum + x) (cosMult * (cos x)) sx
    in helpFunction 0 1 list

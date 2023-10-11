f :: Int -> String
f x | x<=3 = "NO"
    | (mod x 2) == 0 = "YES"
    | otherwise = "NO"
main=interact$f.read
{- Generalização -}

--funções que recebem funções como argumentos

dobro :: Num a => a -> a
dobro a = 2*a

duas_vezes :: (a -> a) -> a -> a
duas_vezes f a = f (f a)
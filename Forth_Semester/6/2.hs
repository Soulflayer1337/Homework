import Control.Monad
import Data.List

data PathTo = PathTo {
  number  :: Int,
  weight' :: Maybe Int
} deriving (Eq, Show)

data Edge = Edge {
  from   :: Int,
  to     :: Int,
  weight :: Int
} deriving Show

data Graph = Graph {
  vertecies :: [Int],
  edges     :: [Edge]
} deriving Show

instance Ord PathTo where
  compare (PathTo _ Nothing)  (PathTo _ (Just _)) = GT
  compare (PathTo _ (Just _)) (PathTo _ Nothing)  = LT
  compare (PathTo _ left)     (PathTo _ right)    = compare left right

-- For example:
testGraph = Graph [1..6] [Edge 1 2 7,  Edge 1 3 9,  Edge 1 6 14, 
                          Edge 2 1 7,  Edge 2 3 10, Edge 2 4 15,
                          Edge 3 1 9,  Edge 3 2 10, Edge 3 4 11, Edge 3 6 2,
                          Edge 4 2 15, Edge 4 3 11, Edge 4 5 6,
                          Edge 5 4 6,  Edge 5 6 9,
                          Edge 6 1 14, Edge 6 3 2,  Edge 6 5 9]
-- The answer for 1:
-- 1  0
-- 2  7
-- 3  9
-- 4  20
-- 5  20
-- 6  11

dijkstra :: Int -> Graph -> [PathTo]
dijkstra start graph = let
    init = [PathTo num (if start == num then Just 0 else Nothing) | num <- vertecies graph]
    dijkstra' [] visited   = visited
    dijkstra' rest visited = let 
        from'      = minimum rest
        newVisited = from' : visited
        newRest    = map updateEntrys (delete from' rest)
        updateEntrys pathTo = minimum $ pathTo : paths pathTo
        paths (PathTo to' _)  = [ PathTo to' (sum (weight' from') weight'') | 
                                  (Edge from'' to'' weight'') <- edges graph,
                                  from'' == number from', to'' == to']
        sum Nothing b = Just b
        sum (Just a) b = Just (a + b)
      in dijkstra' newRest newVisited
  in dijkstra' init [] 

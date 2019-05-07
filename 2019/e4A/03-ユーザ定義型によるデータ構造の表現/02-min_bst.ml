(* 二分木の定義 *)
type 'a btree = Node of 'a * 'a btree * 'a btree  | Leaf 

(* 二分木 *)
let t =
  Node(1,
    Node(2,
      Node(4, Leaf,
        Node(5, Leaf, Leaf)),
      Leaf),
    Node(7, Node(6, Leaf, Leaf),
      Node(8, Leaf,
        Node(9, Leaf, Leaf))
    )
  );;

(* 要素の最小値 *)
let min_bst t min_num=
  let rec rec_min_bst t min_num =
    match t with
      Node(v, t1,t2) ->
        if v < min_num then (count_bst t1) or (count_bst t2)
        else true
    | Leaf -> 0
  in rec_min_bst t min_num;;
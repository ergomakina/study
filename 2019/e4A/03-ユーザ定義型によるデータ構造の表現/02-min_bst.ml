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
let rec min_bst t =
    match t with
      Node(_, Node(v, _, _), Leaf) -> v
    | Leaf -> 0
  in min_bst t;;
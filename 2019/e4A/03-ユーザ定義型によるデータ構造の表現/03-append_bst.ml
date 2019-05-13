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

  (* 二分探索木への要素の追加 *)
let append_bst n t =
  let rec append_bst_rec t =
    match t with
    Node(v, t1, _) -> if n < v then append_bst_rec t1
    | Node(v, _, t2) -> if n > v then append_bst_rec t2 
    | Leaf -> Node( n, Leaf, Leaf)

let rec add t x =
  match t with
    Lf -> Br (x, Lf, Lf)
  | (Br (y, left, right) as whole) ->
      if x = y then whole
      else if x < y then Br(y, add left x, right) else Br(y, left, add right x);;


let rec append_bst n tree =
  match tree with
    Leaf -> Node(n, Leaf, Leaf)
  | Node(v, t1, t2) ->
      if n < v then Node(v, append_bst n t1, t2)
      else if n > v then Node(v, t1, append_bst n t2)
      else Node(v, t1, t2)
;;

append_bst 5 (Node(8, Node(3, Node(1, Leaf, Leaf), Leaf), Node(10, Leaf, Leaf)));;
append_bst 0 (Node(8, Node(3, Node(1, Leaf, Leaf), Leaf), Node(10, Leaf, Leaf)));;
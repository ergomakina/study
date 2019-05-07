let lec find v t =
  match t with
   Node(v', t1, t2) ->
    if v = v' then true
    else if v > v' then find v t2
    else find v t1
  | Leaf -> false;;
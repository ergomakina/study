(* 幅優先探索 *)
let bfs t =
  let rec bfs_iter result nodes =
    if nodes = [] then result else
    let (newresult, nodes') =
      List.fold_left ( fun (rs, ns) n ->
        match n with
          Node(v, t1, t2) -> (rs @ [v], t1::t2:ns)
        | Leaf -> (rs, ns)
      ) ([],[]) nodes in bfs_iter (result @ newresult) nodes'
  in bfs_iter [] [t];;
let rev xs =
  let rec rev_iter result xs =
    match xs with
      hd::tl -> rev_iter (hd::result) tl
    | [] -> result
  in rev_iter [] xs
    
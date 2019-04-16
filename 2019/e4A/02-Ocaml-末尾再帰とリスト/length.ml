let length mylist =
  let rec count result mylist =
    match mylist with
      hd::tl -> 1 + (count result tl)
    | [] -> 0
  in count 1 mylist
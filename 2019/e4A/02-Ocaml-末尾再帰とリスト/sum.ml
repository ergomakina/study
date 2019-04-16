let rec sum xs =
  match xs with
    hd::tl -> hd + (sum tl)
  | [] -> 0
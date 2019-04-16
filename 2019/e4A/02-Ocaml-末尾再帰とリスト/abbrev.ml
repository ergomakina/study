let rec abbrev xs =
  match xs with
    hd::tl ->
      (String.sub hd 0 1) ^ (abbrev tl)
  | [] -> ""
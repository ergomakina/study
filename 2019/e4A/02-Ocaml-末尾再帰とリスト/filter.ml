let filter f xs =
  let rec myfilter result mylist=
    match mylist with
      hd::tl when hd > 2 -> myfilter (result @ [hd] ) tl
    | hd::tl -> myfilter result tl
    | [] -> result
  in myfilter [] xs;;

(* filter (fun x -> x mod 2 = 0) [1;2;3;4;5];; *)
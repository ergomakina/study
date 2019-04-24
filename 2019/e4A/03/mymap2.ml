(* # mymap (fun x -> x > 2) [1;2;3;4;5;6;7;8;9];;
- : bool list = [false; false; true; true; true; true; true; true; true]
# mymap (fun x -> x mod 2 = 0)  [1;2;3;4;5;6;7;8;9];;
- : bool list = [false; true; false; true; false; true; false; true; false]
# mymap (fun x -> x mod 2 =1) [1;2;3;4;5;6;7;8;9];;
- : bool list = [true; false; true; false; true; false; true; false; true] *)

let mymap f mylist =
  List.fold_left (fun result x->
    (f x) :: result
   ) []  (List.rev mylist);;

let mymap2 f mylist =
  let rec mymap3 f data =
    match data with
      hd::tl -> (fun hd -> f x ) 
    | [] -> []
  in mymap3 f mylist


(* Answer *)
let rec mymap f mylist =
  match mylist with
    hd::tl -> (f hd)::(mymap f tl)
  | [] -> []

let mymap f mylist =
  let rec mymap_filter result mylist =
    match mylist with
      hd::tl -> mymap_filter (result @ [f hd]) tl
  in mymap_filter [] mylist
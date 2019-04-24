let n = int_of_string Sys.argv.(1);;
let seed_index = 2;; (* first definition *)
(* let incr_seed = seed_index = seed_index + 1;; *)
let rec ispromise n =
  if n mod seed_index = 0 then true
  else seed_index = seed_index + 1;;
let () = Printf.printf "result: %d\n" (ispromise n);;  


(* # anster *)
let ispromise n =
  let rec divisor j =
    if j <2 then true
    else if ( n mod j) <> 0 then 
    else 
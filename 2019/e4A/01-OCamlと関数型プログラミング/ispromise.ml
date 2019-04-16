let n = int_of_string Sys.argv.(1);;
let seed_index = 2;; (* first definition *)
(* let incr_seed = seed_index = seed_index + 1;; *)
let rec ispromise n =
  if n mod seed_index = 0 then true
  else seed_index = seed_index + 1;;
let () = Printf.printf "result: %d\n" (ispromise n);;  
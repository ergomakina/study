let n = int_of_string Sys.argv.(1);;
let seed_index = ref 2;; (* first definition *)
let incr_seed = seed_index := !seed_index + 1;;
let rec ispromise n =
  if n = 2 then true
  else
    if n mod 2 = 0 then false
    else
      if n mod seed_index.contents = 0 then false
      else
        if n = seed_index.contents then true
        else incr_seed;;
let () = ispromise n;;
  
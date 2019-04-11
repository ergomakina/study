let n = int_of_string Sys.argv.(1);;
let seed_index = ref 0;; (* first definition *)
let incr_seed() = 
    seed_index := !seed_index + 1;;
let rec ispromis n =
  if n = 2 then true
  else
    if n mod 2 = 0 then false
    else
      if seed_index.contents < n then
        if n mod seed_index.contents = 0 then false
        else true
      else incr_seed();;
let () = ispromise n;;
  
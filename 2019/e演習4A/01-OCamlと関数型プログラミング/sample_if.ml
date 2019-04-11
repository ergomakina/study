let is_even x = if x mod 2 = 0 then 1 else 0;; 
let even_vs_odd a b c d e =
  if (is_even a + is_even b + is_even c + is_even d + is_even e) > 2 then true else false;;
even_vs_odd 4 4 4 4 1;;
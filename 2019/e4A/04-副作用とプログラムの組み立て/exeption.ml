exception ZeroDivision;;

let div x y =
  if y = 0 then raize ZeroDivision
  else x / y;;

div 3 2;;

div 4 0;;
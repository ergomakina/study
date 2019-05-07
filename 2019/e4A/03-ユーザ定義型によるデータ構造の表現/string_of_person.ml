let string_of_person p =
  match p with
    Student{id = _; name = n; grade = g} -> n ^ (if g > 3 then "senpai" else "san")
  | Teacher{title = t; name = n} -> t ^ " " ^ n;;

let enryo = Student{id="1F1017xxxxx"; name="Enryo Inoue"; grade=4} in string_of_person enryo;;

let dean = Teacher{title="Prof."; name="Ken Sakamura"} in string_of_person dean;;
use calc.ml;;
use ../03-ユーザ定義型によるデータ構造の表現/06-eval.ml;;

let calc2 =
  let bst = perse read_line () in eval bst;;
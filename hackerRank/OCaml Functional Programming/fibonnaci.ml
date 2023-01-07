(* Enter your code here. Read input from STDIN. Print output to STDOUT *)


let rec fib n =
  match n with
  | 1 -> 0
  | 2 -> 1
  | m when m>=3 -> fib (m-1) + fib (m-2)
  | _ -> failwith "fact: negative input";;

  

let () = 
    let n = read_int () in
    Printf.printf "%d" (fib n);;

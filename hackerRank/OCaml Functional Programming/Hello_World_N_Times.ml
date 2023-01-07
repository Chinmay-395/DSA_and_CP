(* Enter your code here. Read input from STDIN. Print output to STDOUT *)
let rec hello_worlds n =
    print_string "Hello World\n";
    if n > 1 then hello_worlds (n - 1)

let () = 
    let n = read_int () in
    hello_worlds n

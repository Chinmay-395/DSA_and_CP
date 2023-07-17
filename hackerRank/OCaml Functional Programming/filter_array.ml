let rec read_filter x = 
    try
        let n = read_int() in
            if n < x then Printf.printf "%d\n" n;
            read_filter x
    with End_of_file -> ()
in read_filter (read_int());;
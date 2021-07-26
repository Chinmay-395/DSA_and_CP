# O(n)
<ul>
<li>🟠 Drop the constants</li>
<li>🟠 If nested loops then multiply
<ul>
<li>🔸 if the length of iterations is same O(n^2)</li>
<li>🔸 if the length of iterations is different O(length*of_outer-loop * length_of_inner-loop)</li>
    </ul>
</li>
<li>🟠 Growth rates: 1 < log(n) < n < n*log(n) < n^2 < n^3 < 2^n < n!</li>
<li>🟠 Consecutive loops then O(length_of_outer-loop + length_of_inner-loop)</li>
<li>🟠 When you see a problem where the number of elements in the problem
space gets <i>halved each time</i>, that will likely be a 0( log N) runtime</li>
<li>🟠 Recurssion
    <p>
    When you have a recursive function that makes multiple calls, the runtime will
    often (but not always) look like <b>O(branches^depth)</b>, where branches is the number of times each recursive call branches.</br>
    where:</br>
    • branches: the different return calls</br>
    • Depth of the tree</br>
    </p>
    
🔸 List of recurrence relations of decreasing functions
```
    1. T(n) = T(n-1) + 1      --------👉 O(n)
    2. T(n) = T(n-1) + n      --------👉 O(n^2)
    3. T(n) = T(n-1) + log(n) --------👉 O(n*log(n))
    4. T(n) = T(n-1) + n^2    --------👉 O(n^3)
    5. T(n) = T(n-1) + 1      --------👉 O(n/2)
    ----------------------------------------------------
        GENERAILIZING THE ABOVE 5 relations
        T(n) = T(n-1) + g(n)      --------👉 O(n*g(n))
        where g(n) is a function
    ----------------------------------------------------    
    6. T(n) = 2T(n-1) + 1     --------👉 O(2^n)
    7. T(n) = 2T(n-1) + n     --------👉 O(n*2^n)
    ----------------------------------------------------
        GENERAILIZING THE ABOVE 2 relations
        T(n) = x*T(n-1) + g(n)      --------👉 O(x^n*g(n))
        where g(n) is a function and x = coefficient
    ----------------------------------------------------    
```
🔸 MASTER THEOREM
```
    T(n) = a*T(n-b) + f(n)
    a>0, b>0 and f(n)=(n^k)
    where k>=0
```
> case-1: if a < 1 then O(n^f(n)) <br/>
> case-2: if a = 1 then O(n*f(n)) <br/>
> case-3: if a > 1 then O(n^f(n)*a^[n/b]) 

    
</li>
</ul>

#### Helpful code-snippets

```
/** counts all permutations of a string */
void permutation(String str) {
    permutation(str, "");
    }
void permutation(String str, String prefix) {
    if (str.length() == 0) {
    System.out.println(prefix);
    } else {
        for (int i= 0; i < str.length(); i++) {
            String rem = str.substring(0, i) + str.substring(i + 1);
            permutation(rem, prefix + str.charAt(i));
        }
    }
 }
```

```
/** Check function is Prime */
boolean isPrime(int n) {
    for (int x = 2; x <= sqrt(n); x++) {
        if (n % X == 0) {
        return false;
        }
    }
    return true;
}
```

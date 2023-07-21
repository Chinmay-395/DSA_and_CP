def longestValidSubstring(word: str, forbidden: list[str]) -> int:
    n = len(word)
    forbidden = set(forbidden)
    ans = prev = 0
    print("The substrings \n")
    for i in range(n):
        curr = i + 1
        for j in range(10):
            if i - j < 0:
                break
            s_t = word[i - j : i + 1]
            print(f"i: {i} j: {j}")
            print(s_t)
            print("\n")
            if s_t in forbidden:
                curr = j
                break
        curr = min(curr, prev + 1)
        ans = max(ans, curr)
        prev = curr
    return ans

x = longestValidSubstring("leetcode",["le","de","e"])
print("The OP ",x)
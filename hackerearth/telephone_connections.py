def min_max_telephone_connections(A, B):
    # Function to calculate the number of connections in a locality with n houses
    def connections(n):
        return n * (n - 1) // 2

    # Calculating minimum connections
    # Number of localities with ceil(A/B) houses
    localities_with_more_houses = A % B
    # Number of localities with floor(A/B) houses
    localities_with_less_houses = B - localities_with_more_houses
    
    min_connections = (localities_with_more_houses * connections((A + B - 1) // B) +
                       localities_with_less_houses * connections(A // B))

    # Calculating maximum connections
    # All but one locality have 1 house, and one locality has A - (B - 1) houses
    max_connections = connections(A - (B - 1))

    return min_connections, max_connections

# Example Case
A = 5
B = 1
print("ans ",min_max_telephone_connections(A, B))


#include <iostream>
#include <cstdio> // for freopen and fclose

void processAndOutput(int n)
{
    // Here, we just square the number for demonstration purposes.
    std::cout << n * n << std::endl;
}

int main()
{
    // Redirect stdin from input.txt
    if (freopen("input.txt", "r", stdin) == nullptr)
    {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    // Redirect stdout to output.txt
    if (freopen("output.txt", "w", stdout) == nullptr)
    {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    int number;
    // Read numbers from file
    while (std::cin >> number)
    {
        // Process each number and output
        processAndOutput(number);
    }

    // Optionally, close the redirected streams
    fclose(stdin);
    fclose(stdout);

    // When the program terminates, the streams would be closed automatically.
    return 0;
}

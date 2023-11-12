/**
 * @brief takes in two parameters to an integer number and the xth bit  from most significant bit side
 * @param unsigned int number
 * @param int x
 * @return bool
 */
bool is_set(unsigned int number, int x)
{
    return (number >> x) & 1;
}
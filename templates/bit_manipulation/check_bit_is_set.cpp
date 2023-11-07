bool is_set(unsigned int number, int x)
{
    /**
     * @brief The value of the  
        x -th bit can be checked by shifting the number  
        x  positions to the right, so that the  
        x -th bit is at the unit place, after which we can extract it by performing a bitwise & with 1.
     * @param unsigned int number
     * @param int
     * @return bool
     */
    return (number >> x) & 1;
}
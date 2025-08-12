/*The first instruction subtracted 60 from %rsi
 * so do not forget that  %rsi is n - 60
 * Furthermore, case %rsi = 4 should jump to line 12 and continue to execute
 * until it met retq instruction in line 18
 */
long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    {
        result = 8 * x;
        break;
    }
    case 61:
    {
        result = x + 75;
        break;
    }
    case 62:
    {
        result = 8 * x;
        break;
    }
    case 63:
    {
        result = x >> 3;
        break;
    }
    case 64:
    {
        result = x * 15;
        x = result * result;
        result = x + 75;
        break;
    }
    case 65:
    {
        result = x * x + 75;
        break;
    }
    default:
    {
        result = x + 75;
    }
    }
    return result;
}
int gcd(int a,int b,int c)
{
    while (a % b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    while (b % c != 0){
        int temp = c;
        c = b % c;
        b = temp;
    }
    return c;
}

long long value(int type, int width, int height, int length)
{
        long long Value;
        switch (type)
        {
            case 79:
                Value = 30;
                break;
            case 47:
                Value = 10;
                break;
            case 29:
                Value = 4;
                break;
            case 82:
                Value = 5;
                break;
            case 26:
                Value = 3;
                break;
            case 22:
                Value = 9;
                break;
            default:
                return -1;
        }
    if (width > 0 && height > 0 && length > 0){
        int l = gcd(width,height,length);
        long long  V = l*l*l;
        long long  N = (length*width*height)/V;
        long long total = Value*V*V*N;
        return total;
    }
    else{
        return -2;
    }
}

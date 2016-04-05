#include <iostream>
int main()
{
    std::ios::sync_with_stdio(0);
    int a, b, x, y, p = 1, q = 0, r = 0, s = 1, A, B;
    std::cin >> a >> b;
    A = a;
    B = b;
    if (!(a % 2) && !(b % 2))
    {
    	std::cout << "0 0\n";
    	return 0;
    }
    while (a && b)
    {
    	if (a >= b)
        {
        	a -= b;
        	p -= r;
        	q -= s;
        }
    	else
        {
        	b -= a;
        	r -= p;
        	s -= q;
        }
    }
	if (a)
    {
    	x = p;
    	y = q;
    }
	else
    {
    	x = r;
    	y = s;
    }
    if (x > 10000 || x < -10000 || y > 10000 || y < -10000 || A * x + B * y != 1)
    {
    	//std::cout << x << " " << y << "\n";
    	std::cout << "0 0\n";
    	return 0;
    }
	std::cout << x << " " << y << "\n";
	return 0;
}

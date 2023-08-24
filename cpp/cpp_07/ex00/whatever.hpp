#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &x, T &y)
{
	T save_x;
	save_x = x;
	x = y;
	y = save_x;
};

template <typename T>
T const &min(T const &x, T const &y)
{
	return (x < y ? x : y);
};

template <typename T>
T const &max(T const &x, T const &y)
{
	return (x > y ? x : y);
};
#endif

#pragma once
template<class T>
T findBiggest(T a, T b, T c) {
	T biggest{ a };
	if (b > a)
		biggest = b;
	if (c > a)
		biggest = c;
	return biggest;
}
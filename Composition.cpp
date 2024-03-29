// Composition.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "pch.h"
#include <iostream>
#include <functional>
/*
template <typename T>
struct function_arg : public function_arg<decltype(&T::operator())> {};

template<typename ReturnType, typename Arg>
struct function_arg<ReturnType(Arg) const> {
	using type = Arg;
};

template<typename ClassType, typename ReturnType, typename Arg>
struct function_arg<ReturnType(ClassType::*)(Arg) const> {
	using type = Arg;
};

template<typename T>
using function_arg_t = typename function_arg<T>::type;

template<typename F, typename G>
auto compose(F&& f, G&& g) {
	return[f = std::forward<F>(f), g = std::forward<G>(g)]
	(function_arg_t<F>&& a) {return g(f(std::forward<function_arg_t<F>>(a))); };
}
*/

template<typename A, typename B, typename C>
std::function<C(A)> compose(std::function<B(A)>&& f,std::function<C(B)>&& g)
{
	return [f,g](A x)
	{
		auto cock = f(x);
		auto dick = g(cock);
		return dick;
	};
}

int cube(int x) {
	return x * x*x;
}

double mul5(int y) {
	return y * 5;
}

int main()
{
	int x = 2;
	int y = 3;
	std::function f_cube = cube;
	std::function f_mul5 = mul5;
	auto cock = f_mul5(5);
	std::cout << compose(std::move(f_cube), std::move(f_mul5))(2);
	return 0;
}


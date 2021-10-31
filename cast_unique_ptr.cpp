#include "f.hpp"
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <utility>

struct A {float f; virtual ~A() = default;};
struct B : public A {int n; };

template <typename T, typename R>
std::unique_ptr<T> cast_unique_ptr(std::unique_ptr<R> &source)
{
	T *test = dynamic_cast<T*>(source.get());
	if (!test)
		return {};
	(void)source.release();
	return std::make_unique<T>(*test);
}

int main()
{
	std::unique_ptr<A> test = std::make_unique<A>();
	auto f = cast_unique_ptr<B>(test);
}

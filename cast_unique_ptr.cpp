#include <memory>
#include <utility>

struct A {float f; virtual ~A() = default;};
struct B : public A {int n; };

template <typename T, typename R>
std::unique_ptr<T> cast_unique_ptr(std::unique_ptr<R> &source)
{
	T *test = dynamic_cast<T*>(source.get()); //try cast
	if (!test)
		return {};
	std::unique_ptr<T> ret = std::make_unique<T>(*test); //copy object
	source.reset(); //free old ptr
	return ret;
}

int main()
{
	std::unique_ptr<A> test = std::make_unique<A>();
	auto f = cast_unique_ptr<B>(test);
}

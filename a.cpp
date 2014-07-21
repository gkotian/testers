#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>

static const int num_threads = 10;

void call_from_thread(int tid) {
    std::cout << "Launched by thread " << tid << std::endl;
}

int main() {
    std::thread t[num_threads];

    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread, i);
    }

    std::cout << "Launched from the main\n";

    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }

    return 0;
}

#if 0
#include <iostream>
#include <regex>

int main() {

    //const char *reg_esp = "[ ,.\\t\\n;:]";  // List of separator characters.
     
     // this can be done using raw string literals:
     const char *reg_esp = R"([ ,.\t\n;:])";

     std::regex rgx(reg_esp); // 'regex' is an instance of the template class
     // 'basic_regex' with argument of type 'char'.
     std::cmatch match; // 'cmatch' is an instance of the template class
     // 'match_results' with argument of type 'const char *'.
     const char *target = "Unseen University - Ankh-Morpork";

     // Identifies all words of 'target' separated by characters of 'reg_esp'.
     if (std::regex_search(target, match, rgx)) {
         // If words separated by specified characters are present.

         const size_t n = match.size();
         for (size_t a = 0; a < n; a++) {
             std::string str (match[a].first, match[a].second);
             std::cout << str << "\n";
         }
     }

    return 0;
}

#include <iostream>

class A {
private:
    static const int a = 2;
public:
    int get_a() const {
        return a;
    }
};

std::ostream& operator<<(std::ostream& out, const A& a) {
    out << a.get_a();
    return out;
}

int main() {
    A objA;
    std::cout << objA << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

class A {
private:
    std::vector<std::string> v;

public:
    A(std::initializer_list<std::string> list) : v(list) {
    }
    const std::vector<std::string>& get_v() const {
        return v;
    }
};

std::ostream& operator<<(std::ostream& out, const A& a) {
    out << "(";
    for (auto i : a.get_v()) {
        out << i << ", ";
    }
    out << ")";
    return out;
}

int main() {
    auto i = {A{"foo", "bar", "dog"}, A{"hey", "sky"}};

    for (auto j : i) {
        std::cout << j << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{4, 30};

    v.push_back(40);

    for (auto i : v) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    return 0;
}

#include <iostream>

class A {
private:
    int a_;
    int b_;

public:
    A(int a, int b) : a_{a}, b_{b} {
    }
    int get_a() const {
        return a_;
    }
    int get_b() const {
        return b_;
    }
};

std::ostream& operator<<(std::ostream& out, const A& a) {
    out << "a = " << a.get_a() << ", b = " << a.get_b();
    return out;
}

int main() {
    A a{10, 20};

    std::cout << a << std::endl;
}

#include <iostream>

constexpr int get_five(int a) {
    return 5;
}

int main() {
    const int x = 3;
    int a[get_five(x) + 7] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    for (auto i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>

class Base
{
private:
public:
    Base() { std::cout << "Base class ctor" << std::endl; }
    virtual void foo() { std::cout << "Base class foo" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived class ctor" << std::endl; }
private:
    void foo() { std::cout << "Derived class foo" << std::endl; }
};

int main()
{
    Derived d;
    Base *p = &d;

    p->foo();
}

#include <iostream>
#include <string>

int main()
{
    std::string s("hello");

    for (const auto& i : s)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

#include <sstream>
#include <iostream>

int main()
{
    std::stringstream ss;

    for (unsigned int i = 0; i < 10; ++i)
    {
        ss << "Unnamed " << i;
        std::cout << ss.str() << std::endl;
        ss.str("");
    }

    return 0;
}
#include <iostream>
#include <vector>

double calcVectorAvg(const std::vector<double>& v)
{
    double sum = 0;

    for (std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        sum += *i;
    }

    return (sum / v.size());
}

int main()
{
    std::vector<double> v;

    v.push_back(20.3);
    v.push_back(20.7);
    v.push_back(20.1);
    v.push_back(20.9);

    std::cout << "avg = " << calcVectorAvg(v) << std::endl;
}

#include <iostream>
#include <vector>
#include <iterator>
#include <string>

template <typename T>
void displayVector(T v)
{
    for (typename T::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> vi;

    vi.push_back(11);
    vi.push_back(22);
    vi.push_back(33);
    vi.push_back(44);

    displayVector(vi);

    std::vector<double> vd;

    vd.push_back(4.36);
    vd.push_back(4.0);
    vd.push_back(45.6);
    vd.push_back(23.6);

    displayVector(vd);

    std::vector<std::string> vs;

    vs.push_back("hello");
    vs.push_back("there");
    vs.push_back("blah1");
    vs.push_back("blah2");

    displayVector(vs);
}

#include <complex>
int main()
{
    std::complex<double> r(2.5, 4.3);
    std::complex<double> s(6.34, 14.332);

    std::cout << "r = " << r << std::endl;
    std::cout << "s = " << s << std::endl;

    return 0;
}

class A
{
    public:
        explicit A(int x) : mx(x)
        //A(int x) : mx(x)
        {
        }

        void print_mx()
        {
            std::cout << "mx = " << mx << std::endl;
        }

    private:
        int mx;
};

int main()
{
    //A a(10);
    A a = 10;

    a.print_mx();

    return 0;
}

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " " );
}

/* Lambdas */
int main()
{
    std::vector<std::string> v;

    v.push_back("cat");
    v.push_back("antelope");
    v.push_back("puppy");
    v.push_back("bear");

    /* std::sort(v.begin(), v.end()); */
    std::sort(v.begin(), v.end(), [](const std::string& left, const std::string& right)
                                      {
                                          return left.size() < right.size();
                                      });

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
#endif


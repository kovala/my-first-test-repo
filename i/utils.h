#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace utils {
	int rndNum(int min, int max);

	std::vector<int> genRandomArray(size_t size, int min, int max);
  std::vector<int> genRandomIntArray(size_t size, int min, int max);

  std::string genRandomStr(size_t length, const std::string_view& chars = "abcdefghijklmnopqrstuvwxyz");
  std::vector<std::string> genRandomStrArray(size_t length, int min, int max);
}

namespace u {
//NB! requires gcc13
#if defined(__APPLE__)
void jlog(json j);
#else
constexpr void jlog(json j) { std::cout << j << std::endl; }
#endif

template <class T, std::size_t N>
constexpr std::ostream& operator<<(std::ostream& o, const std::array<T, N>& arr) {
  copy(arr.cbegin(), arr.cend(), std::ostream_iterator<T>(o, ","));
  return o;
}

template <typename Signature1, typename Signature2 = void> class arr_a;
template <typename Signature1, typename Signature2 = void> class arr_b;
template <typename Signature1, typename Signature2 = void> class fixarr;

template<class T, std::size_t N> class arr_a<T[N]> {
public:
  T tmp[N];
  operator const T*() {return tmp;}
  operator T*() {return tmp;}
  T& operator [](int i) {return tmp[i];}
  std::size_t size() {return N;}
};

template <typename T, std::size_t N> class arr_b<T[N]> : public arr_a<T[N]> {
public:
  arr_b() {memset(this->tmp, 0, sizeof(this->tmp));}
};

template <typename T, size_t N> class fixarr<T[N]> : public arr_b<T[N]> {};
template <size_t N> class fixarr<char[N]> : public arr_b<char[N]> {
public:
  fixarr(){}
  fixarr(const char* formatstring, ...){
    size_t size = (sizeof(this->tmp) / sizeof(this->tmp[0])) - sizeof(this->tmp[0]);
    va_list args;
    // va_start(args, formatstring);
    // memset(m_tmp, 0, sizeof(m_tmp));
    // _vsnprintf(m_tmp, size, formatstring, args);
  }
};
template <size_t N> class fixarr<wchar_t[N]> : public arr_b<wchar_t[N]> {
public:
  fixarr(){}
  fixarr(const wchar_t* formatstring, ...){
    size_t size = (sizeof(this->tmp) / sizeof(this->tmp[0])) - sizeof(this->tmp[0]);
    va_list args;
    // va_start(args, formatstring);
    // memset(m_tmp, 0, sizeof(m_tmp));
    // _vsnwprintf(m_tmp, size, formatstring, args);
  }
};
}

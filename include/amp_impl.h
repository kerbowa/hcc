#ifndef INCLUDE_AMP_IMPL_H
#define INCLUDE_AMP_IMPL_H

#include <iostream>
#if __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif
#define CHECK_ERROR(error_code, message) \
  if (error_code != CL_SUCCESS) { \
    std::cout << "Error: " << message << "\n"; \
    std::cout << "Code: " << error_code << "\n"; \
    std::cout << "Line: " << __LINE__ << "\n"; \
    exit(1); \
  }

#define CHECK_ERROR_GMAC(error_code, message) \
  if (error_code != eclSuccess) { \
    std::cout << "Error: " << message << "\n"; \
    std::cout << "Code: " << error_code << "\n"; \
    std::cout << "Line: " << __LINE__ << "\n"; \
    exit(1); \
  }
// Specialization of AMP classes/templates

namespace Concurrency {
// Accelerators
inline accelerator::accelerator(): accelerator(default_accelerator) {
  if (device_path != std::wstring(default_accelerator)) {
    std::wcerr << L"CLAMP: Warning: the given accelerator is not supported: ";
    std::wcerr << device_path << std::endl;
  }

  description = L"Default GMAC+OpenCL";
  if (!default_view_) {
    default_view_ = new accelerator_view(0);
    default_view_->accelerator_ = this;
  }
}
inline accelerator::accelerator(const accelerator& other): device_path(other.device_path), version(other.version),
dedicated_memory(other.dedicated_memory),is_emulated(other.is_emulated), has_display(other.has_display),
supports_double_precision(other.supports_double_precision), supports_limited_double_precision(other.supports_limited_double_precision) {
  if (device_path != std::wstring(default_accelerator)) {
    std::wcerr << L"CLAMP: Warning: the given accelerator is not supported: ";
    std::wcerr << device_path << std::endl;
  }

  description = L"Default GMAC+OpenCL";
  if (!default_view_) {
    default_view_ = new accelerator_view(0);
    default_view_->accelerator_ = this;
  }
}

// TODO(I-Jui Sung): perform real OpenCL queries here..
inline accelerator::accelerator(const std::wstring& path): device_path(path),
  version(0), dedicated_memory(1<<20), is_debug(false), is_emulated(false),
  has_display(false), supports_double_precision(true),
  supports_limited_double_precision(false), supports_cpu_shared_memory(false) {
  if (path != std::wstring(default_accelerator)) {
    std::wcerr << L"CLAMP: Warning: the given accelerator is not supported: ";
    std::wcerr << path << std::endl;
  }

  description = L"Default GMAC+OpenCL";
  if (!default_view_) {
    default_view_ = new accelerator_view(0);
    default_view_->accelerator_ = this;
  }
}
inline accelerator& accelerator::operator=(const accelerator& other) {
  device_path = other.device_path;
  version = other.version;
  dedicated_memory = other.dedicated_memory;
  is_emulated = other.is_emulated;
  has_display = other.has_display;
  supports_double_precision = other.supports_double_precision;
  supports_limited_double_precision = other.supports_limited_double_precision;
  return *this;
}
inline bool accelerator::operator==(const accelerator& other) const {
  return device_path == other.device_path &&
         version == other.version &&
         dedicated_memory == other.dedicated_memory &&
         is_emulated == other.is_emulated &&
         has_display == other.has_display &&
         supports_double_precision == other.supports_double_precision;
}
inline bool accelerator::operator!=(const accelerator& other) const {
  return !(*this == other);
}

inline accelerator_view& accelerator::get_default_view() const {
  return *default_view_;
}

// Accelerator view
inline accelerator_view accelerator::create_view(void) {
  accelerator_view sa(0);
  sa.queuing_mode = queuing_mode_automatic;
  sa.accelerator_ = this;
  return sa;
}
inline accelerator_view accelerator::create_view(queuing_mode qmode) {
  accelerator_view sa(0);
  sa.queuing_mode = qmode;
  sa.accelerator_ = this;
  return sa;
}

inline completion_future accelerator_view::create_marker(){return completion_future();}

template <int N>
index<N> operator+(const index<N>& lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r += rhs;
    return __r;
}
template <int N>
index<N> operator+(const index<N>& lhs, int rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r += rhs;
    return __r;
}
template <int N>
index<N> operator+(int lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = rhs;
    __r += lhs;
    return __r;
}
template <int N>
index<N> operator-(const index<N>& lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r -= rhs;
    return __r;
}
template <int N>
index<N> operator-(const index<N>& lhs, int rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r -= rhs;
    return __r;
}
template <int N>
index<N> operator-(int lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = rhs;
    __r -= lhs;
    return __r;
}
template <int N>
index<N> operator*(const index<N>& lhs, int rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r *= rhs;
    return __r;
}
template <int N>
index<N> operator*(int lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = rhs;
    __r *= lhs;
    return __r;
}
template <int N>
index<N> operator/(const index<N>& lhs, int rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r /= rhs;
    return __r;
}
template <int N>
index<N> operator/(int lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = rhs;
    __r /= lhs;
    return __r;
}
template <int N>
index<N> operator%(const index<N>& lhs, int rhs) restrict(amp,cpu) {
    index<N> __r = lhs;
    __r %= rhs;
    return __r;
}
template <int N>
index<N> operator%(int lhs, const index<N>& rhs) restrict(amp,cpu) {
    index<N> __r = rhs;
    __r %= lhs;
    return __r;
}

template <int N>
extent<N> operator+(const extent<N>& lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r += rhs;
    return __r;
}
template <int N>
extent<N> operator+(const extent<N>& lhs, int rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r += rhs;
    return __r;
}
template <int N>
extent<N> operator+(int lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = rhs;
    __r += lhs;
    return __r;
}
template <int N>
extent<N> operator-(const extent<N>& lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r -= rhs;
    return __r;
}
template <int N>
extent<N> operator-(const extent<N>& lhs, int rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r -= rhs;
    return __r;
}
template <int N>
extent<N> operator-(int lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = rhs;
    __r -= lhs;
    return __r;
}
template <int N>
extent<N> operator*(const extent<N>& lhs, int rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r *= rhs;
    return __r;
}
template <int N>
extent<N> operator*(int lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = rhs;
    __r *= lhs;
    return __r;
}
template <int N>
extent<N> operator/(const extent<N>& lhs, int rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r /= rhs;
    return __r;
}
template <int N>
extent<N> operator/(int lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = rhs;
    __r /= lhs;
    return __r;
}
template <int N>
extent<N> operator%(const extent<N>& lhs, int rhs) restrict(amp,cpu) {
    extent<N> __r = lhs;
    __r %= rhs;
    return __r;
}
template <int N>
extent<N> operator%(int lhs, const extent<N>& rhs) restrict(amp,cpu) {
    extent<N> __r = rhs;
    __r %= lhs;
    return __r;
}


template<int N> class extent;
template<typename T, int N> array<T, N>::array(const Concurrency::extent<N>& ext)
    : extent(ext), m_device(nullptr) {
#ifndef __GPU__
        initialize();
#endif
    }
template<typename T, int N> array<T, N>::array(int e0)
    : array(Concurrency::extent<1>(e0)) {}
template<typename T, int N> array<T, N>::array(int e0, int e1)
    : array(Concurrency::extent<2>(e0, e1)) {}
template<typename T, int N> array<T, N>::array(int e0, int e1, int e2)
    : array(Concurrency::extent<3>(e0, e1, e2)) {}


template<typename T, int N> 
array<T, N>::array(const Concurrency::extent<N>& ext, accelerator_view av, access_type cpu_access_type) : array(ext) {
  this->cpu_access_type = cpu_access_type;
}
template<typename T, int N> 
array<T, N>::array(int e0, accelerator_view av, access_type cpu_access_type) : array(e0) {
  this->cpu_access_type = cpu_access_type;
}
template<typename T, int N> 
array<T, N>::array(int e0, int e1, accelerator_view av, access_type cpu_access_type) : array(e0, e1) {
  this->cpu_access_type = cpu_access_type;
}
template<typename T, int N> 
array<T, N>::array(int e0, int e1, int e2, accelerator_view av, access_type cpu_access_type) : array(e0, e1, e2) {
  this->cpu_access_type = cpu_access_type;
}


template<typename T, int N> 
array<T, N>::array(const Concurrency::extent<N>& extent, accelerator_view av, accelerator_view associated_av) : array(extent) {}
template<typename T, int N> 
array<T, N>::array(int e0, accelerator_view av, accelerator_view associated_av) : array(e0) {}
template<typename T, int N> 
array<T, N>::array(int e0, int e1, accelerator_view av, accelerator_view associated_av) : array(e0, e1) {}
template<typename T, int N> 
array<T, N>::array(int e0, int e1, int e2, accelerator_view av, accelerator_view associated_av) : array(e0, e1, e2) {}


template<typename T, int N> template <typename InputIterator>
array<T, N>::array(const Concurrency::extent<N>& ext, InputIterator srcBegin)
    : extent(ext), m_device(nullptr) {
#ifndef __GPU__
        InputIterator srcEnd = srcBegin;
        std::advance(srcEnd, extent.size());
        initialize(srcBegin, srcEnd);
#endif
    }

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(const Concurrency::extent<N>& ext, InputIterator srcBegin, InputIterator srcEnd)
    : extent(ext), m_device(nullptr) {
#ifndef __GPU__
        initialize(srcBegin, srcEnd);
#endif
 }

template<typename T, int N> template <typename InputIterator> 
array<T, N>::array(int e0, InputIterator srcBegin)
    : array(Concurrency::extent<1>(e0), srcBegin) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, InputIterator srcBegin, InputIterator srcEnd)
    : array(Concurrency::extent<1>(e0), srcBegin, srcEnd) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, InputIterator srcBegin)
    : array(Concurrency::extent<2>(e0, e1), srcBegin) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, InputIterator srcBegin, InputIterator srcEnd)
    : array(Concurrency::extent<2>(e0, e1), srcBegin, srcEnd) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, int e2, InputIterator srcBegin)
    : array(Concurrency::extent<3>(e0, e1, e2), srcBegin) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, int e2, InputIterator srcBegin, InputIterator srcEnd)
    : array(Concurrency::extent<3>(e0, e1, e2), srcBegin, srcEnd) {}



template<typename T, int N> template <typename InputIterator>
array<T, N>::array(const Concurrency::extent<N>& ext, InputIterator srcBegin, accelerator_view av,
                   access_type cpu_access_type) : array(ext, srcBegin) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(const Concurrency::extent<N>& ext, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, access_type cpu_access_type) : array(ext, srcBegin, srcEnd) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, InputIterator srcBegin, accelerator_view av, access_type cpu_access_type)
    : array(e0, srcBegin) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator> 
array<T, N>::array(int e0, InputIterator srcBegin, InputIterator srcEnd, accelerator_view av, access_type cpu_access_type)
    : array(e0, srcBegin) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, InputIterator srcBegin, accelerator_view av, access_type cpu_access_type)
    : array(e0, e1, srcBegin) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator> 
array<T, N>::array(int e0, int e1, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, access_type cpu_access_type) : array(e0, e1, srcBegin, srcEnd) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, int e2, InputIterator srcBegin, accelerator_view av, access_type cpu_access_type)
    : array(e0, e1, e2, srcBegin) {
  this->cpu_access_type = cpu_access_type;
}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, int e2, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, access_type cpu_access_type) : array(e0, e1, e2, srcBegin, srcEnd) {
  this->cpu_access_type = cpu_access_type;
}





template<typename T, int N> template <typename InputIterator>
array<T, N>::array(const Concurrency::extent<N>& ext, InputIterator srcBegin, accelerator_view av,
                   accelerator_view associated_av) : array(ext, srcBegin) {}
template<typename T, int N> template <typename InputIterator>
array<T, N>::array(const Concurrency::extent<N>& ext, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, accelerator_view associated_av)
    : array(ext, srcBegin, srcEnd) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, InputIterator srcBegin, accelerator_view av,
                   accelerator_view associated_av)
    : array(e0, srcBegin) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, accelerator_view associated_av)
    : array(e0, srcBegin, srcEnd) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, InputIterator srcBegin, accelerator_view av,
                   accelerator_view associated_av)
    : array(e0, e1, srcBegin) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, accelerator_view associated_av)
    : array(e0, e1, srcBegin, srcEnd) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, int e2, InputIterator srcBegin, accelerator_view av,
                   accelerator_view associated_av)
    : array(e0, e1, e2, srcBegin) {}

template<typename T, int N> template <typename InputIterator>
array<T, N>::array(int e0, int e1, int e2, InputIterator srcBegin, InputIterator srcEnd,
                   accelerator_view av, accelerator_view associated_av)
    : array(e0, e1, e2, srcBegin, srcEnd) {}


template<typename T, int N> array<T, N>::array(const array& other)
    : extent(other.extent), m_device(other.m_device) {}
template<typename T, int N> array<T, N>::array(array&& other)
    : extent(other.extent), m_device(other.m_device) {}
template<typename T, int N>
array<T, N>::array(const array_view<const T, N>& src, accelerator_view av,
                   access_type cpu_access_type)
    : array(src) {
  this->cpu_access_type = cpu_access_type;
}
template<typename T, int N>
array<T, N>::array(const array_view<const T, N>& src, accelerator_view av,
                   accelerator_view associated_av)
    : array(src) {}

#define __global
#ifndef __GPU__

template <typename T, int N>
void array_view<T, N>::synchronize() const {
  assert(cache.get());
  assert(p_);
  cache.synchronize();
}

template <typename T, int N>
completion_future array_view<T, N>::synchronize_async() const {
  assert(cache.get());
  assert(p_);
  if (extent_base == extent && offset == 0) {
      std::future<void> fut = std::async([&]() mutable {
          memmove(const_cast<void*>(reinterpret_cast<const void*>(p_)),
              reinterpret_cast<const void*>(cache.get()), extent.size() * sizeof(T));
          });
    return completion_future(fut.share());

  } else {
    std::future<void> fut = std::async([&]() mutable {
      for (int i = 0; i < extent_base[0]; ++i){
          int off = extent_base.size() / extent_base[0];
          memmove(const_cast<void*>(reinterpret_cast<const void*>(&p_[offset + i * off])),
                  reinterpret_cast<const void*>(&(cache.get()[offset + i * off])),
                  extent.size() / extent[0] * sizeof(T));
          }
      });
    return completion_future(fut.share());
  }
}

template <typename T, int N>
array_view<T, N>::array_view(const Concurrency::extent<N>& ext,
                             value_type* src) restrict(amp,cpu)
    : extent(ext), p_(src),
      cache(GMACAllocator<nc_T>().allocate(ext.size()), GMACDeleter<nc_T>(), src, ext.size() * sizeof(T)),
      offset(0), extent_base(ext) {}

template <typename T, int N>
array_view<T, N>::array_view(const Concurrency::extent<N>& ext) restrict(amp,cpu)
    : extent(ext), p_(nullptr),
    cache(GMACAllocator<nc_T>().allocate(ext.size()), GMACDeleter<nc_T>()),
    offset(0), extent_base(ext) {}

template <typename T, int N>
void array_view<T, N>::refresh() const {
    assert(cache.get());
    assert(extent == extent_base && "Only support non-sectioned view");
    assert(offset == 0 && "Only support non-sectioned view");
    cache.refresh();
}

#else // GPU implementations

template <typename T, int N>
array_view<T,N>::array_view(const Concurrency::extent<N>& ext,
                            value_type* src) restrict(amp,cpu)
    : extent(ext), p_(nullptr), cache((__global nc_T *)(src)),
    offset(0), extent_base(ext) {}

#endif
#undef __global  

} //namespace Concurrency
#endif //INCLUDE_AMP_IMPL_H

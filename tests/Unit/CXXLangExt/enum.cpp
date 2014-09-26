// XFAIL: Linux

// RUN: %amp_device -DTYPE="char" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="char" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="signed char" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="signed char" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="unsigned char" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="unsigned char" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out

// RUN: %amp_device -DTYPE="short" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="short" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="signed short" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="signed short" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="unsigned short" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="unsigned short" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out

// RUN: %amp_device -DTYPE="int" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="int" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="signed int" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="signed int" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="unsigned int" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="unsigned int" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out

// RUN: %amp_device -DTYPE="long" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="long" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="signed long" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="signed long" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="unsigned long" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="unsigned long" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out

// RUN: %amp_device -DTYPE="long long" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="long long" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="signed long long" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="signed long long" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out
// RUN: %amp_device -DTYPE="unsigned long long" -D__GPU__ -Xclang -fhsa-ext %s -m64 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp -DTYPE="unsigned long long" -Xclang -fhsa-ext %link %t/kernel.o %s -o %t.out && %t.out

#include <amp.h>

enum E : TYPE {
  ZERO = 0
};

enum class EC : TYPE {
  ZERO = 0
};

enum struct ES : TYPE {
  ZERO = 0
};

// An HSA version of C++AMP program
int main ()
{

  const int vecSize = 16;

  int ans[vecSize];
  int *p_ans = &ans[0];

  parallel_for_each(
    Concurrency::extent<1>(vecSize),
    [=](Concurrency::index<1> idx) restrict(amp) {

    p_ans[idx[0]] = (int)E::ZERO + (int)EC::ZERO + (int)ES::ZERO;
  });

  // Verify
  int error = 0;
  for(int i = 0; i < vecSize; i++) {
    error += abs(ans[i]);
  }
  if (error == 0) {
    std::cout << "Verify success!\n";
  } else {
    std::cout << "Verify failed!\n";
  }
  return (error != 0);
}

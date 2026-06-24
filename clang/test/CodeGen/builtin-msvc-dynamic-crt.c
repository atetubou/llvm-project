// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -fdeclspec -D_DLL -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-X64-DLL
// RUN: %clang_cc1 -triple i686-pc-windows-msvc -fdeclspec -D_DLL -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-X86-DLL
// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -fdeclspec -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-STATIC

float test_func(float x, float y) {
  return __builtin_hypotf(x, y);
}

// CHECK-X64-DLL: declare dllimport float @hypotf(float noundef, float noundef)
// CHECK-X86-DLL: declare dllimport float @_hypotf(float noundef, float noundef)
// CHECK-STATIC: declare dso_local float @hypotf(float noundef, float noundef)

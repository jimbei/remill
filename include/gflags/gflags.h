#pragma once

#include <string>
#include <stdint.h>
#include <llvm/Support/CommandLine.h>

#define DECLARE_string(name)            extern llvm::cl::opt<std::string> FLAGS_##name
#define DEFINE_string(name, val, help)  __declspec(selectany) llvm::cl::opt<std::string> FLAGS_##name(#name, llvm::cl::desc(help), llvm::cl::init(val))
#define DEFINE_bool(name, val, help)    __declspec(selectany) llvm::cl::opt<bool> FLAGS_##name(#name, llvm::cl::desc(help), llvm::cl::init(val))
#define DEFINE_uint64(name, val, help)  __declspec(selectany) llvm::cl::opt<uint64_t> FLAGS_##name(#name, llvm::cl::desc(help), llvm::cl::init(val))

namespace google
{
  static inline void SetVersionString(std::string s) {};
  static inline void ParseCommandLineFlags(int* argc, char*** argv, bool)
  {
    llvm::cl::ParseCommandLineOptions(*argc, *argv, "remill\n");
  };
}

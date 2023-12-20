#ifndef FEATURE_DETECT_H
#define FEATURE_DETECT_H

namespace fp_util {

__attribute__((feature_variable("__VARA__DETECT__"))) void detect() {
  long foo = 0;
  asm volatile("" : "+g"(foo) : :);
  foo++;
}
} // namespace fp_util

#endif // FEATURE_DETECT_H

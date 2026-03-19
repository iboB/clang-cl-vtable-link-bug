# clang-cl vtable link bug

A demo of a clang-cl bug where it fails to link (or possibly emit?) the vtable for a type which is virtually inherited from X, non-virtually from Y, and also inherits the constructor of Y.

Issue tracked here: https://github.com/llvm/llvm-project/issues/187485

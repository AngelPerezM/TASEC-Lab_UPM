For the compilation of all modules (main and others) run:
  make # or 
  make all

For the compilation of non-primary modules run:
  make lib

For the compilation and execution of the tests run:
  make test

For the execution of an specific target for the above options add TARGET=target.
E.g.:
  1) If you want to clean all modules run:
    make all TARGET=clean # or
    make TARGET= clean

  2) If you want to clean non-primary modules run:
    make lib TARGET=clean

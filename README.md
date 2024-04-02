# Homework #6

### due: Fri April 12, 2024

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

> Note: using ChatGPT or similar AI tools to write your code is not allowed.

1. In this repo you'll find the contiguous array class, `array.H`,
   that we worked on in class (with a few enhancements based on what
   we have learned recently).

   There is also a test driver, `test_array.cpp` that has some assertions.

   Your job is to add automated testing to the github repo
   that was created when you accepted this assignment.

   The easiest way to start is to copy the `.yml` file we discussed in class:
   https://zingale.github.io/phy504/github-ci.html

   We will go one step beyond that and also add a test on the output.

   You should:

   * setup the automated testing by editing the `.yml` file as needed and
     putting it in the `.github/workflows/` directory.

     Verify that it works by pushing some changes to trigger the testing.

   * Store the output from the test driver in a file in the repo, for example
     by doing:

     ```
     ./test_array > test_array.out
     ```

     We'll call this the *stored benchmark*.  It represents what we
     think the right answer is for this test, and represents a form of
     regression testing.

   * Modify the `.yml` file to have another section after that runs
     the `test_array` program, stores its output in a file like `out`
     and then runs the Unix `diff` command to compare `out` and
     `test_array.out` to make sure that the code gives the same output
     as the stored benchmark.

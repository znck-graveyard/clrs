# Contribution Guidelines

- Source files are arranged in folders as per chapter number.
- Filename should start with page number.
- Filename should be same for all languages eg. `/2/18-insertion-sort.cpp` in c++ and same source in python should be in `/2/18-insertion-sort.py`
- File should have header containing section name, page number and topic name.

  ```c++
  /*
   * Insertion Sort, Page 18 (CLRS section 2.1)
   * @author Rahul Kadyan
   */
   ```
- Add test cases in `tests` directory. eg. for `/2/18-insertion-sort.cpp`, `/2/18-insertion-sort.py` or `/2/18-insertion-sort.*` have their test cases in `/tests/2/18-insertion-sort/` directory.
- Test case format: Input in `input.txt` and results in `output.txt`

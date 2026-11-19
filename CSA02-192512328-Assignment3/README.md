# CSA02 – C Programming Assignment 3

- **Student Name:** Sri Varshini K
- **Register Number:** 192512328
- **Course:** C Programming (CSA02)
- **Course Outcome:** CO3
- **Compiler:** GCC (tested with the GCC available in the build environment)
- **Language:** C (C11)
- **Assignment:** Assignment 3 – Searching, Sorting, Merging, Arrays and Strings
- **Role prepared:** Student A + shared group work only

## Scope and role boundary

This project follows the supplied Assignment 3 PDF. It contains shared program work and Student A's individual responsibilities. It deliberately does **not** include Student B-only investigations or Student B's Q7 Stage 3 implementation and measurement. Q7 therefore contains Student A's design deliverable only. The faculty PDF states that each student must execute every task individually and that the submission must contain C source for all questions; consequently, this Student-A-only package is not a complete pair submission until the partner's separately assigned work is combined.

## Folder structure

- `Q1/` – Library catalogue search; linear and binary search source, execution output and Student A analysis.
- `Q2/` – Examination seating register; bubble, selection and insertion sort; Student A tracing and algorithm analysis.
- `Q3/` – Merge of two descending merit lists; Student A comparison and memory analysis.
- `Q4/` – 2-D rainfall sample computations; Student A row-major memory analysis.
- `Q5/` – Character-array processing without `string.h`; Student A string design analysis.
- `Q6/` – Sorting/searching resident names; Student A measurement and index-sort improvement analysis.
- `Q7/` – Student A design pseudocode only; no Student B implementation.
- `Report/` – Assignment report PDF and editable text source.

Each Q1–Q6 folder includes a `.c` source, captured `output.txt`, and `output.png`. The PNG files are visual captures generated from the actual GCC program output.

## Compile and run

Open a terminal in the relevant question folder and compile:

```bash
gcc -std=c11 -Wall -Wextra -pedantic Q1.c -o Q1
```

Run on Linux/macOS:

```bash
./Q1
```

On Windows:

```bat
gcc -std=c11 -Wall -Wextra -pedantic Q1.c -o Q1.exe
Q1.exe
```

Replace `Q1.c` and the executable name with the corresponding question file (`Q2.c`, etc.). The same compile flags are used for Q1–Q6.

## Program summary

| Question | Program | Included shared implementation |
|---|---|---|
| Q1 | Library catalogue search | Linear search on unsorted data and binary search on sorted data; comparison counts |
| Q2 | Examination seating register | Bubble sort with early exit, selection sort, insertion sort; comparisons and moves |
| Q3 | Merit-list merge | Merge two descending sorted arrays; handles unequal lengths and empty input |
| Q4 | District rainfall sample | Annual totals, monthly averages, wettest cell and deficient-district check on a 3×4 verification sample |
| Q5 | SMS feedback analyser | Space-delimited word count, case conversion, reversal and palindrome check |
| Q6 | Hostel resident directory | Name sorting, binary search, duplicate detection, comparison and character-copy counts |
| Q7 | Election vote-counting design | Student A design/pseudocode only; implementation belongs to Student B in the PDF |

## Testing notes

- Q1 tests first, middle, last and missing keys. Binary search input is sorted; linear search input is deliberately unsorted.
- Q2 tests sorted, nearly sorted, reverse-sorted and random six-element arrays.
- Q3 tests the supplied two-list example and one empty list.
- Q4 uses a 3×4 small array suitable for hand verification. The PDF's full scenario is 38 districts × 12 months; extend the input dimensions/data for the complete dataset.
- Q5 tests leading/trailing and repeated spaces, palindrome and non-palindrome strings, and a tab-separated string. Under the exact PDF wording (“spaces”), the word counter treats only the ordinary space character as a separator; a tab is not a separator.
- Q6 uses an eight-name demonstration dataset with a duplicate. The PDF's scale tests (100, 500 and 5,000 names) are Student A's measurement responsibility and should be run with generated datasets for final evidence.

## Student A responsibilities included

- Q1: search pseudocode, comparison analysis, 100,000-record prediction, sorted-data rationale and midpoint overflow rationale.
- Q2: manual traces, early-exit flag, nearly sorted insertion sort, stability and recommendation.
- Q3: merge comparison bound, merge-versus-sort estimates, extra memory and edge cases.
- Q4: row-major layout, address formula, loop locality and 3-D extension.
- Q5: null terminator, word-count pseudocode, repeated `strlen` cost and array-vs-pointer distinction.
- Q6: measurement approach, index-sorting alternative, string length boundary and binary-search comparisons.
- Q7: Stage 2 design, pseudocode, tie detection and complexity.

## GitHub requirement

Create the repository named `CSA02-192512328-Assignment3`. Commit work progressively (at least one commit per task), then add the faculty as a collaborator or make the repository public. Add the repository URL to the cover page and submission form. A ZIP upload does not create Git history; commits must be made in GitHub separately.

## Important submission limitation

The supplied faculty PDF is pair-work. This ZIP intentionally excludes Student B-only work as requested. It is therefore not the complete joint submission. In particular, Student B's Q1/Q2/Q4/Q5/Q6 investigations and Q7 Stage 3 implementation/measurements are not represented as completed work. Do not claim those items as completed.

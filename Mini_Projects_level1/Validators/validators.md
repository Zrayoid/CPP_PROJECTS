# C++ Validators

A collection of three beginner-level C++ validation programs built using string manipulation, conditional statements, loops, and basic validation logic.

## Validators

### 1. Email Validator
- Checks for exactly one `@` symbol.
- Checks that the local part and domain are not empty.
- Checks for valid dot placement.
- Rejects consecutive dots.
- Requires at least two characters after the final dot.

### 2. URL Validator
- Accepts URLs beginning with `http://` or `https://`.
- Checks whether the domain is empty.
- Rejects domains starting or ending with a dot.
- Checks for consecutive dots.
- Requires at least two characters in the domain extension.

### 3. Date Validator
- Supports `YYYY-MM-DD` and `YYYY/MM/DD` formats.
- Checks date length and separator consistency.
- Validates numeric characters.
- Checks month and day ranges.
- Accounts for leap years.
- Validates the year range (1–9999).

## Technologies & Concepts
- C++
- String manipulation (`find()`, `rfind()`, `substr()`)
- Loops and conditional statements
- `<cctype>` character validation functions
- Basic logical validation
- Leap-year calculation

## Important Note

These programs are beginner-level learning exercises designed to practise C++ programming and understand basic validation logic.

**They are not production-ready validators and should not be used in real-world

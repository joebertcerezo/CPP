#!/bin/zsh
# format.sh: Formats C++ files using the project's .clang-format file

# Exit immediately if a command exits with a non-zero status.
set -e

echo "Starting C++ formatting with clang-format..."

# Use find to locate files and execute clang-format on them.
# - The -style=file option tells clang-format to look for the nearest .clang-format file.
# - The -i option means "in-place" editing.
# - The -print0 and -0 options handle filenames with spaces or special characters correctly.
find . -path ./build -prune -o \
  \( -iname "*.cpp" -o -iname "*.hpp" -o -iname "*.c" -o -iname "*.h" -o -iname "*.cc" -o -iname "*.cxx" \) \
  -print0 | xargs -0 clang-format -style=file -i

echo "Formatting complete."
